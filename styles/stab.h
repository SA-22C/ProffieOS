#ifndef STYLES_STAB_H
#define STYLES_STAB_H

// Usage: Stab<BASE, STAB_COLOR, STAB_MILLIS>
// BASE: COLOR
// STAB_COLOR: COLOR (defaults to white)
// STAB_MILLIS: a number (defaults to 1000)
// return value: COLOR
// Turns the blade tip to STAB_COLOR for STAB_MILLIS millseconds
// when a stab occurs.

template<class T, class STAB_COLOR = Rgb<255,255,255>, int STAB_MILLIS = 1000,
  BladeEffectType EFFECT = EFFECT_STAB>
class Stab {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    int num_leds = blade->num_leds();
    if (num_leds > 6) {
      stab_cutoff_ = num_leds * 98 / 100;
    } else {
      stab_cutoff_ = 0;
    }
    stab_color_.run(blade);
    // This should make us activate the stab at least one "frame".
    stab_ |= !!effect_.Detect(blade);
    if (stab_ && micros() - effect_.last_detected_micros() > STAB_MILLIS * 1000)
      stab_ = false;
  }
  OverDriveColor getColor(int led) {
    if (stab_ && led >= stab_cutoff_) {
      return stab_color_.getColor(led);
    } else {
      return base_.getColor(led);
    }
  }
private:
  OneshotEffectDetector<EFFECT> effect_;
  bool stab_ = false;
  int stab_cutoff_;
  T base_;
  STAB_COLOR stab_color_;
};

#endif

