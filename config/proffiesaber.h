#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 180
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.1
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define USB_CLASS_WEBUSB
#define ENABLE_SERIAL
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
    { "bank3", "tracks/venus.wav",
        StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<OnSpark<BrownNoiseFlicker<Strobe<Black,White,50,1>,Strobe<Cyan,Black,50,1>,50>,White,200>,White,200,100,400>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,White,50,1>,Strobe<Cyan,Black,50,1>,50>,White,200>,White>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,White,50,1>,Strobe<Cyan,Black,50,1>,50>,White,200>,White>>,White,40>,AudioFlicker<White,Blue>,500>,300,800,Black>>(), "bank3"},
   { "Light", "tracks/rots.wav",
   StylePtr<InOutHelper<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<0,64,255>,Rgb<0,32,128>>,Red,200,800,400>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,BrownNoiseFlicker<GhostWhite,Orange,50>>,BrownNoiseFlicker<GhostWhite,White,50>,80,75>,300,300,Black>>(), "Light"},
   { "Graflex8", "tracks/rey.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Cyan,Rgb<0,64,128>>,White,200>,White>,AudioFlicker<OnSpark<AudioFlicker<Cyan,Rgb<0,64,128>>,White,200>,White>>,White,40>,300,800,Black>>(), "Graflex8"},
   { "Kguard", "tracks/kylotlj.wav",
    //StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,Blue,200,100,400>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,White>,AudioFlicker<OnSpark<BrownNoiseFlicker<Strobe<Black,Red,50,1>,Strobe<Red,Orange,50,1>,50>,White,200>,White>>,White,40>,300,800,Black>>(), "Kguard"},
       StylePtr<InOutSparkTip<SimpleClash<Lockup<Blast<Strobe<Rgb<128,0,0>,StyleFire<Orange,Yellow,0,3,FireConfig<0,2500,10>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,2500,10>>,25,1>,Cyan,200,100,400>,AudioFlicker<Strobe<Rgb<128,0,0>,StyleFire<Red,Orange,0,2,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,50,1>,White>,AudioFlicker<Strobe<Rgb<128,0,0>,StyleFire<Red,Orange,0,2,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,50,1>,White>>,White,40>,200,800,White>>(), "Kguard"},
    { "R1Vader", "tracks/hall.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Red,Rgb<128,0,0>>,White,200>,Green>,AudioFlicker<OnSpark<AudioFlicker<Red,Rgb<128,0,0>>,White,200>,White>>,White,40>,700,800,Black>>(), "R1Vader"},
    { "LukeROTJ", "tracks/jaba.wav",
        StylePtr<InOutHelper<EasyBlade<OnSpark<AudioFlicker<GREEN, Rgb<0,128,0>>>, WHITE>, 200, 800> >(), "LukeROTJ"},
    { "Traya", "tracks/traya.wav",
        StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Strobe<BLACK, Yellow, 50, 1>, Strobe<RED, Black, 50, 1>, 50>>, WHITE>, 300, 800> >(), "Traya"},
    { "DrkKyber", "tracks/mars.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Pulsing<AudioFlicker<Red,Rgb<50,0,0>>,AudioFlicker<Rgb<50,0,0>,Red>,250>,Green>,AudioFlicker<Pulsing<AudioFlicker<Red,Rgb<50,0,0>>,AudioFlicker<Rgb<50,0,0>,Red>,250>,White>>,Green,40>,300,800,Black>>(), "DrkKyber"},
    { "balance", "tracks/revan.wav",
        StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<RandomPerLEDFlicker<Gradient<Green,Coral>,Gradient<Coral,Green>>,Cyan,200>,Blue>,AudioFlicker<OnSpark<RandomPerLEDFlicker<Gradient<Green,Coral>,Gradient<Coral,Green>>,White,200>,Cyan>>,Cyan,40>,500,800,Black>>(), "balance"},
   { "vengence", "tracks/mercury.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Cyan>,AudioFlicker<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Cyan>>,Cyan,40>,300,800,Black>>(), "vengence"},
   { "RgueCmdr", "tracks/venus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<ColorCycle<Yellow,  0, 1, AudioFlicker<DarkOrange, Rgb<128,0,0>>,  100, 3000, 800>>, White>, 300, 800> >(), "RgueCmdr"},
   { "SAVANT", "tracks/mars.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<GREEN, Blue, 50>>, WHITE>, 300, 800> >(), "SAVANT"},
   { "SmthGrey", "tracks/mercury.wav",
    StylePtr<InOutSparkTip<EasyBlade<HumpFlicker<Red,SpringGreen,25>, WHITE>, 300, 800>>(), "SmthGrey"},
   { "SmthJedi", "tracks/uranus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Yellow, Orange, 50>>, WHITE>, 300, 800> >(), "SmthJedi"},
   { "TthCrstl", "tracks/mars.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<RandomPerLEDFlicker<Green, Cyan>>, WHITE>, 300, 800> >(), "TthCrstl"},
   { "SmthJedi", "tracks/mars.wav",
    &style_charging, "Battery\nLevel"}
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<128, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif
