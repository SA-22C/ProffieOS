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

static uint8_t block_hump[32] = {
  255,255,252,247,240,232,222,211,
  199,186,173,159,145,132,119,106,
  94,82,72,62,53,45,38,32,
  26,22,18,14,11,9,7,5
};

template<class BASE, class LOCALIZED_LOCKUP, class DRAG_COLOR = LOCALIZED_LOCKUP,
         class BLOCK_COLOR = LOCALIZED_LOCKUP, int LOCKUP_WALK_MILLIS = 200,
		 int LOCKUP_WIDTH_PERCENT = 50, int BLOCK_WALK_MILLIS = 50,
     int BLOCK_WIDTH_PERCENT = 20, BladeEffectType EFFECT = EFFECT_LOCKUP_BEGIN>
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
        effect_location_ = e->location;
        lockup_detected_ = true;
      }
      mult_ = NELEM(lockup_hump) * 2 * 102400 / LOCKUP_WIDTH_PERCENT / blade->num_leds();
      block_mult_ = NELEM(block_hump) * 2 * 102400 / BLOCK_WIDTH_PERCENT / blade->num_leds();
      lockup_location_ = e->location * blade->num_leds() * mult_;
      original_location_ = lockup_location_;
      block_location1_ = e->location * blade->num_leds() * block_mult_;
      original_block_ = block_location1_;
      block_location2_ = (e->location + 0.25) * blade->num_leds() * block_mult_;
      original_block2_ = block_location2_;
      block_location3_ = (e->location - 0.25) * blade->num_leds() * block_mult_;
      original_block3_ = block_location3_;
      total_leds_ = blade->num_leds();
    }
      if (micros() - (LOCKUP_WALK_MILLIS * 1000) > last_walk_) {
        if (lockup_location_ < original_location_ * 1.1 & !upper_) {
          lockup_location_ += original_location_ * 0.015;
          upper_ = false;
        } else if (lockup_location_ >= original_location_ * 1.1) {
          upper_ = true;
        }
        if (lockup_location_ >=original_location_ * 0.9 & upper_) {
          lockup_location_ -= original_location_ * 0.015;
        } else if (lockup_location_ <= original_location_ * 0.9){
          upper_ = false;
        }
        last_walk_ = micros();
      }
      if (micros() - (BLOCK_WALK_MILLIS * 1000) > block_last_walk_) {
        block_last_walk_ = micros();
        if (block_location1_ < original_block_ * 1.1 & !block_upper_) {
          block_location1_ += original_block_ * 0.01;
          block_upper_ = false;
        } else if (block_location1_ > original_block_ * 1.1) {
          block_upper_ = true;
        }
        if (block_location1_ > original_block_ * 0.9 & block_upper_) {
          block_location1_ -= original_block_ * 0.0075;
        } else if (block_location1_ < original_block_ * 0.9){
          block_upper_ = false;
        }
        if (block_location3_ < original_block3_ * 1.5 & !block_upper3_) {
          block_location3_ += original_block3_ * 0.035;
          block_upper3_ = false;
        } else if (block_location3_ > original_block3_ * 1.5) {
          block_upper3_ = true;
        }
        if (block_location3_ > original_block3_ * 0.6 & block_upper3_) {
          block_location3_ -= original_block3_ * 0.045;
        } else if ( block_location3_ < original_block3_ * 0.6) {
          block_upper3_ = false;
        }
        if (block_location2_ > original_block2_ * 0.6 & !block_lower2_) {
          block_location2_ -= original_block2_ * 0.045;
          block_lower2_ = false;
        } else if (block_location2_ < original_block2_ * 0.6) {
          block_lower2_ = true;
        }
        if (block_location2_ < original_block2_ * 1.4 & block_lower2_) {
          block_location2_ += original_block2_ * 0.035;
        } else if (block_location2_ > original_block2_ * 1.4) {
          block_lower2_ = false;
        }
      }
  }
  OverDriveColor getColor(int led) {
    OverDriveColor ret = base_.getColor(led);
    OverDriveColor lock = lockup_.getColor(led);
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
    lock = lockup_.getColor(led);
  } else {
    lock = drag_.getColor(led);
  }
	  case SaberBase::LOCKUP_NORMAL:
	  case SaberBase::LOCKUP_ARMED:  // TODO: should this be different?
    if (dist_ < NELEM(lockup_hump)) {
      ret.c = ret.c.mix(lock.c, lockup_hump[dist_]);
      return ret;
    } else {
      return base_.getColor(led);
    }

case SaberBase::LOCKUP_BLOCK: // Fett263 addition

if (is_same_type<BLOCK_COLOR, LOCALIZED_LOCKUP>::value) {
  lock = lockup_.getColor(led);
} else {
  lock = block_.getColor(led);
}
  if (led < (block_location1_/block_mult_ + BLOCK_WIDTH_PERCENT * total_leds_/2/100) &&
      led > (block_location1_/block_mult_ - BLOCK_WIDTH_PERCENT * total_leds_/2/100)) {
      int blockdist1 = abs(led * block_mult_ - block_location1_)/1024;
      if (blockdist1 < NELEM(block_hump)) {
        ret.c = ret.c.mix(lock.c, block_hump[blockdist1]);
      }
  }
  if (led < (block_location2_/block_mult_ + BLOCK_WIDTH_PERCENT * total_leds_/2/100) &&
      led > (block_location2_/block_mult_ - BLOCK_WIDTH_PERCENT * total_leds_/2/100)){
        int blockdist1 = abs(led * block_mult_ - block_location2_)/1024;
        if (blockdist1 < NELEM(block_hump)) {
          ret.c = ret.c.mix(lock.c, block_hump[blockdist1]);
        }
  }
  if (led < (block_location3_/block_mult_ + BLOCK_WIDTH_PERCENT * total_leds_/2/100) &&
      led > (block_location3_/block_mult_ - BLOCK_WIDTH_PERCENT * total_leds_/2/100)){
        int blockdist1 = abs(led * block_mult_ - block_location3_)/1024;
        if (blockdist1 < NELEM(block_hump)) {
          ret.c = ret.c.mix(lock.c, block_hump[blockdist1]);
        }
  }
    return ret;
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
  float effect_location_;
  int original_block_;
  int original_block2_;
  int original_block3_;
  int dist_;
  int mult_;
  int block_mult_;
  int total_leds_;
  uint32_t last_walk_;
  uint32_t block_last_walk_;
  bool upper_;
  bool block_upper_;
  bool block_lower2_;
  bool block_upper3_;
  bool lockup_detected_;
  BASE base_;
  LOCALIZED_LOCKUP lockup_;
  DRAG_COLOR drag_;
  BLOCK_COLOR block_;
  OneshotEffectDetector<EFFECT> effect_;
};

#endif
