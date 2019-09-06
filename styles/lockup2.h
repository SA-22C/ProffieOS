#ifndef STYLES_LOCKUP_H
#define STYLES_LOCKUP_H

// Usage: Lockup<BASE, LOCKUP, DRAG_COLOR, BLOCK_COLOR>
// BASE, LOCKUP: COLOR
// DRAG_COLOR: COLOR (defaults to the LOCKUP color)
// return value: COLOR
// Shows LOCKUP if the lockup state is true, otherwise BASE.
// Also handles "Drag" effect.
template<class BASE, class LOCKUP, class DRAG_COLOR = LOCKUP, class BLOCK_COLOR = LOCKUP>
class Lockup {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    lockup_.run(blade);
    block_.run(blade);
    if (!is_same_type<DRAG_COLOR, LOCKUP>::value)
      drag_.run(blade);
    int num_leds = blade->num_leds();
    if (num_leds > 6) {
      drag_cutoff_ = num_leds * 98 / 100;
    } else {
      drag_cutoff_ = 0;
    }
  }
  OverDriveColor getColor(int led) {
    switch (SaberBase::Lockup()) {
      // Good luck desciphering this one..

	case SaberBase::LOCKUP_DRAG:
      if (led >= drag_cutoff_) {
	if (is_same_type<DRAG_COLOR, LOCKUP>::value) {
	  case SaberBase::LOCKUP_NORMAL:
	  case SaberBase::LOCKUP_ARMED:  // TODO: should this be different?
	  return lockup_.getColor(led);
	} else {
	  return drag_.getColor(led);
	}
	case SaberBase::LOCKUP_BLOCK: // Fett263 addition
if (is_same_type<BLOCK_COLOR, LOCKUP>::value) {
	  return lockup_.getColor(led);
	} else {
	  return block_.getColor(led);
      }
} else {
	case SaberBase::LOCKUP_NONE:
	break;
      }
    }
    return base_.getColor(led);
  }
private:
  int drag_cutoff_;
  BASE base_;
  LOCKUP lockup_;
  DRAG_COLOR drag_;
  BLOCK_COLOR block_;
};

static uint8_t lockup_hump[32] = {
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,244,234,169,143,123,
  101,81,63,47,33,21,11,3,
};

template<class BASE, class LOCALIZED_LOCKUP, class DRAG_COLOR = LOCALIZED_LOCKUP,
         class BLOCK_COLOR = LOCALIZED_LOCKUP, int LOCKUP_WALK_MILLIS = 200,
         int BLOCK_WALK_MILLIS = 100, int LOCKUP_WIDTH_PERCENT = 50,
         int BLOCK_WIDTH_PERCENT = 33,
          BladeEffectType EFFECT = EFFECT_LOCKUP_BEGIN>
class LocalizedLockup {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    lockup_.run(blade);
    block_.run(blade);
    if (!is_same_type<DRAG_COLOR, LOCALIZED_LOCKUP>::value)
      drag_.run(blade);
    total_leds_ = blade->num_leds();
    if (total_leds_ > 6) {
      drag_cutoff_ = total_leds_ * 90 / 100;
      //drag_cutoff_ = 0;
    } else {
      drag_cutoff_ = 0;
    }
    if (BladeEffect* e = effect_.Detect(blade)) {
      if (e->location > 0.0 && e->location < 1.0) {
        lockup_detected_ = true;
      }
      mult_ = NELEM(lockup_hump) * 2 * 102400 / LOCKUP_WIDTH_PERCENT / blade->num_leds();
      lockup_location_ = e->location * blade->num_leds() * mult_;
      original_location_ = lockup_location_;
      block_location1_ = e->location * blade->num_leds() * mult_;
      original_block_ = block_location1_;
      block_location2_ = (e->location + 0.25) * blade->num_leds() * mult_;
      block_location3_ = (e->location - 0.25) * blade->num_leds() * mult_;
      total_leds_ = blade->num_leds();
    }
    if (micros() - (BLOCK_WALK_MILLIS * 1000) > last_walk_block_) {
      if (block_location1_ < original_block_ * 1.2 & !upper_block_) {
        block_location1_ += block_location1_ * 0.015;
        block_location2_ -= block_location2_ * 0.05;
        block_location3_ += block_location3_ * 0.04;
        upper_block_ = false;
      } else if (block_location1_ >= original_block_ * 1.2) {
        upper_block_ = true;
      }
      if (block_location1_ >= original_block_ * 0.8 & upper_block_) {
        block_location1_ -= block_location1_ * 0.015;
        block_location2_ += block_location2_ * 0.05;
        block_location3_ -= block_location3_ * 0.04;
      } else if (block_location1_ >= original_block_ * 0.8){
        upper_block_ = false;
      }
      last_walk_block_ = micros();
    }
    if (micros() - (LOCKUP_WALK_MILLIS * 1000) > last_walk_) {
      if (lockup_location_ < original_location_ * 1.1 & !upper_) {
        lockup_location_ += lockup_location_ * 0.015;
        upper_ = false;
      } else if (lockup_location_ >= original_location_ * 1.1) {
        upper_ = true;
      }
      if (lockup_location_ >=original_location_ * 0.9 & upper_) {
        lockup_location_ -= lockup_location_ * 0.015;
      } else if (lockup_location_ <= original_location_ * 0.9){
        upper_ = false;
      }
      last_walk_ = micros();
    }
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor lock = lockup_.getColor(led);
    OverDriveColor block = block_.getColor(led);
    int mix = 0;
    dist_ = abs(led * mult_ - lockup_location_)/1024;
    switch (SaberBase::Lockup()) {
      // Good luck desciphering this one..

	case SaberBase::LOCKUP_DRAG:
  if (SaberBase::LOCKUP_DRAG) {
    lockup_location_ = 1 * total_leds_ * mult_;
    lockup_detected_ = false;
  }
      if (led >= drag_cutoff_) {
	if (is_same_type<DRAG_COLOR, LOCALIZED_LOCKUP>::value) {
	  case SaberBase::LOCKUP_NORMAL:
	  case SaberBase::LOCKUP_ARMED:  // TODO: should this be different?
    if (dist_ < NELEM(lockup_hump)) {
      ret.c = ret.c.mix(lock.c, lockup_hump[dist_]);
      return ret;
    } else {
      return base_.getColor(led);
    }
	} else {
    OverDriveColor drag = drag_.getColor(led);
    if (dist_ <NELEM(lockup_hump)) {
      ret.c = ret.c.mix(drag.c, lockup_hump[dist_]);
	    return ret;
    } else {
      return base_.getColor(led);
    }
	}

case SaberBase::LOCKUP_BLOCK: // Fett263 addition
  mult_ = NELEM(lockup_hump) * 2 * 102400 / BLOCK_WIDTH_PERCENT / total_leds_;

  if (led < (block_location1_/mult_ + BLOCK_WIDTH_PERCENT/2 * total_leds_) &&
      led > (block_location1_/mult_ - BLOCK_WIDTH_PERCENT/2 * total_leds_)) {
      int blockdist1 = abs(led * mult_ - block_location1_)/1024;
      if (blockdist1 < NELEM(lockup_hump)) {
        //STDOUT.println(blockdist1);
        //ret.c = ret.c.mix(block.c, lockup_hump[blockdist1]);
        //return ret;
      }
      return block_.getColor(led);
  } else if (led < (block_location2_/mult_ + BLOCK_WIDTH_PERCENT/2 * total_leds_) &&
      led > (block_location2_/mult_ - BLOCK_WIDTH_PERCENT/2 * total_leds_)){
        int blockdist2 = abs(led * mult_ - block_location2_)/1024;
        //ret.c = ret.c.mix(block.c, lockup_hump[blockdist2]);
        //return ret;
        return block_.getColor(led);
  } else if (led < (block_location3_/mult_ + BLOCK_WIDTH_PERCENT/2 * total_leds_) &&
      led > (block_location3_/mult_ - BLOCK_WIDTH_PERCENT/2 * total_leds_)){
        int blockdist3 = abs(led * mult_ - block_location3_)/1024;
        //ret.c = ret.c.mix(block.c, lockup_hump[blockdist3]);
        //return ret;
        return block_.getColor(led);
  } else {
    return base_.getColor(led);
  }
} else {
case SaberBase::LOCKUP_NONE:
break;
    }
  }
  lockup_detected_ = false;
  return base_.getColor(led);
}
private:
  int drag_cutoff_;
  int lockup_location_;
  int block_location1_;
  int block_location2_;
  int block_location3_;
  int original_location_;
  int original_block_;
  int dist_;
  int mult_;
  int total_leds_;
  int last_walk_;
  int last_walk_block_;
  bool upper_;
  bool upper_block_;
  bool lockup_detected_;
  BASE base_;
  LOCALIZED_LOCKUP lockup_;
  DRAG_COLOR drag_;
  BLOCK_COLOR block_;

  OneshotEffectDetector<EFFECT> effect_;
};

#endif
