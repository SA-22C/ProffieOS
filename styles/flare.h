#ifndef STYLES_FLARE_H
#define STYLES_FLARE_H

// Usage: Stab<BASE, FLARE_COLOR, FLARE_LENGTH>
// BASE: COLOR
// FLARE_COLOR: COLOR (defaults to white)
// FLARE_LENGTH: 0-100 (percentage of blade) (defaults to 20)
// return value: COLOR
// Turns the blade base to FLARE_COLOR

static uint8_t flare_hump[32] = {
  255,255,252,247,240,232,222,211,
  199,186,173,159,145,132,119,106,
  94,82,72,62,53,45,38,32,
  26,22,18,14,11,9,7,5
};

template<class T, class FLARE_COLOR = Rgb<255,255,255>, int FLARE_LENGTH = 35>
class Flare {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    int num_leds = blade->num_leds();
    mult_ = NELEM(flare_hump) * 2 * 102400 /FLARE_LENGTH/blade->num_leds();
    flare_color_.run(blade);
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor flare =  flare_color_.getColor(led);
    dist_ = led * mult_/1024;
    if (dist_ < NELEM(flare_hump)) {
      ret.c = ret.c.mix(flare.c, flare_hump[dist_]);
    }
    return ret;
  }
private:
  int flare_cutoff_;
  int mult_;
  int dist_;
  T base_;
  FLARE_COLOR flare_color_;
};

#endif
