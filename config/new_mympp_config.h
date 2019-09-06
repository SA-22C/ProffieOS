#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 150
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define COLOR_A Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,HotPink
#define COLOR_B Rgb<128,0,0>,OrangeRed,Rgb<80,80,50>,Rgb<40,100,40>,Rgb<0,128,0>,Rgb<20,100,60>,SteelBlue,SteelBlue,DodgerBlue,Rgb<60,0,100>,Rgb<80,0,80>,DeepPink
#define FLARES Tomato,Yellow,LightYellow,LightYellow,GreenYellow,Cyan,Aquamarine,SteelBlue,DodgerBlue,LightPink,Pink,Magenta
#define EFFECTS Green,Cyan,Red,Red,Red,LightYellow,LightYellow,LightYellow,LightYellow,Cyan,Cyan,Cyan
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<CCAudio<COLOR_A, COLOR_B, EFFECTS>,300,800>>()
},
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<CCAudioFlare<COLOR_A, COLOR_B, EFFECTS, FLARES>,300,800>>()
},
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(),
},
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<Lockup<EffectScroll<1500,AudioFlicker<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>>,HumpFlicker<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>,20>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>,100>,RandomPerLEDFlicker<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>>,Pulsing<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>,1000>,StyleFire<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>>,Sparkle<AudioFlicker<ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>,AudioFlicker<Gradient<White,ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Red,DarkOrange,Yellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>>,ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>>>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<120,0,0>,Orange,LemonChiffon,Rgb<0,120,0>,Aqua,SteelBlue,DodgerBlue,Rgb<60,8,120>,HotPink,HotPink>,White>>,White>,White>,300,500,Black>>()
},
{ "Light", "tracks/march.wav",
StylePtr<InOutHelper<LocalizedClash<Blast<Lockup<EffectScroll<1500,AudioFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>>,HumpFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>,20>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>,100>,RandomPerLEDFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>>,Pulsing<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>,1000>,StyleFire<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>>,Sparkle<AudioFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>>,White>,StyleFire<Gradient<Red,DarkOrange,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Red>,AudioFlicker<Gradient<White,ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>>,ColorChangeFade<1500,   Blue,Orange,LemonChiffon,Rgb<0,120,0>,Red,Magenta,DodgerBlue>>>,RandomPerLEDFlicker<ColorChangeFade<1500,   Red,Yellow,Green,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta>,White>>,White>,White>,300,500,Black>>()
},
{ "Balance", "tracks/march.wav",
StylePtr<InOutHelper<Blast<LocalizedClash<Lockup<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Pulsing<Gradient<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,Gradient<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,3500>, RandomPerLEDFlicker<Red,White>>,ColorScroll<2000,Blue,White,Red,White,Yellow,Blue,Red,White,White,Red,Blue,White>>,ColorScroll<2000,Blue,White,Red,White,Yellow,Blue,Red,White,White,Red,Blue,White>>,150,500,Black>>()
},
{ "Vengence", "tracks/march.wav",
StylePtr<InOutHelper<Blast<LocalizedClash<Lockup<AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Pulsing<Gradient<AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,Gradient<AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorChangeFade<1500,   Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,3500>, RandomPerLEDFlicker<Red,White>>,ColorChangeFade<1500,   Blue,White,Red,White,Yellow,Blue,Red,White,White,Red,Blue,White>>,ColorChangeFade<1500,   Blue,White,Red,White,Yellow,Blue,Red,White,White,Red,Blue,White>>,150,500,Black>>()
},
{ "Traya", "tracks/march.wav",
StylePtr<InOutHelper<Lockup<StyleFire<Blast<LocalizedClash<BrownNoiseFlicker<ColorChangeFade<1500,   ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,White,80,50>,White,200,100,400>,ColorChangeFade<1500,   Rgb<80,0,0>,Rgb<80,15,0>,Rgb<80,25,0>,Rgb<15,80,0>,Rgb<0,80,0>,Rgb<0,80,15>,Rgb<0,15,80>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,100>,Rgb<40,0,40>,Rgb<80,0,15>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,StyleFire<Pulsing<Gradient<BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,RandomPerLEDFlicker<White,Strobe<Blue,White,50,1>>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>>,Gradient<BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,RandomPerLEDFlicker<White,Strobe<Blue,White,50,1>>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>>,3500>,ColorChangeFade<1500,   Rgb<80,0,0>,Rgb<80,15,0>,Rgb<80,25,0>,Rgb<15,80,0>,Rgb<0,80,0>,Rgb<0,80,15>,Rgb<0,15,80>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,100>,Rgb<40,0,40>,Rgb<80,0,15>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,RandomPerLEDFlicker<White,ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>>,StyleFire<Pulsing<Gradient<BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>>,Pulsing<Gradient<BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>>,Gradient<BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,Strobe<White,RandomPerLEDFlicker<White,DeepSkyBlue>,15,3>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>,BrownNoiseFlicker<ColorChangeFade<1500,   Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,RandomPerLEDFlicker<ColorChangeFade<1500,   Rgb<25,0,0>,OrangeRed,Orange,Rgb<0,25,0>,Rgb<0,25,0>,Rgb<0,25,0>,DeepSkyBlue,SteelBlue,Rgb<0,0,25>,Rgb<10,0,25>,Rgb<10,0,25>,Rgb<25,0,0>>,ColorChangeFade<1500,   Rgb<60,0,0>,Rgb<60,10,0>,Rgb<60,20,0>,Rgb<10,60,0>,Rgb<0,60,0>,Rgb<0,60,10>,Rgb<0,10,60>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,0,10>>>,200>>,1500>,2000>,ColorChangeFade<1500,   Rgb<80,0,0>,Rgb<80,15,0>,Rgb<80,25,0>,Rgb<15,80,0>,Rgb<0,80,0>,Rgb<0,80,15>,Rgb<0,15,80>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,100>,Rgb<40,0,40>,Rgb<80,0,15>>,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,150,500,Black>>()
},
{ "Graflex8", "tracks/march.wav",
StylePtr<InOutHelper<Blast<LocalizedClash<Lockup<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Pulsing<Gradient<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,Gradient<AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, Strobe<White, BrownNoiseFlicker<Red,White,100>,50,1>,AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>, AudioFlicker<ColorScroll<2000,Red,Orange,Yellow,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<125,30,255>,Magenta,DeepPink>,ColorScroll<2000,Rgb<100,0,0>,Rgb<0,100,0>,Rgb<0,0,100>>>>,3500>, RandomPerLEDFlicker<Red,White>>,ColorScroll<2000,Blue,White,Red,White,White,Blue,Red,White,White,Red,Blue,White>>,ColorScroll<2000,Blue,White,Red,White,White,Blue,Red,White,White,Red,Blue,White>>,150,500,Black>>()
},
{ "Kguard", "tracks/march.wav",
StylePtr<InOutHelper<ColorScroll<1000,AudioFlicker<Red, Rgb<100,0,0>>,AudioFlicker<DarkOrange, Orange>,AudioFlicker<Yellow, Bisque>,AudioFlicker<GreenYellow, Rgb<0,100,0>>,AudioFlicker<Green, Rgb<0,100,0>>,AudioFlicker<Cyan, DeepSkyBlue>,AudioFlicker<DodgerBlue, SteelBlue>,AudioFlicker<Blue, SteelBlue>,AudioFlicker<Rgb<100,0,220>, Rgb<60,0,180>>,AudioFlicker<Magenta, DeepPink>>,200,300,Black>>()
},
{ "SAVANT", "tracks/march.wav",
StylePtr<InOutHelper<ColorScroll<2000,AudioFlicker<Red,Rgb<100,0,0>>,StyleFire<Gradient<Red,Orange,Yellow,Green,Blue,Rgb<125,30,255>>,Red,0,4>,Pulsing<Blue,Green,200>,RandomFlicker<Blue,DeepSkyBlue>,RandomPerLEDFlicker<Green,Yellow>,Stripes<1000,1000,Blue,Red,Green,Magenta>>,150,300,Black>>()
},
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<130, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif