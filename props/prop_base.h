#ifndef PROPS_PROP_BASE_H
#define PROPS_PROP_BASE_H

// Base class for props.
class PropBase : CommandParser, Looper, protected SaberBase {
public:
  PropBase() : CommandParser() {}
  BladeStyle* current_style(){
    return current_config->blade1->current_style();
  }

  bool NeedsPower() {
    if (SaberBase::IsOn()) return true;
    if (current_style() && current_style()->NoOnOff())
      return true;
    return false;
  }

  int32_t muted_volume_ = 0;
  bool SetMute(bool muted) {
#ifdef ENABLE_AUDIO
    if (muted) {
      if (dynamic_mixer.get_volume()) {
	muted_volume_ = dynamic_mixer.get_volume();
	dynamic_mixer.set_volume(0);
	return true;
      }
    } else {
      if (muted_volume_) {
	dynamic_mixer.set_volume(muted_volume_);
	muted_volume_ = 0;
	return true;
      }
    }
#endif
    return false;
  }


  bool unmute_on_deactivation_ = false;
  uint32_t activated_ = 0;
  uint32_t last_clash_ = 0;
  uint32_t clash_timeout_ = 100;
  bool clash_pending_ = false;
  bool savepending_ = false;
  virtual void On() {
    if (SaberBase::IsOn()) return;
    if (current_style() && current_style()->NoOnOff())
      return;
    activated_ = millis();
    STDOUT.println("Ignition.");
    MountSDCard();
    EnableAmplifier();
    SaberBase::TurnOn();
    // Avoid clashes a little bit while turning on.
    // It might be a "clicky" power button...
    IgnoreClash(300);
  }


  virtual void Off(OffType off_type = OFF_NORMAL) {
    if (!SaberBase::IsOn()) return;
    if (SaberBase::Lockup()) {
      SaberBase::DoEndLockup();
      SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
    }

    SaberBase::TurnOff(off_type);

    if (unmute_on_deactivation_) {
      unmute_on_deactivation_ = false;
#ifdef ENABLE_AUDIO
      // We may also need to stop any thing else that generates noise..
      for (size_t i = 0; i < NELEM(wav_players); i++) {
        wav_players[i].Stop();
      }
#endif
      SetMute(false);
    }
  }


  void IgnoreClash(size_t ms) {
    if (clash_pending_) return;
    uint32_t now = millis();
    uint32_t time_since_last_clash = now - last_clash_;
    if (time_since_last_clash < clash_timeout_) {
      ms = std::max<size_t>(ms, clash_timeout_ - time_since_last_clash);
    }
    last_clash_ = now;
    clash_timeout_ = ms;
  }

  void Clash2() {
    if (Event(BUTTON_NONE, EVENT_CLASH)) {
      IgnoreClash(400);
    } else {
      IgnoreClash(100);
      if (SaberBase::IsOn()) SaberBase::DoClash();
    }
  }

  virtual void Clash() {
    // No clashes in lockup mode.
    if (SaberBase::Lockup()) return;
    // TODO: Pick clash randomly and/or based on strength of clash.
    uint32_t t = millis();
    if (t - last_clash_ < clash_timeout_) {
      last_clash_ = t; // Vibration cancellation
      return;
    }
    if (current_modifiers & ~MODE_ON) {
      // Some button is pressed, that means that we need to delay the clash a little
      // to see if was caused by a button *release*.
      last_clash_ = millis();
      clash_timeout_ = 3;
      clash_pending_ = true;
      return;
    }
    Clash2();
  }

