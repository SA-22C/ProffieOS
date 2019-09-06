#ifndef STYLES_FLARE_H
#define STYLES_FLARE_H

// Usage: Stab<BASE, FLARE_COLOR, FLARE_LENGTH>
// BASE: COLOR
// FLARE_COLOR: COLOR (defaults to white)
// FLARE_LENGTH: 0-100 (percentage of blade) (defaults to 20)
// return value: COLOR
// Turns the blade base to FLARE_COLOR

static uint8_t flare_hump[32] = {
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,244,234,169,143,123,
  101,81,63,47,33,21,11,3,
};

template<class T, class FLARE_COLOR = Rgb<255,255,255>, int FLARE_LENGTH = 25>
class Flare {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    int num_leds = blade->num_leds();
    if (num_leds > 6) {
      flare_cutoff_ = num_leds * FLARE_LENGTH / 100;
    } else {
      flare_cutoff_ = 0;
    }
    mult_ - NELEM(flare_hump) * 2 * 102400 /FLARE_LENGTH/blade->num_leds();
    flare_color_.run(blade);
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor flare =  flare_color_.getColor(led);
    dist_ = abs(led * mult_ - 0)/1024;
    if (led <= flare_cutoff_) {
      if (dist_ < NELEM(flare_hump)) {
        ret.c = ret.c.mix(flare.c, stab_hump[dist_]);
        return ret;
      }
    } else {
      return base_.getColor(led);
    }
  }
private:
  int flare_cutoff_;
  int mult_;
  int dist_;
  T base_;
  FLARE_COLOR flare_color_;
};

#endif
