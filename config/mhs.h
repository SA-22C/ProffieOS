#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.1
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
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
  { "Rogue", "tracks/rey_training.wav",
      StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, Blue,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
      StylePtr<InOutHelper<CCAudio<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(), "Graflex8"},
  { "Bespin", "tracks/venus.wav",
      StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, BrownNoiseFlicker<Green,Blue,75>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
      StylePtr<InOutSparkTip<SimpleClash<Lockup<Blast<BrownNoiseFlicker<Green,Blue,75>,Red,200,100,400>,AudioFlicker<BrownNoiseFlicker<Green,Blue,75>,LemonChiffon>,AudioFlicker<BrownNoiseFlicker<Green,Blue,75>,Orange>>,LemonChiffon,40>,300,800,White>>(), "balance"},
    { "Graflex8", "tracks/rey_training.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, Blue,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Rgb<0,123,255>,Rgb<0,62,139>>,White,200>,Red>,AudioFlicker<OnSpark<AudioFlicker<Blue,Rgb<0,0,139>>,White,200>,White>>,White,40>,350,500,Black>>(), "Graflex8"},
    { "balance", "tracks/venus.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, BrownNoiseFlicker<Green,Blue,75>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<SimpleClash<Lockup<Blast<BrownNoiseFlicker<Green,Blue,75>,Red,200,100,400>,AudioFlicker<BrownNoiseFlicker<Green,Blue,75>,LemonChiffon>,AudioFlicker<BrownNoiseFlicker<Green,Blue,75>,Orange>>,LemonChiffon,40>,300,800,White>>(), "balance"},
    { "vengence", "tracks/mercury.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, AudioFlicker<Magenta,Red>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Blue>,AudioFlicker<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Cyan>>,Cyan,40>,300,800,Black>>(), "Vengence"},
    { "Traya", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, BrownNoiseFlicker<Strobe<BLACK, Yellow, 50, 1>, Strobe<RED, Black, 50, 1>, 50>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Strobe<BLACK, Yellow, 50, 1>, Strobe<RED, Black, 50, 1>, 50>>, WHITE>, 300, 800> >(), "Traya"},
    { "cyber", "tracks/cyber.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50, AudioFlicker<SpringGreen,Rgb<0,128,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<EasyBlade<ColorCycle<GreenYellow,0,1,AudioFlicker<SpringGreen,Rgb<0,128,0>>,100,3000,1000>, WHITE>, 300, 800> >(), "cyber"},
    { "proto1", "tracks/proto1.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Red,Rgb<128,0,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<EasyBlade<ColorCycle<Orange,0,1,AudioFlicker<Red,Rgb<128,0,0>>,100,3000,1000>, WHITE>, 300, 800> >(), "proto1"},
    { "proto2", "tracks/proto2.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<SteelBlue,Rgb<0,0,128>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<EasyBlade<ColorCycle<Cyan,0,1,AudioFlicker<SteelBlue,Rgb<0,0,128>>,100,3000,1000>, WHITE>, 300, 800> >(), "proto2"},
    { "proto3", "tracks/proto3.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Magenta,Pink>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<EasyBlade<ColorCycle<Pink,0,1,AudioFlicker<Magenta,Pink>,100,3000,1000>, WHITE>, 300, 800> >(), "proto3"},
    { "R1Vader", "tracks/hall.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Red,Rgb<128,0,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Red,Rgb<128,0,0>>,White,200>,Green>,AudioFlicker<OnSpark<AudioFlicker<Red,Rgb<128,0,0>>,White,200>,White>>,White,40>,700,800,Black>>(), "R1Vader"},
    { "Kguard", "tracks/kylotlj.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,Blue,200,100,400>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,White>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,White>>,White,40>,300,800,Black>>(), "Kguard"},
    { "DrkKyber", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Red,Rgb<128,0,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Sparkle<AudioFlicker<Red,Rgb<128,0,0>>,Yellow,300,1024>,Blue,200,100,400>,AudioFlicker<Sparkle<Red,Yellow,300,1024>,Cyan>,AudioFlicker<Sparkle<Blue,White,300,1024>,White>>,White,40>,300,800,Black>>(), "DrkKyber"},
    { "RgueCmdr", "tracks/venus.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<DarkOrange, Rgb<128,0,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<ColorCycle<Yellow,  0, 1, AudioFlicker<DarkOrange, Rgb<128,0,0>>,  100, 3000, 800>>, White>, 300, 800> >(), "RgueCmdr"},

    { "LukeROTJ", "tracks/jabba.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Green,Rgb<0,139,0>>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Green,Rgb<0,139,0>>,White,200>,Orange,200,100,400>,AudioFlicker<OnSpark<AudioFlicker<Green,Rgb<0,139,0>>,White,200>,White>,AudioFlicker<OnSpark<AudioFlicker<Green,Rgb<0,139,0>>,White,200>,Red>>,White,40>,200,500,Black>>(),"LukeROTJ"},
    { "Light", "tracks/rots.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<Coral,Moccasin>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Coral,Moccasin>,White,200>,SteelBlue,200,100,400>,AudioFlicker<OnSpark<AudioFlicker<Coral,Moccasin>,White,200>,Yellow>,AudioFlicker<OnSpark<AudioFlicker<Coral,Moccasin>,White,200>,White>>,White,40>,300,800,Black>>(), "Light"},
    { "SAVANT", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,BrownNoiseFlicker<GREEN, Blue, 50>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<GREEN, Blue, 50>>, WHITE>, 300, 800> >(), "SAVANT"},
    { "SmthGrey", "tracks/mercury.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,Gradient<Magenta, Red>,  17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<Strobe<BLACK, Gradient<Magenta, Red>, 30, 1>>, WHITE>, 300, 800> >(), "SmthGrey"},
    {"SmthJedi", "tracks/uranus.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,BrownNoiseFlicker<Yellow, Orange, 50>,17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Yellow, Orange, 50>>, WHITE>, 300, 800> >(), "SmthJedi"},
    { "TeensySF", "tracks/venus.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,AudioFlicker<PeachPuff, PapayaWhip>,17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<AudioFlicker<PeachPuff, PapayaWhip>>, WHITE>, 300, 800> >(), "TeensySF"},
    { "TthCrstl", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,RandomPerLEDFlicker<Green, Cyan>,17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutHelper<EasyBlade<OnSpark<RandomPerLEDFlicker<Green, Cyan>>, WHITE>, 300, 800> >(),  "TthCrstl"},
    { "SmthFuzz", "tracks/rots.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,HumpFlicker<Green, Blue, 50>,17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        StylePtr<InOutSparkTip<EasyBlade<AudioFlicker<HumpFlicker<Green, Blue, 50>, Red>, WHITE>, 300, 800>>(), "SmthFuzz"},
    { "SmthJedi", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<White,  17, 50,HumpFlicker<Green, Blue, 50>,17, 450, 4000>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>,Strobe<Black,White,15,1>>, 300, 6000, ColorCycle<White,  17, 50, White,  17, 50, 1>>>(),
        &style_charging, "Battery\nLevel"}
};
BladeConfig blades[] = {
    { 0, SubBlade(0,5, WS2811BladePtr<144, WS2811_ACTUALLY_800kHz | WS2811_GRB>()),
        SubBlade(6,130, NULL),
         CONFIGARRAY(presets) },

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
//Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
#endif