  bool chdir(const char* dir) {
    if (strlen(dir) > 1 && dir[strlen(dir)-1] == '/') {
      STDOUT.println("Directory must not end with slash.");
      return false;
    }
#ifdef ENABLE_AUDIO
    smooth_swing_v2.Deactivate();
    looped_swing_wrapper.Deactivate();
    hybrid_font.Deactivate();

    // Stop all sound!
    // TODO: Move scanning to wav-playing interrupt level so we can
    // interleave things without worry about memory corruption.
    for (size_t i = 0; i < NELEM(wav_players); i++) {
      wav_players[i].Stop();
    }
#endif

    strcpy(current_directory, dir);
    if (strlen(current_directory) &&
        current_directory[strlen(current_directory)-1] != '/') {
      strcat(current_directory, "/");
    }

#ifdef ENABLE_AUDIO
    Effect::ScanDirectory(dir);
    SaberBase* font = NULL;
    hybrid_font.Activate();
    font = &hybrid_font;
    if (font) {
	  if (lswing.files_found()) {
      smooth_swing_config.ReadInCurrentDir("smoothsw.ini");
		  smooth_swing_v2.Activate(font);
	  } else if (swingl.files_found()) {
        smooth_swing_config.ReadInCurrentDir("smoothsw.ini");
        switch (smooth_swing_config.Version) {
          case 1:
            looped_swing_wrapper.Activate(font);
            break;
          case 2:
            smooth_swing_v2.Activate(font);
            break;
        }
      }
    }
//    EnableBooster();
#endif
    return false;
  }

  // Select preset (font/style)
  void SetPreset(int preset_num, bool announce) {
    #ifdef SAVED_PRESET
    if (savepending_) {
      LOCK_SD(true);
      STDOUT.println("Saving Preset Settings");
      if (current_preset_.font.get() != NULL) {
        current_preset_.SaveAt(current_preset_.preset_num);
      }
      LOCK_SD(false);
      savepending_ = false;
    }
    #endif
    bool on = SaberBase::IsOn();
    if (on) Off();
    // First free all styles, then allocate new ones to avoid memory
    // fragmentation.
#define UNSET_BLADE_STYLE(N) \
    delete current_config->blade##N->UnSetStyle();
    ONCEPERBLADE(UNSET_BLADE_STYLE)
    current_preset_.SetPreset(preset_num);
    if (announce) {
      if (current_preset_.name.get()) {
        SaberBase::DoMessage(current_preset_.name.get());
      } else {

        char message[64];
        strcpy(message, "Preset: ");
        itoa(current_preset_.preset_num + 1,
             message + strlen(message), 10);
        strcat(message, "\n");
        strncat(message + strlen(message),
                current_preset_.font.get(), sizeof(message) - strlen(message));
        message[sizeof(message) - 1] = 0;
        SaberBase::DoMessage(message);
      }
    }

#define SET_BLADE_STYLE(N) \
    current_config->blade##N->SetStyle(style_parser.Parse(current_preset_.current_style##N.get()));
    ONCEPERBLADE(SET_BLADE_STYLE)
    chdir(current_preset_.font.get());
    if (on) On();
    if (announce)
    {
      SaberBase::DoNewFont();
    }
  }

  // Go to the next Preset.
  virtual void next_preset() {
#ifdef ENABLE_AUDIO
    beeper.Beep(0.05, 2000.0);
#endif
    SetPreset(current_preset_.preset_num + 1, true);
  }

  // Go to the previous Preset.
  virtual void previous_preset() {
#ifdef ENABLE_AUDIO
    beeper.Beep(0.05, 2000.0);
#endif
    SetPreset(current_preset_.preset_num - 1, true);
  }

  // Rotates presets backwards and saves.
  virtual void rotate_presets() {
#ifdef ENABLE_AUDIO
    beeper.Beep(0.05, 2000.0);
#endif
    LOCK_SD(true);
    current_preset_.Load(-1);  // load last preset
    current_preset_.SaveAt(0); // save in first position, shifting all other presets down
    LOCK_SD(false);
    SetPreset(0, true);
  }

  // Measure and return the blade identifier resistor.
  float id() {
#ifdef ENABLE_POWER_FOR_ID
    ENABLE_POWER_FOR_ID power_pins_to_toggle;
    STDOUT.println("Power for ID enabled. Turning on FETs");
    power_pins_to_toggle.Init();
    power_pins_to_toggle.Power(true);
#endif
    pinMode(bladeIdentifyPin, INPUT_PULLUP);
    delay(100);
    int blade_id = LSAnalogRead(bladeIdentifyPin, INPUT_PULLUP);
#ifdef ENABLE_POWER_FOR_ID
    power_pins_to_toggle.Power(false);
#endif
    float volts = blade_id * 3.3f / 1024.0f;  // Volts at bladeIdentifyPin
    float amps = (3.3f - volts) / 33000;     // Pull-up is 33k
    float resistor = volts / amps;
    STDOUT.print("ID: ");
    STDOUT.print(blade_id);
    STDOUT.print(" volts ");
    STDOUT.print(volts);
    STDOUT.print(" resistance= ");
    STDOUT.println(resistor);
    return resistor;
  }

