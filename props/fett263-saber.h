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
        aux_on_ = false;
        On();
	return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
#ifdef DUAL_POWER_BUTTONS
        aux_on_ = true;
        On();
#else
        next_preset();
#endif
	return true;

      case EVENTID(BUTTON_POWER, EVENT_DOUBLE_CLICK, MODE_ON):
	if (millis() - activated_ < 500) {
	  if (SetMute(true)) {
	    unmute_on_deactivation_ = true;
	  }
	}
	return true;

      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
      case EVENTID(BUTTON_POWER, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_OFF, MODE_ON):
#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
#endif
        Off();
        return true;

      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
        SaberBase::DoForce();
	return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
        // Avoid the base and the very tip.
	// TODO: Make blast only appear on one blade!
        SaberBase::DoBlast();
	   return true;

	// ColorChange
  #ifdef NO_COLOR_SWING
	case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
	SaberBase::DoChange();
	return true;
  #else
  case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
  if (colorswing_) {
    SaberBase::DoMExit();
    colorswing_ = false;
  } else if (!colorswing_) {
    SaberBase::DoMEnter();
    colorswing_ = true;
  }
  return true;
  case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON):
  if (colorswing_) {
    SaberBase::DoChange();
  }
  return true;
  #endif


     // ColorScroll
     case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_AUX):
	//beeper.Beep(0.5, 2000.0);
	SaberBase::DoScroll();
	return true;

     // ColorSelect
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON | BUTTON_POWER):
	SaberBase::DoSelect();
	return true;

#if NUM_BUTTONS > 1
    case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_POWER):
    if (!clear_) {
      clear_ = true;
      SaberBase::DoMEnter();
    } else if (clear_) {
      SaberBase::DoMSelect();
      SaberBase::DoClearPresets();
      clear_ = false;
    }
    return true;
#endif

        // Lockup
		// Enables Dual Lockup functionality using "Block" as second lockup effect
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
	  	SaberBase::SetLockup(SaberBase::LOCKUP_BLOCK);
		SaberBase::DoBeginLockup();
	  	return true;
		break;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
        if (!SaberBase::Lockup()) {
          if (pointing_down_) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          }
          SaberBase::DoBeginLockup();
	  return true;
        }
        break;

        // Off functions
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
        StartOrStopTrack();
	return true;

      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
        SaberBase::RequestMotion();
	return true;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
        next_preset();
	return true;

      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_AUX):
      if (clear_) {
        clear_ = false;
        SaberBase::DoMExit();
      } else {
        previous_preset();
      }
	return true;

      case EVENTID(BUTTON_AUX2, EVENT_CLICK_SHORT, MODE_OFF):
#ifdef DUAL_POWER_BUTTONS
        next_preset();
#else
        previous_preset();
#endif
	return true;

	// Events that needs to be handled regardless of what other buttons
	// are pressed.
      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
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
  bool clear_ = false;
  bool colorswing_ = false;
};

#endif
