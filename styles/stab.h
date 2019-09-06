#ifndef STYLES_STAB_H
#define STYLES_STAB_H

// Usage: Stab<BASE, STAB_COLOR, STAB_MILLIS>
// BASE: COLOR
// STAB_COLOR: COLOR (defaults to white)
// STAB_MILLIS: a number (defaults to 1000)
// return value: COLOR
// Turns the blade tip to STAB_COLOR for STAB_MILLIS millseconds
// when a stab occurs.

static uint8_t stab_hump[32] = {
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,244,234,169,143,123,
  101,81,63,47,33,21,11,3,
};

template<class T, class STAB_COLOR = Rgb<255,255,255>, int STAB_MILLIS = 1000,
  BladeEffectType EFFECT = EFFECT_STAB>
class Stab {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    int num_leds = blade->num_leds();
    if (num_leds > 6) {
      stab_cutoff_ = num_leds * 90 / 100;
    } else {
      stab_cutoff_ = 0;
    }
    mult_ - NELEM(stab_hump) * 2 * 102400 /50/blade->num_leds();
    lockup_location_ = 1 * blade->num_leds() * mult_;
    stab_color_.run(blade);
    // This should make us activate the stab at least one "frame".
    stab_ |= !!effect_.Detect(blade);
    if (stab_ && micros() - effect_.last_detected_micros() > STAB_MILLIS * 1000)
      stab_ = false;
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor stab = stab_color_.getColor(led);
    dist_ = abs(led * mult_ - lockup_location_)/1024;
    if (stab_ && led >= stab_cutoff_) {
      if (dist_ < NELEM(stab_hump)) {
        ret.c = ret.c.mix(stab.c, stab_hump[dist_]);
        return ret;
      }
    } else {
      return base_.getColor(led);
    }
  }
private:
  OneshotEffectDetector<EFFECT> effect_;
  bool stab_ = false;
  int stab_cutoff_;
  int lockup_location_;
  int mult_;
  int dist_;
  T base_;
  STAB_COLOR stab_color_;
};

#endif