  // Called from setup to identify the blade and select the right
  // Blade driver, style and sound font.
  void FindBlade() {
    size_t best_config = 0;
    if (NELEM(blades) > 1) {
      float resistor = id();

      float best_err = 1000000.0;
      for (size_t i = 0; i < NELEM(blades); i++) {
        float err = fabsf(resistor - blades[i].ohm);
        if (err < best_err) {
          best_config = i;
          best_err = err;
        }
      }
    }
    STDOUT.print("blade= ");
    STDOUT.println(best_config);
    current_config = blades + best_config;

#define ACTIVATE(N) do {     \
    if (!current_config->blade##N) goto bad_blade;  \
    current_config->blade##N->Activate();           \
  } while(0);

    ONCEPERBLADE(ACTIVATE);
    //SetPreset(0, false);
    #ifdef SAVED_PRESET
    ResumePreset();
    #else
    SetPreset(0, false);
    #endif
    return;

   bad_blade:
    STDOUT.println("BAD BLADE");
#ifdef ENABLE_AUDIO
    talkie.Say(talkie_error_in_15, 15);
    talkie.Say(talkie_blade_array_15, 15);
#endif
  }

  void ResumePreset() {

    FileReader f;
    int newPreset;
    int newVolume;
    if (f.Open("savedpreset.ini") && f.FileSize() > 0) {
      for (; f.Available(); f.skipline()) {
        char variable[33];
        f.readVariable(variable);
        if (!variable[0]) continue;
        if (f.Peek() != '=') continue;
        f.Read();
        f.skipwhite();
        if (!strcmp(variable, "preset")) {
          newPreset = f.readIntValue();
        continue;
        }
        if (!strcmp(variable, "volume")) {
          newVolume = f.readIntValue();
        }
      }
      f.Close();
      SetPreset(newPreset, false);
      if (newVolume < VOLUME) {
        dynamic_mixer.set_volume(newVolume);
      }
    } else {
      SetPreset(0, false);
    }
  }

  void SB_Message(const char* text) override {
    STDOUT.print("DISPLAY: ");
    STDOUT.println(text);
  }

  float peak = 0.0;
  Vec3 at_peak;
  virtual void DoAccel(const Vec3& accel, bool clear) {
    SaberBase::DoAccel(accel, clear);
    accel_loop_counter_.Update();
    if (clear) accel_ = accel;
    float v = (accel_ - accel).len();
    // If we're spinning the saber, require a stronger acceleration
    // to activate the clash.
    if (v > CLASH_THRESHOLD_G + filtered_gyro_.len() / 200.0) {
      // Needs de-bouncing
#if 1
      STDOUT.print("ACCEL: ");
      STDOUT.print(accel.x);
      STDOUT.print(", ");
      STDOUT.print(accel.y);
      STDOUT.print(", ");
      STDOUT.print(accel.z);
      STDOUT.print(" v = ");
      STDOUT.print(v);
      STDOUT.print(" fgl = ");
      STDOUT.print(filtered_gyro_.len() / 200.0);
      STDOUT.print(" accel_: ");
      STDOUT.print(accel_.x);
      STDOUT.print(", ");
      STDOUT.print(accel_.y);
      STDOUT.print(", ");
      STDOUT.print(accel_.z);
      STDOUT.print(" clear = ");
      STDOUT.print(clear);
      STDOUT.print(" millis = ");
      STDOUT.println(millis());
#endif
      Clash();
    }
    if (v > peak) {
      peak = v;
      at_peak = accel_ - accel;
    }
    accel_ = accel;
    if (monitor.ShouldPrint(Monitoring::MonitorClash)) {
      STDOUT.print("ACCEL: ");
      STDOUT.print(accel.x);
      STDOUT.print(", ");
      STDOUT.print(accel.y);
      STDOUT.print(", ");
      STDOUT.print(accel.z);
      STDOUT.print(" peak ");
      STDOUT.print(at_peak.x);
      STDOUT.print(", ");
      STDOUT.print(at_peak.y);
      STDOUT.print(", ");
      STDOUT.print(at_peak.z);
      STDOUT.print(" (");
      STDOUT.print(peak);
      STDOUT.println(")");
      peak = 0.0;
    }
  }

