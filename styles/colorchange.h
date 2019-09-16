#ifndef STYLES_COLORCHANGE_H
#define STYLES_COLORCHANGE_H

// ColorChange style can be inserted into an effect in place of a static color and will rotate through colors or effects with SaberBase::DoChange().  Multiple instances can be included to change various colors of a preset.

template<class... COLORS>
class ColorChange {
public:

  void run(BladeBase* blade) {
    colors_.run(blade);
    if (effect_.Detect(blade)) {
	n_ = (n_ + 1) % sizeof... (COLORS);
  SaberBase::DoSetColor(n_);
   }
    if (change_.Detect(blade)) {
	n_ = SaberBase::DoINTGetColor();
   }
  }
  OverDriveColor getColor(int led) {
    return colors_.getColor(n_, led);

  }
private:
  OneshotEffectDetector<EFFECT_CHANGE> effect_;
  OneshotEffectDetector<EFFECT_CHANGEPRESET> change_;
  int n_ = SaberBase::DoINTGetColor();
  MixHelper<COLORS...> colors_;
};

//ColorScroll features 3 modes, "EFFECT_CHANGE" which advances colors once per click (like ColorChange), "EFFECT_SCROLL" which scrolls through colors/effects continuously and "EFFECT_SELECT" which stops scroll to select and run the current color/effect.

template<int millis_per_color, class... COLORS>
class ColorScroll {
public:
  void run(BladeBase* blade) {
    colors_.run(blade);
    if (effect_.Detect(blade)) {
	n_ = (n_ + 1) % sizeof... (COLORS);
	start_ = 0;
   }
    if (change_.Detect(blade)) {
	n_ = SaberBase::DoINTGetColorScroll();
	start_ = 0;
   }
    if (select_.Detect(blade)) {
	n_ = n_;
  SaberBase::DoSetColorScroll(n_);
     start_ = 0;
   }
    if (scroll_.Detect(blade)) {
	start_ = 1;
   }
	if (start_ == 1) {
	 uint32_t now = micros();
      if (now - last_micros_ > millis_per_color * 1000) {
        if (now - last_micros_ > millis_per_color * 10000) {
	   n_ = n_;
	   last_micros_ = now;
       } else {
	   n_ = (n_ + 1) % sizeof...(COLORS);
	  last_micros_ += millis_per_color * 1000;
      }
    }
   }
  }
  OverDriveColor getColor(int led) {
    return colors_.getColor(n_, led);
  }
private:
  OneshotEffectDetector<EFFECT_CHANGE> effect_;
  OneshotEffectDetector<EFFECT_CHANGEPRESET> change_;
  OneshotEffectDetector<EFFECT_SCROLL> scroll_;
  OneshotEffectDetector<EFFECT_SELECT> select_;
  uint32_t last_micros_;
  int n_ = SaberBase::DoINTGetColorScroll();
  int start_;
  MixHelper<COLORS...> colors_;
};

//EffectScroll features 2 modes,"EFFECT_SCROLL" which scrolls through colors/effects continuously and "EFFECT_SELECT" which stops scroll to select and run the current color/effect.

template<int millis_per_color, class... COLORS>
class EffectScroll {
public:
  void run(BladeBase* blade) {
    colors_.run(blade);
    if (change_.Detect(blade)) {
	n_ = SaberBase::DoINTGetEffect();
	start_ = 0;
   }
    if (select_.Detect(blade)) {
	n_ = n_;
  SaberBase::DoSetEffect(n_);
     start_ = 0;
   }
    if (scroll_.Detect(blade)) {
	start_ = 1;
   }
	if (start_ == 1) {
	 uint32_t now = micros();
      if (now - last_micros_ > millis_per_color * 1000) {
        if (now - last_micros_ > millis_per_color * 10000) {
	   n_ = n_;
	   last_micros_ = now;
       } else {
	   n_ = (n_ + 1) % sizeof...(COLORS);
	  last_micros_ += millis_per_color * 1000;
      }
    }
   }
  }
  OverDriveColor getColor(int led) {
    return colors_.getColor(n_, led);
  }
private:
  OneshotEffectDetector<EFFECT_CHANGEPRESET> change_;
  OneshotEffectDetector<EFFECT_SCROLL> scroll_;
  OneshotEffectDetector<EFFECT_SELECT> select_;
  uint32_t last_micros_;
  int n_ = SaberBase::DoINTGetEffect();
  int start_;
  MixHelper<COLORS...> colors_;
};

// Transition Modes - these Color Change / Effect Change modes feature built in transitions, the transition time (ms) can be set to

// Usage: ColorChangeFade<TRANSITION TIME (ms), COLORS>
// TRANSITION TIME: a number, for transition time in ms
// COLORS: array of colors to change through
// return value: COLOR
// When you initiate EFFECT_CHANGE, it starts with fade from current color to next using Transition Time to complete

template<int transition_, class... COLORS>
class ColorChangeFade {
public:
  void run(BladeBase* blade) {
    colors_.run(blade);
    uint32_t m = millis();
    if (effect_.Detect(blade)) {
      on_millis_ = m;
	 c_ = n_;
      n_ = (n_ + 1) % sizeof... (COLORS);
      SaberBase::DoSetColor(n_);
      start_ = 1;
    }
    if (change_.Detect(blade)) {
	n_ = 0;
     c_ = 0;
     start_ = 0;
    }
    if (start_ == 1) {
    uint32_t t = millis() - on_millis_;
    uint32_t fade_millis = transition_;
    if (t < fade_millis) {
      mix_ = 255 - 255 * t / fade_millis;
    } else {
      mix_ = 0;
      start_ = 0;
    }
   }
  }
  OverDriveColor getColor(int led) {
    if (start_ == 1) {
      OverDriveColor ret = colors_.getColor(n_, led);
      OverDriveColor fade = colors_.getColor(c_, led);
      ret.c = ret.c.mix(fade.c, mix_);
      return ret;
    }
    return colors_.getColor(n_, led);
  }
private:
  OneshotEffectDetector<EFFECT_CHANGE> effect_;
  OneshotEffectDetector<EFFECT_CHANGEPRESET> change_;
  uint32_t on_millis_;
  int mix_;
  int n_ = SaberBase::DoINTGetColor();
  int c_;
  int start_;
  MixHelper<COLORS...> colors_;
};

#endif
