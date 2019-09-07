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
  255,255,252,247,240,232,222,211,
  199,186,173,159,145,132,119,106,
  94,82,72,62,53,45,38,32,
  26,22,18,14,11,9,7,5
};

template<class T, class STAB_COLOR = Rgb<255,255,255>, int STAB_MILLIS = 1000,
  int STAB_WIDTH=50, BladeEffectType EFFECT = EFFECT_STAB>
class Stab {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    int num_leds = blade->num_leds();
    mult_ = NELEM(stab_hump) * 2 * 102400 /STAB_WIDTH/blade->num_leds();
    lockup_location_ = blade->num_leds() * mult_;
    stab_color_.run(blade);
    // This should make us activate the stab at least one "frame".
    stab_ |= !!effect_.Detect(blade);
    if (stab_ && micros() - effect_.last_detected_micros() > STAB_MILLIS * 1000)
      stab_ = false;
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    if (stab_) {
      OverDriveColor stab = stab_color_.getColor(led);
      dist_ = abs(led * mult_ - lockup_location_)/1024;
      if (dist_ < NELEM(stab_hump)) {
        ret.c = ret.c.mix(stab.c, stab_hump[dist_]);
      }
    }
    return ret;
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