  virtual void DoMotion(const Vec3& motion, bool clear) {
    SaberBase::DoMotion(motion, clear);
  }

  void SB_Top() override {
    STDOUT.print("Acceleration measurements per second: ");
    accel_loop_counter_.Print();
    STDOUT.println("");
  }

  enum StrokeType {
    NO_STROKE,
    TWIST_LEFT,
    TWIST_RIGHT,
  };
  struct Stroke {
    StrokeType type;
    uint32_t start_millis;
    uint32_t end_millis;
    uint32_t length() const { return end_millis - start_millis; }
  };

  Stroke strokes[5];

  void ProcessStrokes() {
    if (monitor.IsMonitoring(Monitoring::MonitorStrokes)) {
      STDOUT.print("Stroke: ");
      switch (strokes[NELEM(strokes)-1].type) {
        case TWIST_LEFT:
          STDOUT.print("TwistLeft");
          break;
        case TWIST_RIGHT:
          STDOUT.print("TwistRight");
          break;
        default: break;
      }
      STDOUT.print(" len=");
      STDOUT.print(strokes[NELEM(strokes)-1].length());
      STDOUT.print(" separation=");
      uint32_t separation =
        strokes[NELEM(strokes)-1].start_millis -
        strokes[NELEM(strokes)-2].end_millis;
      STDOUT.println(separation);
    }
    if ((strokes[NELEM(strokes)-1].type == TWIST_LEFT &&
         strokes[NELEM(strokes)-2].type == TWIST_RIGHT) ||
        (strokes[NELEM(strokes)-1].type == TWIST_RIGHT &&
         strokes[NELEM(strokes)-2].type == TWIST_LEFT)) {
      if (strokes[NELEM(strokes) -1].length() > 90UL &&
          strokes[NELEM(strokes) -1].length() < 300UL &&
          strokes[NELEM(strokes) -2].length() > 90UL &&
          strokes[NELEM(strokes) -2].length() < 300UL) {
        uint32_t separation =
          strokes[NELEM(strokes)-1].start_millis -
          strokes[NELEM(strokes)-2].end_millis;
        if (separation < 200UL) {
          STDOUT.println("TWIST");
          // We have a twisting gesture.
          Event(BUTTON_NONE, EVENT_TWIST);
        }
      }
    }
  }

  void DoGesture(StrokeType gesture) {
    if (gesture == NO_STROKE) {
      if (strokes[NELEM(strokes) - 1].end_millis == 0) {
        strokes[NELEM(strokes) - 1].end_millis = millis();
        ProcessStrokes();
      }
      return;
    }
    if (gesture == strokes[NELEM(strokes)-1].type &&
        strokes[NELEM(strokes)-1].end_millis == 0) {
      // Stroke not done, wait.
      return;
    }
    for (size_t i = 0; i < NELEM(strokes) - 1; i++) {
      strokes[i] = strokes[i+1];
    }
    strokes[NELEM(strokes)-1].type = gesture;
    strokes[NELEM(strokes)-1].start_millis = millis();
    strokes[NELEM(strokes)-1].end_millis = 0;
  }

  BoxFilter<Vec3, 5> gyro_filter_;
  Vec3 filtered_gyro_;
  bool swinging = false;
  void SB_Motion(const Vec3& gyro, bool clear) override {
    if (clear)
      for (int i = 0; i < 4; i++)
        gyro_filter_.filter(gyro);

    filtered_gyro_ = gyro_filter_.filter(gyro);
    if (monitor.ShouldPrint(Monitoring::MonitorGyro)) {
      // Got gyro data
      STDOUT.print("GYRO: ");
      STDOUT.print(gyro.x);
      STDOUT.print(", ");
      STDOUT.print(gyro.y);
      STDOUT.print(", ");
      STDOUT.println(gyro.z);
    }
    if (abs(gyro.x) > 200.0 &&
        abs(gyro.x) > 3.0f * abs(gyro.y) &&
        abs(gyro.x) > 3.0f * abs(gyro.z)) {
      DoGesture(gyro.x > 0 ? TWIST_LEFT : TWIST_RIGHT);
    } else {
      DoGesture(NO_STROKE);
    }
	if (sqrtf(gyro.z * gyro.z + gyro.y * gyro.y) > 250 && !swinging) {
		STDOUT.println("SWING");
          // We have a twisting gesture.
         Event(BUTTON_NONE, EVENT_SWING);
		 swinging = true;
	} else if (sqrtf(gyro.z * gyro.z + gyro.y * gyro.y) < 150) {
		swinging = false;
	}
  }

