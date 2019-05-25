#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 2
#define VOLUME 2500
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#endif

//MaulSaber

#ifdef CONFIG_PRESETS
Preset presets[] = {

{ "Menace", "tracks/MaulThme.wav",
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<Red,Rgb<150,0,0>>,Gradient<Green,Red,White>,200,300,600>,Pulsing< Gradient<AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>>,Gradient<AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>>,3500>,BrownNoiseFlicker<Red,White,200>>,BrownNoiseFlicker<Red,White,50>,80,50>,200,300,Black>>(),
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<Red,Rgb<150,0,0>>,Gradient<Green,Red,White>,200,300,600>,Pulsing< Gradient<AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>>,Gradient<AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>,AudioFlicker<Red,Tomato>>,3500>,BrownNoiseFlicker<Red,White,200>>,BrownNoiseFlicker<Red,White,50>,80,50>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Maul Red"},

{ "SmthJedi", "tracks/mercury.wav",
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<Chartreuse,Rgb<100,150,0>>,Gradient<Green,Red,White>,200,300,600>,Pulsing< Gradient<AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>>,Gradient<AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>>,3500>,BrownNoiseFlicker<Green,White,200>>,BrownNoiseFlicker<Green,White,50>,80,50>,200,300,Black>>(),
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<Chartreuse,Rgb<100,150,0>>,Gradient<Green,Red,White>,200,300,600>,Pulsing< Gradient<AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>>,Gradient<AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,Strobe<White,BrownNoiseFlicker<Red,White,50>,50,1>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>,AudioFlicker<Chartreuse,GreenYellow>>,3500>,BrownNoiseFlicker<Green,White,200>>,BrownNoiseFlicker<Green,White,50>,80,50>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Green"},

{ "SmthGrey", "tracks/mars.wav",
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<Green,Red,White>,200,300,600>,Pulsing<Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,3500>,BrownNoiseFlicker<Magenta,White,200>>,White,40>,200,300,Black>>(),
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<Green,Red,White>,200,300,600>,Pulsing<Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,3500>,BrownNoiseFlicker<Magenta,White,200>>,White,40>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Purple"},

{ "TeensySF", "tracks/uranus.wav",
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<White,GhostWhite>,Gradient<Green,Red,Yellow>,200,300,600>,Pulsing< Gradient<AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,Strobe<Cyan,BrownNoiseFlicker<Red,Cyan,50>,50,1>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>>,Gradient<AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,Strobe<Cyan,BrownNoiseFlicker<Red,Cyan,50>,50,1>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>>,3500>,BrownNoiseFlicker<Red,White,200>>,BrownNoiseFlicker<Red,Cyan,50>,80,50>,200,300,Black>>(),
StylePtr<InOutSparkTip<LocalizedClash<Lockup<Blast<AudioFlicker<White,GhostWhite>,Gradient<Green,Red,Yellow>,200,300,600>,Pulsing< Gradient<AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,Strobe<Cyan,BrownNoiseFlicker<Red,Cyan,50>,50,1>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>>,Gradient<AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,Strobe<Cyan,BrownNoiseFlicker<Red,Cyan,50>,50,1>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>,AudioFlicker<White,GhostWhite>>,3500>,BrownNoiseFlicker<Red,White,200>>,BrownNoiseFlicker<Red,Cyan,50>,80,50>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"White"},

{ "RgueCmdr", "tracks/venus.wav",
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<Green,Red,White>,200,300,600>,Pulsing<Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,3500>,BrownNoiseFlicker<Magenta,White,200>>,White,40>,200,300,Black>>(),
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<Green,Red,White>,200,300,600>,Pulsing<Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,3500>,BrownNoiseFlicker<Magenta,White,200>>,White,40>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Red"},

{ "TeensySF", "tracks/venus.wav",
StylePtr<InOutHelper<StyleFire<Yellow,LemonChiffon>,150,500,Black>>(),
StylePtr<InOutHelper<StyleFire<Yellow,LemonChiffon>,150,500,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Yellow Fire"},

{ "TthCrstl", "tracks/mercury.wav",
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<Rainbow,White>,AudioFlicker<Rainbow,WHITE>>,White>, 400, 400>>(),
StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<Rainbow,White>,AudioFlicker<Rainbow,WHITE>>,White>, 400, 400>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Rainbow"},

{ "SmthFuzz", "tracks/uranus.wav",
StylePtr<InOutHelper<Lockup<StyleFire<Blast<LocalizedClash<Gradient<Red,OrangeRed,Orange,GreenYellow,Green,Aqua,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,Pulsing<StyleFire<Blast<LocalizedClash<Gradient<Red,Orange,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,1>,Green,Aqua,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,StyleFire<Blast<LocalizedClash<Gradient<Red,Orange,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,1>,Green,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,3500>>,150,500,Black>>(),
StylePtr<InOutHelper<Lockup<StyleFire<Blast<LocalizedClash<Gradient<Red,OrangeRed,Orange,GreenYellow,Green,Aqua,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,Pulsing<StyleFire<Blast<LocalizedClash<Gradient<Red,Orange,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,1>,Green,Aqua,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,StyleFire<Blast<LocalizedClash<Gradient<Red,Orange,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,1>,Green,DodgerBlue,Blue,Rgb<20,0,255>>,White,200,80>,White,300,200,400>,Red,10,2,FireConfig<100,2000,5>,FireConfig<2000,500,50>,FireConfig<0,5000,10>,FireConfig<100,2000,5>>,3500>>,150,500,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Rainbow Fire"},

{ "ChosOne", "tracks/.wav", 
&style_charging,
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,Black,100,1024>,200,300,Black>>(),
StylePtr<InOutHelper<Sparkle<Black,White,100,1024>,200,300,Black>>(),"Battery\nLevel"}

};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<126, WS2811_ACTUALLY_800kHz | WS2811_GRB>(),
 { 0, WS2811BladePtr<126, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), 
SimpleBladePtr<Red3mmLED,NoLED,NoLED,NoLED,bladePowerPin4, -1, -1, -1>(),
SimpleBladePtr<Red3mmLED,NoLED,NoLED,NoLED,bladePowerPin5, -1, -1, -1>(),
 CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
