#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1500
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
   { "ESB", "tracks/venus.wav",
        StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<AudioFlicker<DeepSkyBlue,SteelBlue>,White,200,100,400>,Pulsing<Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,3500>,AudioFlicker<White,DeepSkyBlue>>,White,40>,AudioFlicker<White,DeepSkyBlue>, 650>,180,500,Black>>(), "ESB"},
   { "BEspin", "tracks/rots.wav",
        StylePtr<InOutHelper<Stab<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<0,64,255>,Rgb<0,32,128>>,Red,200,800,400>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,BrownNoiseFlicker<GhostWhite,Orange,50>>,BrownNoiseFlicker<GhostWhite,White,50>,80,75>,BrownNoiseFlicker<GhostWhite, Orange, 50>,650>,300,300,Black>>(), "Bespin"},
   { "Rey", "tracks/rey.wav",
        StylePtr<InOutHelper<Stab<LocalizedClash<Lockup<Blast<AudioFlicker<Rgb<0,64,255>,Rgb<0,32,128>>,Red,200,800,400>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,White>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,BrownNoiseFlicker<GhostWhite,Orange,50>>,BrownNoiseFlicker<GhostWhite,White,50>,80,75>,BrownNoiseFlicker<GhostWhite, Orange, 50>,650>,300,300,Black>>(), "Rey"},
   { "Kguard", "tracks/kylotlj.wav",
    StylePtr<InOutHelper<Stab<Lockup<StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,300>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,Pulsing<Gradient<StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,RandomPerLEDFlicker<White,Strobe<Blue,White,50,1>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,Gradient<StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,RandomPerLEDFlicker<White,Strobe<Blue,White,50,1>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,White,80,50>,White,200,100,400>,Rgb<80,0,0>,0,8,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,3500>,RandomPerLEDFlicker<Red,White>>,RandomPerLEDFlicker<Red, White>, 650>,150,500,Black>>(), "Kguard"},
    { "Father", "tracks/hall.wav",
        StylePtr<InOutHelper<Stab<LocalizedClash<Lockup<Blast<AudioFlicker<Red,Rgb<120,0,0>>,DeepSkyBlue,200,100,400>,Pulsing<Gradient<AudioFlicker<Red,Rgb<120,0,0>>,AudioFlicker<Red,Rgb<120,0,0>>,BrownNoiseFlicker<White,Strobe<SteelBlue,White,50,1>,100>,AudioFlicker<Red,Rgb<120,0,0>>,AudioFlicker<Red,Rgb<120,0,0>>,AudioFlicker<Red,Rgb<120,0,0>>>,Gradient<AudioFlicker<Red,Rgb<120,0,0>>,AudioFlicker<Red,Rgb<120,0,0>>,BrownNoiseFlicker<White,Strobe<SteelBlue,White,50,1>,100>,AudioFlicker<Red,Rgb<120,0,0>>,AudioFlicker<Red,Rgb<120,0,0>>>,3500>,AudioFlicker<Red,White>>,White,80,50>,AudioFlicker<Red,White>, 650>,800,500,Black>>(), "Father"},
    { "Return", "tracks/jaba.wav",
        StylePtr<Stab<InOutHelper<OnSpark<LocalizedClash<Lockup<Blast<AudioFlicker<Green,Rgb<0,200,0>>,White,200,100,400>,Pulsing<Gradient<AudioFlicker<Green,Rgb<0,200,0>>,AudioFlicker<Green,Rgb<0,200,0>>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<Green,Rgb<0,200,0>>,AudioFlicker<Green,Rgb<0,200,0>>,AudioFlicker<Green,Rgb<0,200,0>>>,Gradient<AudioFlicker<Green,Rgb<0,200,0>>,AudioFlicker<Green,Rgb<0,200,0>>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<Green,Rgb<0,200,0>>,AudioFlicker<Green,Rgb<0,200,0>>>,3500>,RandomPerLEDFlicker<White,Green>>,White,50,80>,HumpFlicker<Green,White,40>,800>,RandomPerLEDFlicker<Red, White>, 650>,180,300,Black>>(), "Return"},
    { "Traya", "tracks/traya.wav",
        StylePtr<InOutHelper<Stab<EasyBlade<OnSpark<BrownNoiseFlicker<Strobe<BLACK, Yellow, 50, 1>, Strobe<RED, Black, 50, 1>, 50>>, WHITE>,Strobe<RED, White, 50,1>, 650>, 300, 800>>(), "Traya"},
    { "DrkKyber", "tracks/mars.wav",
        StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<Pulsing<AudioFlicker<Red,Rgb<50,0,0>>,AudioFlicker<Rgb<50,0,0>,Red>,250>,Green>,AudioFlicker<Pulsing<AudioFlicker<Red,Rgb<50,0,0>>,AudioFlicker<Rgb<50,0,0>,Red>,250>,White>>,Green,40>,AudioFlicker<Red, White>, 650>,300,800,Black>>(), "DrkKyber"},
    { "balance", "tracks/revan.wav",
        StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<OnSpark<RandomPerLEDFlicker<Gradient<Green,Coral>,Gradient<Coral,Green>>,Cyan,200>,Blue>,AudioFlicker<OnSpark<RandomPerLEDFlicker<Gradient<Green,Coral>,Gradient<Coral,Green>>,White,200>,Cyan>>,Cyan,40>,AudioFlicker<Green, White>, 650>,500,800,Black>>(), "balance"},
   { "vengence", "tracks/mercury.wav",
    StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Cyan>,AudioFlicker<OnSpark<AudioFlicker<Magenta,Red>,White,200>,Cyan>>,Cyan,40>,AudioFlicker<Magenta, White>, 650>,300,800,Black>>(), "vengence"},
   { "Unstable", "tracks/venus.wav",
    StylePtr<InOutHelperX<Stab<SimpleClash<Lockup<Blast<OnSpark<ColorCycle<Yellow,0,1,AudioFlicker<DarkOrange,Rgb<128,0,0>>,100,3000,800>,White,200>,White>,AudioFlicker<OnSpark<ColorCycle<Yellow,0,1,AudioFlicker<DarkOrange,Rgb<128,0,0>>,100,3000,800>,White,200>,White>>,White>,AudioFlicker<Orange,White>,650>,InOutFuncX<Int<300>,Int<800>>>>(), "Unstable"},
   { "Dark", "tracks/mars.wav",
    StylePtr<InOutHelper<Stab<EasyBlade<OnSpark<BrownNoiseFlicker<GREEN, Blue, 50>>, WHITE>,AudioFlicker<Green, White>, 650>, 300, 800> >(), "Dark"},
   { "Menace", "tracks/mercury.wav",
    StylePtr<ColorCycle<Black,100,1400,ColorCycle<Red,100,1200,ColorCycle<Red,100,4000,ColorCycle<Red,100,8000,ColorCycle<Red,100,1000,Yellow,100,6000,16000>,100,8000,12000>,100,10000,14000>,100,18000,24000>,100,6000,28000>>(), "Menace"},
   { "OB4", "tracks/uranus.wav",
    StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<AudioFlicker<DeepSkyBlue,SteelBlue>,White,200,100,400>,Pulsing<Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,3500>,AudioFlicker<White,DeepSkyBlue>>,White,40>,AudioFlicker<White,DeepSkyBlue>, 650>,180,500,Black>>(), "OB4"},
   { "ANH", "tracks/mars.wav",
    StylePtr<InOutHelper<Stab<SimpleClash<Lockup<Blast<AudioFlicker<DeepSkyBlue,SteelBlue>,White,200,100,400>,Pulsing<Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,Gradient<AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<DeepSkyBlue,SteelBlue>,AudioFlicker<DeepSkyBlue,SteelBlue>>,3500>,AudioFlicker<White,DeepSkyBlue>>,White,40>,AudioFlicker<White,DeepSkyBlue>, 650>,180,500,Black>>(), "ANH"},
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
