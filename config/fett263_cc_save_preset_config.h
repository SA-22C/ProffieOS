#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 300
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVED_PRESET
#define NO_COLOR_SWING
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "R1Vader", "tracks/mars.wav",
StylePtr<InOutHelper<EndSpark<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<BrownNoiseFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,RandomPerLEDFlicker<ColorChange<Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,200>,ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,HumpFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,20>,Pulsing<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,1000>,BrownNoiseFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,200>,BrownNoiseFlicker<RandomPerLEDFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,ColorChange<Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,200>,StyleFire<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,StyleFire<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>,0,3>,Sparkle<AudioFlicker<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorChange<Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>>,Strobe<White,RandomPerLEDFlicker<ColorChange<Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,White,600>,300,500,Black>>(), "full spectrum"},

{ "Light", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<StyleFire<BrownNoiseFlicker<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,RandomPerLEDFlicker<ColorScroll<2000,Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>>,ColorScroll<2000,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>>>,200>,ColorScroll<2000,Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,Strobe<White,RandomPerLEDFlicker<ColorScroll<2000,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "unstable blade"},

{ "Balance", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<StyleFire<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorScroll<2000,Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>,0,3,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,Strobe<White,RandomPerLEDFlicker<ColorScroll<2000,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "fire blade"},

{ "Yoda", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<AudioFlicker<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,ColorScroll<2000,Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink>>,Strobe<White,RandomPerLEDFlicker<ColorScroll<2000,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,Pulsing<Pulsing<Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,300>,Gradient<ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorScroll<2000,Red,DarkOrange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "audio flicker"},

{ "KGuard", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<ColorChangeFade<5000,AudioFlicker<DeepSkyBlue,SteelBlue>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,Strobe<White,RandomPerLEDFlicker<ColorChange<Red,Blue>,White>,50,1>,RandomPerLEDFlicker<White,ColorChange<DeepSkyBlue,Red>>,Pulsing<Pulsing<Gradient< ColorChange<DeepSkyBlue,Red>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>, ColorChange<DeepSkyBlue,Red>>, ColorChange<DeepSkyBlue,Red>,300>,Gradient< ColorChange<DeepSkyBlue,Red>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>, ColorChange<DeepSkyBlue,Red>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "pull to the darkness"},

{ "cyber", "tracks/venus.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>,ColorChange<SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>, Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue>>,Sparkle<AudioFlicker<ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>,ColorChange<SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>, Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue>>,White>>,Strobe<White,RandomPerLEDFlicker<ColorChange<Red,Red,Red,Blue,Blue, Blue,Blue,Red,Red, Red,Red,Red>,White>,50,1>,RandomPerLEDFlicker<White,ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>>,Pulsing<Pulsing<Gradient<ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>>,ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>,300>,Gradient<ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow, Green,Aquamarine,Cyan>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "audio flicker / rain"},

{ "Tano", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<ChangeSpark<600,AudioFlicker<ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>,ColorChange<Rgb<60,60,100>, Rgb<40,0,80>>>,HumpFlicker<ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>,White,40>>,Strobe<White,RandomPerLEDFlicker<Red,White>,50,1>, RandomPerLEDFlicker<White,ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>>,Pulsing<Pulsing<Gradient<ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>>,ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>,300>,Gradient<ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChange<Rgb<100,100,150>, Rgb<125,30,255>>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "coran horn dual phase"},

{ "OUTCAST", "tracks/venus.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>,ColorChange<SteelBlue,DodgerBlue,Rgb<128,0,0>,Rgb<40,0,80>,Rgb<60,60,0>>>,AudioFlicker<Red,Rgb<128,0,0>>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,Strobe<White,RandomPerLEDFlicker<EffectScroll<2000,Red,Blue,Blue>,White>,50,1>,RandomPerLEDFlicker<White,EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>,Red,Red>>,Pulsing<Pulsing<Gradient<EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>,Red,Red>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>, Red,Red>>,EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>, Red,Red>,300>,Gradient<EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>,Red,Red>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,EffectScroll<2000,ColorChange<DeepSkyBlue,Blue,Green,Rgb<125,30,255>,Yellow>,Red,Red>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "light side - dark side"},

{ "SAVAGEN", "tracks/venus.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<EffectScroll<2000,AudioFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>>>,StyleFire<BrownNoiseFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,RandomPerLEDFlicker<ColorChangeFade<500,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,Rgb<10,0,15>,Rgb<25,0,0>, Rgb<25,0,0>,OrangeRed,Rgb<15,15,0>,Rgb<10,15,0>>,ColorChangeFade<500,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>, Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>>>,200>,ColorChangeFade<500,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>, Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,HumpFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>>,20>,Pulsing<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>>,1000>,BrownNoiseFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>, Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>>,200>,BrownNoiseFlicker<RandomPerLEDFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>, Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>>>,ColorChangeFade<500,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,Rgb<40,0,40>,Rgb<80,0,15>, Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,Rgb<15,60,0>>,200>,StyleFire<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>>>,StyleFire<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<50,0,10>, Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>>,0,3>,Sparkle<AudioFlicker<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,ColorChangeFade<500,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<40,0,80>,Rgb<60,0,60>,DeepPink, Rgb<128,0,0>,OrangeRed,Rgb<60,60,0>,Rgb<40,80,0>>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>>,Strobe<White,RandomPerLEDFlicker<ColorChangeFade<500,Red,Red,Red,Red,Red,Red,Blue,Blue, Blue,Blue,Red,Red>,White>,50,1>,RandomPerLEDFlicker<White,ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>>,Pulsing<Pulsing<Gradient<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>>,ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,300>,Gradient<ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,ColorChangeFade<500,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink, Red,DarkOrange,Yellow,GreenYellow>>,2000>,200,40,60,20>,White>,White>,300,500,Black>>(), "full spectrum fade"},
{ "RETURN", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<LocalizedLockup<ColorScroll<2000,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,BrownNoiseFlicker<Red,Rgb<60,0,0>,400>,StyleFire<Red,Rgb<80,0,0>,0,3>>,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,1>,RandomPerLEDFlicker<White,Red>,Pulsing<Pulsing<Gradient<Red,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,Red>,Red,300>,Gradient<Red,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,Red>,2000>,200,40,60,20>,White>,White>,150,300,Black>>(), "kylo unstable variants"},
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<144, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