  Vec3 accel_;

  void StartOrStopTrack() {
#ifdef ENABLE_AUDIO
    if (track_player_) {
      track_player_->Stop();
      track_player_.Free();
    } else {
      MountSDCard();
      EnableAmplifier();
      track_player_ = GetFreeWavPlayer();
      if (track_player_) {
        track_player_->Play(current_preset_.track.get());
      } else {
        STDOUT.println("No available WAV players.");
      }
    }
#else
    STDOUT.println("Audio disabled.");
#endif
  }

  uint32_t last_beep_;
  void Loop() override {
    if (clash_pending_ && millis() - last_clash_ >= clash_timeout_) {
      clash_pending_ = false;
      Clash2();
    }
    if (battery_monitor.low()) {
      // TODO: FIXME
      if (current_style()->Charging()) {
        if (SaberBase::IsOn()) {
          STDOUT.print("Battery low, turning off. Battery voltage: ");
          STDOUT.println(battery_monitor.battery());
          Off();
        } else if (millis() - last_beep_ > 5000) {
          STDOUT.println("Battery low beep");
#ifdef ENABLE_AUDIO
          // TODO: allow this to be replaced with WAV file
          talkie.Say(talkie_low_battery_15, 15);
#endif
          last_beep_ = millis();
        }
      }
    }
#ifdef ENABLE_AUDIO
    if (track_player_ && !track_player_->isPlaying()) {
      track_player_.Free();
    }
#endif
  }

  void PrintButton(uint32_t b) {
    if (b & BUTTON_POWER) STDOUT.print("Power");
    if (b & BUTTON_AUX) STDOUT.print("Aux");
    if (b & BUTTON_AUX2) STDOUT.print("Aux2");
    if (b & BUTTON_UP) STDOUT.print("Up");
    if (b & BUTTON_DOWN) STDOUT.print("Down");
    if (b & BUTTON_LEFT) STDOUT.print("Left");
    if (b & BUTTON_RIGHT) STDOUT.print("Right");
    if (b & BUTTON_SELECT) STDOUT.print("Select");
    if (b & MODE_ON) STDOUT.print("On");
  }

  void PrintEvent(EVENT e) {
    switch (e) {
      case EVENT_NONE: STDOUT.print("None"); break;
      case EVENT_PRESSED: STDOUT.print("Pressed"); break;
      case EVENT_RELEASED: STDOUT.print("Released"); break;
      case EVENT_CLICK_SHORT: STDOUT.print("Shortclick"); break;
      case EVENT_CLICK_LONG: STDOUT.print("Longclick"); break;
      case EVENT_DOUBLE_CLICK: STDOUT.print("Doubleclick"); break;
      case EVENT_LATCH_ON: STDOUT.print("On"); break;
      case EVENT_LATCH_OFF: STDOUT.print("Off"); break;
      case EVENT_STAB: STDOUT.print("Stab"); break;
      case EVENT_SWING: STDOUT.print("Swing"); break;
      case EVENT_SHAKE: STDOUT.print("Shake"); break;
      case EVENT_TWIST: STDOUT.print("Twist"); break;
      case EVENT_CLASH: STDOUT.print("Clash"); break;
      case EVENT_HELD: STDOUT.print("Held"); break;
      case EVENT_HELD_LONG: STDOUT.print("HeldLong"); break;
    }
  }

  void PrintEvent(enum BUTTON button, EVENT event) {
    STDOUT.print("EVENT: ");
    if (button) {
      PrintButton(button);
      STDOUT.print("-");
    }
    PrintEvent(event);
    if (current_modifiers & ~button) {
      STDOUT.print(" mods ");
      PrintButton(current_modifiers);
    }
    if (SaberBase::IsOn()) STDOUT.print(" ON");
    STDOUT.print(" millis=");
    STDOUT.println(millis());
  }

