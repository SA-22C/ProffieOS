#ifdef CONFIG_TOP

#include "proffieboard_v1_config.h"

#define NUM_BLADES 1

#define NUM_BUTTONS 2

#define VOLUME 1700

const unsigned int maxLedsPerStrip = 144;

#define CLASH_THRESHOLD_G 1.0

#define ENABLE_AUDIO

#define ENABLE_MOTION

#define ENABLE_WS2811

#define ENABLE_SD

#define

#endif


#ifdef CONFIG_PRESETS

Preset presets[] = {



	{ "RETURN", "tracks/heros.wav",


	StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,
Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,
Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,
Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,
Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/heros.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<AliceBlue,Azure>,AudioFlicker<LightCyan,Azure>,
AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,
Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<AliceBlue,Azure>,
HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,
HumpFlicker<LightCyan,Azure,50>>,Gradient<AudioFlicker<AliceBlue,Azure>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,
Azure,50>,HumpFlicker<LightCyan,Azure,50>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,
HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>,HumpFlicker<LightCyan,Azure,50>>,3500>,Gradient<AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,
AudioFlicker<LightCyan,Azure>,Gradient<AudioFlicker<LightCyan,Azure>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,AudioFlicker<LightCyan,Azure>,
Gradient<AudioFlicker<LightCyan,Azure>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "white"},


	{ "RETURN", "tracks/temple.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,
Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,
Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,
200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/ambience.wav",
   StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/lvsv.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,
Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,
1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/woods.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,
Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/heros.wav",
   StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,
Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,
Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/heros.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Pink,Rgb<120,20,235>>,AudioFlicker<Rgb<120,20,235>,
Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,
AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,
Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>>,BrownNoiseFlicker<Green,Yellow,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Pink,Rgb<120,20,235>>,
HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,
HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>>,
Gradient<AudioFlicker<Pink,Rgb<120,20,235>>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,
Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>,
HumpFlicker<Rgb<120,20,235>,Rgb<60,10,170>,50>>,3500>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,
AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,
AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,Gradient<AudioFlicker<Rgb<120,20,235>,Rgb<60,10,170>>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>,1400>,
White,200>,200,300,Black>>(), "purple"},


	{ "RETURN", "tracks/ftheme.wav",
  StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,
BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,
LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,
Rgb<0,0,150>,50>>,3500>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,
Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/fates.wav",
  StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "Blue"},


	{ "RETURN", "tracks/naboo.wav",

StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Rgb<125,255,125>,GreenYellow>,
AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,
AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>>,
BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,Pulsing<Gradient<AudioFlicker<Rgb<125,255,125>,GreenYellow>,HumpFlicker<Green,GreenYellow,50>,
HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>,
HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>>,Gradient<AudioFlicker<Rgb<125,255,125>,GreenYellow>,HumpFlicker<Green,GreenYellow,50>,
HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>,HumpFlicker<Green,GreenYellow,50>>,3500>,
Gradient<AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,Gradient<AudioFlicker<Green,GreenYellow>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,50>,100,50>,
Gradient<AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,Gradient<AudioFlicker<Green,GreenYellow>,
BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "green"},


	{ "RETURN", "tracks/woods.wav",
 StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "RETURN", "tracks/camp.wav",
  StylePtr<InOutHelper<OnSpark<Stab<LocalizedClash<Lockup<Blast<Gradient<AudioFlicker<Cyan,Blue>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,
AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>>,BrownNoiseFlicker<Red,Magenta,300>,150,200,600>,
Pulsing<Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,Gradient<AudioFlicker<Cyan,Blue>,HumpFlicker<Blue,Rgb<0,0,150>,50>,
HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>,HumpFlicker<Blue,Rgb<0,0,150>,50>>,3500>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,50>,100,50>,
Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,
BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,1400>,White,200>,200,300,Black>>(), "blue"},


	{ "SmthGrey", "tracks/mercury.wav",
    StyleFirePtr<RED, YELLOW>(), "fire"},


	{ "SmthFuzz", "tracks/uranus.wav",
    StyleNormalPtr<RED, WHITE, 300, 800>(), "red"},


	{ "RgueCmdr", "tracks/venus.wav",
    StyleFirePtr<BLUE, CYAN>(), "blue fire"},


	{ "SmthJedi", "tracks/uranus.wav",
    StyleNormalPtr<AudioFlicker<YELLOW, WHITE>, BLUE, 300, 800>(), "yellow"},


	{ "SmthGrey", "tracks/venus.wav",
    StylePtr<InOutSparkTip<EASYBLADE(MAGENTA, WHITE), 300, 800> >(), "magenta"},


	{ "SmthFuzz", "tracks/mars.wav",
    StyleNormalPtr<Gradient<RED, BLUE>, Gradient<CYAN, YELLOW>, 300, 800>(), "gradient"},


	{ "RgueCmdr", "tracks/mercury.wav",
    StyleRainbowPtr<300, 800>(), "rainbow"},


	{ "SmthJedi", "tracks/uranus.wav",
    StyleNormalPtr<Gradient<GREEN, BLUE>, Gradient<CYAN, YELLOW>, 300, 800>(), "gradient"},


	{ "TthCrstl", "tracks/uranus.wav",
    StyleStrobePtr<WHITE, Rainbow, 15, 300, 800>(), "strobe"},


	{ "TthCrstl", "tracks/uranus.wav",
    StyleNormalPtr<Orange, WHITE, 300, 800>(), "Orange"},


   	{ "TeensySF", "tracks/venus.wav",
    StyleNormalPtr<CYAN, WHITE, 300, 800>(), "cyan"},


	{ "TeensySF", "tracks/venus.wav",
    &style_pov, "POV"},


	{ "SmthJedi", "tracks/mars.wav",
    &style_charging, "Battery\nLevel"},


};

BladeConfig blades[] = {

{ 0, WS2811BladePtr<144, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },

};

#endif



#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif
