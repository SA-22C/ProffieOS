#ifndef STYLES_TRANSITIONS_H
#define STYLES_TRANSITIONS_H

// Usage: ChangeSpark<TRANSITION TIME (ms), BASE, FADE_COLOR>
// TRANSITION TIME: a number (ms)
// BASE: COLOR
// FADE_COLOR: COLOR (defaults to white)
// return value: COLOR
// When you initiate EFFECT_CHANGE, it starts with FADE_COLOR, and then fades to BASE over a period of transition in ms.

template<int transition_, class T, class FADE_COLOR = Rgb<255,255,255>>
class ChangeSpark {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    fade_color_.run(blade);
    uint32_t m = millis();
    if (effect_.Detect(blade)) {
      change_millis_ = m;
    }
    uint32_t t = millis() - change_millis_;
    uint32_t fade_millis = transition_;
    if (t < fade_millis) {
      mix_ = 255 - 255 * t / fade_millis;
    } else {
      mix_ = 0;
    }
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor fade = fade_color_.getColor(led);
    ret.c = ret.c.mix(fade.c, mix_);
    return ret;
  }
private:
  OneshotEffectDetector<EFFECT_CHANGE> effect_;
  int mix_;
  T base_;
  FADE_COLOR fade_color_;
  uint32_t change_millis_;
};

#endif
