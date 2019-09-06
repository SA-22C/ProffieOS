#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define NO_COLOR_SWING
#define NO_LOCKUP_HOLD
#define SWAP_LOCKUP
#define NO_SAVED_PRESET
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<CCUnstable<Red, Rgb<128,0,0>,Blue,OrangeRed,Rgb<128,27,0>,Blue,Orange,Rgb<128,82,0>,Blue,Yellow,Rgb<128,128,0>,Cyan,GreenYellow,Rgb<86,128,23>,Cyan,Green,Rgb<0,128,0>,Red,Cyan, Rgb<0,128,128>,Red,DeepSkyBlue,Rgb<0,95,128>,Magenta,Blue,Rgb<0,0,128>,Magenta,Magenta,Rgb<128,0,128>,Cyan,DeepPink,Rgb<128,10,74>,Red,Rgb<238,130,238>,Rgb<119,65,119>,Cyan>,180,500>>()
},
{ "R1Vader", "tracks/march.wav",
StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(),
},
{ "Balance", "tracks/rots.wav",
StylePtr<InOutHelper<CCAudio<Red, Rgb<128,0,0>,Blue,OrangeRed,Rgb<128,27,0>,Blue,Orange,Rgb<128,82,0>,Blue,Yellow,Rgb<128,128,0>,Cyan,GreenYellow,Rgb<86,128,23>,Cyan,Green,Rgb<0,128,0>,Red,Cyan, Rgb<0,128,128>,Red,DeepSkyBlue,Rgb<0,95,128>,Magenta,Blue,Rgb<0,0,128>,Magenta,Magenta,Rgb<128,0,128>,Cyan,DeepPink,Rgb<128,10,74>,Red,Rgb<238,130,238>,Rgb<119,65,119>,Cyan>,180,500>>()
},
{ "Vengence", "tracks/rots.wav",
StylePtr<InOutHelper<CCAudioFlare<Red, Rgb<128,0,0>,Blue,OrangeRed,Rgb<128,27,0>,Blue,Orange,Rgb<128,82,0>,Blue,Yellow,Rgb<128,128,0>,Cyan,GreenYellow,Rgb<86,128,23>,Cyan,Green,Rgb<0,128,0>,Red,Cyan, Rgb<0,128,128>,Red,DeepSkyBlue,Rgb<0,95,128>,Magenta,Blue,Rgb<0,0,128>,Magenta,Magenta,Rgb<128,0,128>,Cyan,DeepPink,Rgb<128,10,74>,Red,Rgb<238,130,238>,Rgb<119,65,119>,Cyan>,180,500>>()
},
{ "Light", "tracks/rots.wav",
StylePtr<InOutHelper<CCUnstableFlare<Red, Black,Blue,OrangeRed,Black,Blue,Orange,Black,Blue,Yellow,Black,Cyan,GreenYellow,Black,Cyan,Green,Black,Red,Cyan, Black,Red,DeepSkyBlue,Black,Magenta,Blue,Black,Magenta,Magenta,Rgb<128,0,128>,Cyan,DeepPink,Black,Red,Rgb<238,130,238>,Black,Cyan>,180,500>>()
},
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<130, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