  bool Parse(const char *cmd, const char* arg) override {
    if (!strcmp(cmd, "id")) {
      id();
      return true;
    }
    if (!strcmp(cmd, "on")) {
      On();
      return true;
    }
    if (!strcmp(cmd, "off")) {
      Off();
      return true;
    }
    if (!strcmp(cmd, "get_on")) {
      STDOUT.println(SaberBase::IsOn());
      return true;
    }
    if (!strcmp(cmd, "clash")) {
      Clash();
      return true;
    }
    if (!strcmp(cmd, "force")) {
      SaberBase::DoForce();
      return true;
    }
    if (!strcmp(cmd, "change")) {
      SaberBase::DoChange();
	  SaberBase::DoMSelect();
      return true;
    }
    if (!strcmp(cmd, "scroll")) {
      SaberBase::DoScroll();
	  SaberBase::DoMEnter();
      return true;
    }
    if (!strcmp(cmd, "select")) {
      SaberBase::DoSelect();
	  SaberBase::DoMSelect();
      return true;
    }
    if (!strcmp(cmd, "blast")) {
      // Avoid the base and the very tip.
      // TODO: Make blast only appear on one blade!
      SaberBase::DoBlast();
      return true;
    }
    if (!strcmp(cmd, "lock") || !strcmp(cmd, "lockup")) {
      STDOUT.print("Lockup ");
      if (SaberBase::Lockup() == SaberBase::LOCKUP_NONE) {
        SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
        SaberBase::DoBeginLockup();
        STDOUT.println("ON");
      } else {
        SaberBase::DoEndLockup();
        SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        STDOUT.println("OFF");
      }
      return true;
    }
    if (!strcmp(cmd, "drag")) {
      STDOUT.print("Drag ");
      if (SaberBase::Lockup() == SaberBase::LOCKUP_NONE) {
        SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
        SaberBase::DoBeginLockup();
        STDOUT.println("ON");
      } else {
        SaberBase::DoEndLockup();
        SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        STDOUT.println("OFF");
      }
      return true;
    }
#ifdef ENABLE_AUDIO
    if (!strcmp(cmd, "beep")) {
      beeper.Beep(1.0, 3000.0);
      return true;
    }
    if (!strcmp(cmd, "play")) {
      if (!arg) {
        StartOrStopTrack();
        return true;
      }
      MountSDCard();
      EnableAmplifier();
      RefPtr<BufferedWavPlayer> player = GetFreeWavPlayer();
      if (player) {
        STDOUT.print("Playing ");
        STDOUT.println(arg);
        player->Play(arg);
      } else {
        STDOUT.println("No available WAV players.");
      }
      return true;
    }
    if (!strcmp(cmd, "play_track")) {
      if (!arg) {
        StartOrStopTrack();
        return true;
      }
      if (track_player_) {
        track_player_->Stop();
        track_player_.Free();
      }
      MountSDCard();
      EnableAmplifier();
      track_player_ = GetFreeWavPlayer();
      if (track_player_) {
        STDOUT.print("Playing ");
        STDOUT.println(arg);
        track_player_->Play(arg);
      } else {
        STDOUT.println("No available WAV players.");
      }
      return true;
    }
    if (!strcmp(cmd, "stop_track")) {
      if (track_player_) {
        track_player_->Stop();
        track_player_.Free();
      }
      return true;
    }
    if (!strcmp(cmd, "get_track")) {
      if (track_player_) {
        STDOUT.println(track_player_->Filename());
      }
      return true;
    }
    if (!strcmp(cmd, "volumes")) {
      for (size_t unit = 0; unit < NELEM(wav_players); unit++) {
        STDOUT.print(" Unit ");
        STDOUT.print(unit);
        STDOUT.print(" Volume ");
        STDOUT.println(wav_players[unit].volume());
      }
      return true;
    }
    if (!strcmp(cmd, "buffered")) {
      for (size_t unit = 0; unit < NELEM(wav_players); unit++) {
        STDOUT.print(" Unit ");
        STDOUT.print(unit);
        STDOUT.print(" Buffered: ");
        STDOUT.println(wav_players[unit].buffered());
      }
      return true;
    }
#endif
    if (!strcmp(cmd, "cd")) {
      chdir(arg);
      SaberBase::DoNewFont();
      return true;
    }
#if 0
    if (!strcmp(cmd, "mkdir")) {
      SD.mkdir(arg);
      return true;
    }
#endif
    if (!strcmp(cmd, "pwd")) {
      STDOUT.println(current_directory);
      return true;
    }
    if (!strcmp(cmd, "n") || (!strcmp(cmd, "next") && arg && (!strcmp(arg, "preset") || !strcmp(arg, "pre")))) {
      next_preset();
      return true;
    }
    if (!strcmp(cmd, "p") || (!strcmp(cmd, "prev") && arg && (!strcmp(arg, "preset") || !strcmp(arg, "pre")))) {
      previous_preset();
      return true;
    }
    if (!strcmp(cmd, "rotate")) {
      rotate_presets();
      return true;
    }
    if (!strcmp(cmd, "message") && arg) {
      SaberBase::DoMessage(arg);
      return true;
    }

    if (!strcmp(cmd, "list_presets")) {
      CurrentPreset tmp;
      for (int i = 0; ; i++) {
        tmp.SetPreset(i);
	if (tmp.preset_num != i) break;
	tmp.Print();
      }
      return true;
    }

    if (!strcmp(cmd, "set_font") && arg) {
      current_preset_.font = mkstr(arg);
      current_preset_.Save();
      return true;
    }

    if (!strcmp(cmd, "set_track") && arg) {
      current_preset_.track = mkstr(arg);
      current_preset_.Save();
      return true;
    }

    if (!strcmp(cmd, "set_name") && arg) {
      current_preset_.name = mkstr(arg);
      current_preset_.Save();
      return true;
    }

#define SET_STYLE_CMD(N)                             \
    if (!strcmp(cmd, "set_style" #N) && arg) {        \
      current_preset_.current_style##N = mkstr(arg); \
      current_preset_.Save();                        \
      return true;                                   \
    }
    ONCEPERBLADE(SET_STYLE_CMD)

    if (!strcmp(cmd, "move_preset") && arg) {
      int32_t pos = strtol(arg, NULL, 0);
      current_preset_.SaveAt(pos);
      return true;
    }

    if (!strcmp(cmd, "duplicate_preset") && arg) {
      int32_t pos = strtol(arg, NULL, 0);
      current_preset_.preset_num = -1;
      current_preset_.SaveAt(pos);
      return true;
    }

    if (!strcmp(cmd, "delete_preset") && arg) {
      current_preset_.SaveAt(-1);
      return true;
    }

    if (!strcmp(cmd, "show_current_preset")) {
      current_preset_.Print();
      return true;
    }

    if (!strcmp(cmd, "get_preset")) {
      STDOUT.println(current_preset_.preset_num);
      return true;
    }
    if (!strcmp(cmd, "get_volume")) {
#ifdef ENABLE_AUDIO
      STDOUT.println(dynamic_mixer.get_volume());
#else
      STDOUT.println(0);
#endif
      return true;
    }
    if (!strcmp(cmd, "set_volume") && arg) {
#ifdef ENABLE_AUDIO
      int32_t volume = strtol(arg, NULL, 0);
      if (volume >= 0 && volume <= 3000)
        dynamic_mixer.set_volume(volume);
#endif
      return true;
    }

    if (!strcmp(cmd, "mute")) {
      SetMute(true);
      return true;
    }
    if (!strcmp(cmd, "unmute")) {
      SetMute(false);
      return true;
    }
    if (!strcmp(cmd, "toggle_mute")) {
      if (!SetMute(true)) SetMute(false);
      return true;
    }

    if (!strcmp(cmd, "set_preset") && arg) {
      size_t preset = strtol(arg, NULL, 0);
      SetPreset(preset, true);
      return true;
    }

#ifdef ENABLE_SD
    if (!strcmp(cmd, "list_tracks")) {
      LOCK_SD(true);
      for (LSFS::Iterator iter("/"); iter; ++iter) {
        if (iter.isdir()) {
          char fname[128];
          strcpy(fname, iter.name());
          strcat(fname, "/");
          char* fend = fname + strlen(fname);
          bool isfont = false;
          if (!isfont) {
            strcpy(fend, "hum.wav");
            isfont = LSFS::Exists(fname);
          }
          if (!isfont) {
            strcpy(fend, "hum01.wav");
            isfont = LSFS::Exists(fname);
          }
          if (!isfont) {
            strcpy(fend, "hum");
            isfont = LSFS::Exists(fname);
          }
          if (!isfont) {
            for (LSFS::Iterator i2(iter); i2; ++i2) {
              if (endswith(".wav", i2.name()) && i2.size() > 200000) {
                strcpy(fend, i2.name());
                STDOUT.println(fname);
              }
            }
          }
        } else {
          if (endswith(".wav", iter.name()) && iter.size() > 200000) {
            STDOUT.println(iter.name());
          }
        }
      }
      LOCK_SD(false);
      return true;
    }

    if (!strcmp(cmd, "list_fonts")) {
      LOCK_SD(true);
      for (LSFS::Iterator iter("/"); iter; ++iter) {
        if (iter.isdir()) {
          char fname[128];
          strcpy(fname, iter.name());
          strcat(fname, "/");
          char* fend = fname + strlen(fname);
          bool isfont = false;
          if (!isfont) {
            strcpy(fend, "hum.wav");
            isfont = LSFS::Exists(fname);
          }
          if (!isfont) {
            strcpy(fend, "hum01.wav");
            isfont = LSFS::Exists(fname);
          }
          if (!isfont) {
            strcpy(fend, "hum");
            isfont = LSFS::Exists(fname);
          }
          if (isfont) {
	    STDOUT.println(iter.name());
          }
        }
      }
      LOCK_SD(false);
      return true;
    }
#endif
    return false;
  }
  void Help() override {
    STDOUT.println(" clash - trigger a clash");
    STDOUT.println(" on/off - turn saber on/off");
    STDOUT.println(" force - trigger a force push");
    STDOUT.println(" blast - trigger a blast");
    STDOUT.println(" change - trigger a change");
    STDOUT.println(" scroll - trigger scroll/demo feature");
    STDOUT.println(" select - stop / select from scroll");
    STDOUT.println(" lock - begin/end lockup");
#ifdef ENABLE_AUDIO
    STDOUT.println(" pwd - print current directory");
    STDOUT.println(" cd directory - change directory, and sound font");
    STDOUT.println(" play filename - play file");
    STDOUT.println(" next/prev font - walk through directories in alphabetical order");
    STDOUT.println(" next/prev pre[set] - walk through presets.");
    STDOUT.println(" beep - play a beep");
#endif
  }

  virtual bool Event(enum BUTTON button, EVENT event) {
    PrintEvent(button, event);

    switch (event) {
      case EVENT_RELEASED:
	clash_pending_ = false;
      case EVENT_PRESSED:
	IgnoreClash(50); // ignore clashes to prevent buttons from causing clashes
      default:
	break;
    }

    if (Event2(button, event, current_modifiers | (SaberBase::IsOn() ? MODE_ON : MODE_OFF))) {
      current_modifiers = BUTTON_NONE;
      return true;
    }
    if (Event2(button, event,  MODE_ANY_BUTTON | (SaberBase::IsOn() ? MODE_ON : MODE_OFF))) {
      current_modifiers = BUTTON_NONE;
      return true;
    }
    return false;
  }

  virtual bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) = 0;

  void SB_SetColor(int n_) override{
    current_preset_.color_seq = n_;
  }
  void SB_SetEffect(int n_) override{
    current_preset_.effect_seq = n_;
  }
  void SB_SetColorScroll(int n_) override{
    current_preset_.color_scroll_seq = n_;
  }
  void SB_SetColorFade(int n_) override{
    current_preset_.color_fade_seq = n_;
  }
  int SB_INTGetColor() override{
    return current_preset_.color_seq;
  }
  int SB_INTGetEffect() override{
    return current_preset_.effect_seq;
  }
  int SB_INTGetColorScroll() override{
    return current_preset_.color_scroll_seq;
  }
  int SB_INTGetColorFade() override{
    return current_preset_.color_fade_seq;
  }
  void SB_ClearPresets() override {
    current_preset_.ClearPresets();
    SetPreset(0, true);
  }
  void SB_SavePresetChanges() override {
    savepending_ = true;
  }

protected:
  CurrentPreset current_preset_;
  LoopCounter accel_loop_counter_;
};

#endif
