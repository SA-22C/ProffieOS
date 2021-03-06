#ifndef PROPS_SABER_H
#define PROPS_SABER_H

#include "prop_base.h"

#define PROP_TYPE Saber

// The Saber class implements the basic states and actions
// for the saber.
class Saber : public PropBase {
public:
  Saber() : PropBase() {}
  const char* name() override { return "Saber"; }

  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
        if (accel_.x < -0.15) {
          pointing_down_ = true;
        } else {
          pointing_down_ = false;
        }
      return true;

#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
#endif
      case EVENTID(BUTTON_POWER, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
#if NUM_BUTTONS == 2
        if (MODE_VOLUME){
          STDOUT.println("Volume up");
          if (dynamic_mixer.get_volume() < max_volume_){
            current_volume_ += max_volume_ * 0.10;
            dynamic_mixer.set_volume(current_volume_);
            beeper.Beep(0.5, 2000);
            STDOUT.print("Current Volume: ");
            STDOUT.println(dynamic_mixer.get_volume());
          }
          else{
            beeper.Beep(0.5, 1000);
          }
        }
#endif
        if (!MODE_VOLUME){
          aux_on_ = false;
          On();
        }
        break;
	return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
#if NUM_BUTTONS == 2
        if (MODE_VOLUME){
          STDOUT.println("Volume Down");
          if (dynamic_mixer.get_volume() <= max_volume_ && dynamic_mixer.get_volume() > (0.10 * max_volume_)){
            current_volume_ = dynamic_mixer.get_volume();
            current_volume_ -= (max_volume_ * 0.10) ;
            dynamic_mixer.set_volume(current_volume_);
            beeper.Beep(0.5, 2000);
            STDOUT.print("Current Volume: ");
            STDOUT.println(dynamic_mixer.get_volume());
          }
          else{
            beeper.Beep(0.5, 1000);
          }
        }
#endif
#if NUM_BUTTONS == 3
        if (MODE_VOLUME){
          STDOUT.println("Volume up");
          if (dynamic_mixer.get_volume() < max_volume_){
            current_volume_ += max_volume_ * 0.10;
            dynamic_mixer.set_volume(current_volume_);
            beeper.Beep(0.5, 2000);
            STDOUT.print("Current Volume: ");
            STDOUT.println(dynamic_mixer.get_volume());
          }
          else{
            beeper.Beep(0.5, 1000);
          }
        }
#endif
        if (!MODE_VOLUME) {
#ifdef DUAL_POWER_BUTTONS
          aux_on_ = true;
          On();
#else
          next_preset();
#endif
        }
        break;

	return true;

#if NUM_BUTTONS > 1
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
        SaberBase::DoBlast();
        break;
        return true;
#endif
#if NUM_BUTTONS == 1
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_POWER):
        SaberBase::DoForce();
        break;
        return true;
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
        StartOrStopTrack();
        break;
        return true;
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
        SaberBase::DoBlast();
        break;
        return true;
#endif
      case EVENTID(BUTTON_POWER, EVENT_DOUBLE_CLICK, MODE_ON):
        if (millis() - activated_ < 500) {
          if (SetMute(true)) {
            unmute_on_deactivation_ = true;
          }
        }
#if NUM_BUTTONS > 1
        else{
          SaberBase::DoForce();
        }
#endif
        break;
	return true;
	
      case EVENTID(BUTTON_POWER, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_OFF, MODE_ON):
#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
#endif
      case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_ON):
        if (!SaberBase::Lockup()) {
          Off();
        }
        break;

        return true;

        // Lockup
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
#if NUM_BUTTONS == 2
      case EVENTID(BUTTON_AUX, EVENT_HELD, MODE_ON):
#endif
#if NUM_BUTTONS == 3
      case EVENTID(BUTTON_AUX2, EVENT_HELD, MODE_ON):
#endif
        if (!SaberBase::Lockup()) {
          if (pointing_down_) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          }
          SaberBase::DoBeginLockup();
        }
        break;
return true;
        // Off functions
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
#if NUM_BUTTONS == 1
        next_preset();
#endif
#if NUM_BUTTONS > 1
        StartOrStopTrack();
#endif
        break;
	return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_OFF):
        current_volume_ = dynamic_mixer.get_volume();
        if (MODE_VOLUME){
          MODE_VOLUME = false;
          beeper.Beep(0.5, 3000);
          STDOUT.println("Exit Volume Menu");
          
        }
        else{
          MODE_VOLUME = true;
          beeper.Beep(0.5, 3000);
          STDOUT.println("Enter Volume Menu");
        }
        break;
        return true;

      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
        SaberBase::RequestMotion();
        break;
	return true;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
        next_preset();
        break;
	return true;

#if NUM_BUTTONS > 1
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_AUX):
        previous_preset();
        break;
#endif

	return true;

      case EVENTID(BUTTON_AUX2, EVENT_CLICK_SHORT, MODE_OFF):
#if NUM_BUTTONS == 3
        if (MODE_VOLUME){
          STDOUT.println("Volume Down");
          if (dynamic_mixer.get_volume() <= max_volume_ && dynamic_mixer.get_volume() > (0.10 * max_volume_)){
            current_volume_ = dynamic_mixer.get_volume();
            current_volume_ -= (max_volume_ * 0.10) ;
            dynamic_mixer.set_volume(current_volume_);
            beeper.Beep(0.5, 2000);
            STDOUT.print("Current Volume: ");
            STDOUT.println(dynamic_mixer.get_volume());
          }
          else{
            beeper.Beep(0.5, 1000);
          }
        }
#endif

#ifdef DUAL_POWER_BUTTONS
        if (!MODE_VOLUME) {next_preset();}
#else
        if (!MODE_VOLUME) {previous_preset();}
#endif
        break;
	return true;

	// Events that needs to be handled regardless of what other buttons
	// are pressed.
      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
	if (SaberBase::Lockup()) {
	  SaberBase::DoEndLockup();
	  SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
	  return true;
	}
    }
    return false;
  }
private:
  bool aux_on_ = true;
  bool pointing_down_ = false;
  bool MODE_VOLUME = false;
  int32_t max_volume_ = dynamic_mixer.get_volume();
  int32_t current_volume_ = dynamic_mixer.get_volume();
};

#endif
