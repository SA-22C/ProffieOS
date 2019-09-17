#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 200
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.1
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVED_PRESET
#define SET1MAIN Red,OrangeRed,Orange,Yellow,GreenYellow,Green,Cyan,DeepSkyBlue,SteelBlue,Blue,Magenta,Pink
#define SET1A Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>
#define SET1B Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>
#define SET1C Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>
#define SET1FLICKER Rgb<128,0,0>,Rgb<128,34,0>,Rgb<128,82,0>,Rgb<128,128,0>,Rgb<0,87,128>,Rgb<0,128,0>,Rgb<0,128,128>,Rgb<0,95,128>,Rgb<35,65,90>,Rgb<0,0,128>,Rgb<128,0,128>,Rgb<128,96,101>
#define SET1LOCKUP Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
#define SET1DRAG Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
#define SET1STAB Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
#define SET1CLASH White,White,White,White,White,White,White,White,White,White,White,White
#define SET1BLAST White,White,White,White,White,White,White,White,White,White,White,White
#define SET1FLARE White,White,White,White,White,White,White,White,White,White,White,White
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
  { "OUTCAST", "tracks/mars.wav",
  StylePtr<InOutHelper<CCAudio<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(),
  StylePtr<InOutHelper<CCAudio<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(),
  },
  { "R1Vader", "tracks/mercury.wav",
  StylePtr<InOutHelper<CCAudioFlare<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST,SET1FLARE>,180,500>>(),
  StylePtr<InOutHelper<CCAudioFlare<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST,SET1FLARE>,180,500>>(),
  },
  { "Light", "tracks/uranus.wav",
  StylePtr<InOutHelper<CCUnstable<SET1MAIN,SET1A,SET1B,SET1C,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(),
  StylePtr<InOutHelper<CCUnstable<SET1MAIN,SET1A,SET1B,SET1C,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(),
  },
  { "Balance", "tracks/venus.wav",
  StylePtr<InOutHelper<CCUnstableFlare<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST,SET1FLARE>,180,500>>(),
  StylePtr<InOutHelper<CCUnstableFlare<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST,SET1FLARE>,180,500>>(),
  },
  { "KGuard", "tracks/mercury.wav",
  StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<BrownNoiseFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,RandomPerLEDFlicker<ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,200>,ColorChange<Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,HumpFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,20>,Pulsing<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,1000>,BrownNoiseFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,200>,BrownNoiseFlicker<RandomPerLEDFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,200>,StyleFire<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,0,3>,Sparkle<AudioFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>>,Strobe<White,RandomPerLEDFlicker<ColorChange<Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(),
  StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<BrownNoiseFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,RandomPerLEDFlicker<ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,200>,ColorChange<Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,HumpFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,20>,Pulsing<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,1000>,BrownNoiseFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,200>,BrownNoiseFlicker<RandomPerLEDFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,200>,StyleFire<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,0,3>,Sparkle<AudioFlicker<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>>,Strobe<White,RandomPerLEDFlicker<ColorChange<Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(),
  },
    { "SmthJedi", "tracks/mars.wav",
    StylePtr<InOutHelper<CCUnstableFlare<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST,SET1FLARE>,180,500>>(),
        &style_charging, "Battery\nLevel"}
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2811_ACTUALLY_800kHz | WS2811_GRB>(),
    WS2811BladePtr<3, WS2811_ACTUALLY_800kHz | WS2811_GRB, blade6Pin, PowerPINS<bladePowerPin4> >()
  , CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
