#ifndef STYLES_TEMPLATES_H
#define STYLES_TEMPLATES_H
#define MAINCOLORTEMPLATE ColorChange< main1, main2, main3, main4, main5, main6, main7, main8, main9, main10, main11, main12>
#define FLICKERCOLORTEMPLATE ColorChange< flicker1, flicker2, flicker3, flicker4, flicker5, flicker6, flicker7, flicker8, flicker9, flicker10, flicker11, flicker12>
#define ACOLORTEMPLATE ColorChange<a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12>
#define BCOLORTEMPLATE ColorChange<b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12>
#define CCOLORTEMPLATE ColorChange<c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12>
#define LOCKUPCOLORTEMPLATE ColorChange< lockup1, lockup2, lockup3, lockup4, lockup5, lockup6, lockup7, lockup8, lockup9, lockup10, lockup11, lockup12>
#define CLASHCOLORTEMPLATE ColorChange< clash1, clash2, clash3, clash4, clash5, clash6, clash7, clash8, clash9, clash10, clash11, clash12>
#define BLASTCOLORTEMPLATE ColorChange< effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8, effect9, effect10, effect11, effect12>
#define STABCOLORTEMPLATE ColorChange<stab1,stab2,stab3,stab4,stab5,stab6,stab7,stab8,stab9,stab10,stab11,stab12>
#define DRAGCOLORTEMPLATE ColorChange< drag1,drag2,drag3,drag4,drag5,drag6,drag7,drag8,drag9,drag10,drag11,drag12>
#define FLARECOLORTEMPLATE ColorChange< flare1, flare2, flare3, flare4, flare5, flare6, flare7, flare8, flare9, flare10, flare11, flare12>

// List of templated CC and CS styles
template<class main1, class main2, class main3, class main4, class main5, class main6, class main7, class main8, class main9, class main10, class main11, class main12, class flicker1, class flicker2, class flicker3, class flicker4, class flicker5, class flicker6, class flicker7, class flicker8, class flicker9, class flicker10, class flicker11, class flicker12, class lockup1, class lockup2, class lockup3, class lockup4, class lockup5, class lockup6, class lockup7, class lockup8, class lockup9, class lockup10, class lockup11, class lockup12, class clash1=White, class clash2=White, class clash3=White, class clash4=White, class clash5=White, class clash6=White, class clash7=White, class clash8=White, class clash9=White, class clash10=White, class clash11=White, class clash12=White, class drag1=White, class drag2=White, class drag3=White, class drag4=White, class drag5=White, class drag6=White, class drag7=White, class drag8=White, class drag9=White, class drag10=White, class drag11=White, class drag12=White, class stab1=White, class stab2=White, class stab3=White, class stab4=White, class stab5=White, class stab6=White, class stab7=White, class stab8=White, class stab9=White, class stab10=White, class stab11=White, class stab12=White, class effect1=White, class effect2=White, class effect3=White, class effect4=White, class effect5=White, class effect6=White, class effect7=White, class effect8=White, class effect9=White, class effect10=White, class effect11=White, class effect12=White>

using CCAudio = Stab<LocalizedLockup<Blast<LocalizedClash<AudioFlicker<MAINCOLORTEMPLATE,FLICKERCOLORTEMPLATE>,CLASHCOLORTEMPLATE>,BLASTCOLORTEMPLATE>,Strobe<White,RandomPerLEDFlicker<LOCKUPCOLORTEMPLATE,White>,50,1>,RandomPerLEDFlicker<DRAGCOLORTEMPLATE,MAINCOLORTEMPLATE>,Pulsing<Pulsing<Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,MAINCOLORTEMPLATE,300>,Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,2000>,200,40,60,20>,RandomPerLEDFlicker<MAINCOLORTEMPLATE, RandomPerLEDFlicker<MAINCOLORTEMPLATE,STABCOLORTEMPLATE>>, 500>;

template<class main1, class main2, class main3, class main4, class main5, class main6, class main7, class main8, class main9, class main10, class main11, class main12, class flicker1, class flicker2, class flicker3, class flicker4, class flicker5, class flicker6, class flicker7, class flicker8, class flicker9, class flicker10, class flicker11, class flicker12, class lockup1, class lockup2, class lockup3, class lockup4, class lockup5, class lockup6, class lockup7, class lockup8, class lockup9, class lockup10, class lockup11, class lockup12, class clash1=White, class clash2=White, class clash3=White, class clash4=White, class clash5=White, class clash6=White, class clash7=White, class clash8=White, class clash9=White, class clash10=White, class clash11=White, class clash12=White, class drag1=White, class drag2=White, class drag3=White, class drag4=White, class drag5=White, class drag6=White, class drag7=White, class drag8=White, class drag9=White, class drag10=White, class drag11=White, class drag12=White, class stab1=White, class stab2=White, class stab3=White, class stab4=White, class stab5=White, class stab6=White, class stab7=White, class stab8=White, class stab9=White, class stab10=White, class stab11=White, class stab12=White, class effect1=White, class effect2=White, class effect3=White, class effect4=White, class effect5=White, class effect6=White, class effect7=White, class effect8=White, class effect9=White, class effect10=White, class effect11=White, class effect12=White, class flare1=White, class flare2=White, class flare3=White, class flare4=White, class flare5=White, class flare6=White, class flare7=White, class flare8=White, class flare9=White, class flare10=White, class flare11=White, class flare12=White>

using CCAudioFlare = Stab<LocalizedLockup<Blast<LocalizedClash<Flare<AudioFlicker<MAINCOLORTEMPLATE,FLICKERCOLORTEMPLATE>,RandomFlicker<MAINCOLORTEMPLATE,FLARECOLORTEMPLATE>,25>,CLASHCOLORTEMPLATE>,BLASTCOLORTEMPLATE>,Strobe<White,RandomPerLEDFlicker<LOCKUPCOLORTEMPLATE,White>,50,1>,RandomPerLEDFlicker<DRAGCOLORTEMPLATE,MAINCOLORTEMPLATE>,Pulsing<Pulsing<Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,MAINCOLORTEMPLATE,300>,Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,2000>,200,40,60,20>,RandomPerLEDFlicker<MAINCOLORTEMPLATE, STABCOLORTEMPLATE>, 500>;

template<class main1, class main2, class main3, class main4, class main5, class main6, class main7, class main8, class main9, class main10, class main11, class main12, class a1,class a2, class a3, class a4, class a5, class a6, class a7, class a8, class a9, class a10, class a11, class a12, class b1,class b2,class b3, class b4, class b5, class b6, class b7, class b8, class b9, class b10, class b11, class b12, class c1, class c2, class c3, class c4, class c5, class c6, class c7, class c8, class c9, class c10, class c11, class c12, class lockup1, class lockup2, class lockup3, class lockup4, class lockup5, class lockup6, class lockup7, class lockup8, class lockup9, class lockup10, class lockup11, class lockup12, class clash1=White, class clash2=White, class clash3=White, class clash4=White, class clash5=White, class clash6=White, class clash7=White, class clash8=White, class clash9=White, class clash10=White, class clash11=White, class clash12=White, class drag1=White, class drag2=White, class drag3=White, class drag4=White, class drag5=White, class drag6=White, class drag7=White, class drag8=White, class drag9=White, class drag10=White, class drag11=White, class drag12=White, class stab1=White, class stab2=White, class stab3=White, class stab4=White, class stab5=White, class stab6=White, class stab7=White, class stab8=White, class stab9=White, class stab10=White, class stab11=White, class stab12=White, class effect1=White, class effect2=White, class effect3=White, class effect4=White, class effect5=White, class effect6=White, class effect7=White, class effect8=White, class effect9=White, class effect10=White, class effect11=White, class effect12=White>

using CCUnstable = Stab<LocalizedClash<Blast<LocalizedLockup<StyleFire<BrownNoiseFlicker<MAINCOLORTEMPLATE,RandomPerLEDFlicker<ACOLORTEMPLATE,BCOLORTEMPLATE>,200>,CCOLORTEMPLATE,0,6,FireConfig<10,1000,2>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,Strobe<White,RandomPerLEDFlicker<LOCKUPCOLORTEMPLATE,White>,50,1>,RandomPerLEDFlicker<DRAGCOLORTEMPLATE,MAINCOLORTEMPLATE>,Pulsing<Pulsing<Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,MAINCOLORTEMPLATE,300>,Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,2000>,200,40>,BLASTCOLORTEMPLATE>,CLASHCOLORTEMPLATE>,RandomPerLEDFlicker<STABCOLORTEMPLATE,MAINCOLORTEMPLATE>>;

template<class main1, class main2, class main3, class main4, class main5, class main6, class main7, class main8, class main9, class main10, class main11, class main12, class flicker1, class flicker2, class flicker3, class flicker4, class flicker5, class flicker6, class flicker7, class flicker8, class flicker9, class flicker10, class flicker11, class flicker12, class lockup1, class lockup2, class lockup3, class lockup4, class lockup5, class lockup6, class lockup7, class lockup8, class lockup9, class lockup10, class lockup11, class lockup12, class clash1=White, class clash2=White, class clash3=White, class clash4=White, class clash5=White, class clash6=White, class clash7=White, class clash8=White, class clash9=White, class clash10=White, class clash11=White, class clash12=White, class drag1=White, class drag2=White, class drag3=White, class drag4=White, class drag5=White, class drag6=White, class drag7=White, class drag8=White, class drag9=White, class drag10=White, class drag11=White, class drag12=White, class stab1=White, class stab2=White, class stab3=White, class stab4=White, class stab5=White, class stab6=White, class stab7=White, class stab8=White, class stab9=White, class stab10=White, class stab11=White, class stab12=White, class effect1=White, class effect2=White, class effect3=White, class effect4=White, class effect5=White, class effect6=White, class effect7=White, class effect8=White, class effect9=White, class effect10=White, class effect11=White, class effect12=White, class flare1=White, class flare2=White, class flare3=White, class flare4=White, class flare5=White, class flare6=White, class flare7=White, class flare8=White, class flare9=White, class flare10=White, class flare11=White, class flare12=White>
using CCUnstableFlare = Stab<LocalizedClash<Blast<LocalizedLockup<Flare<RandomPerLEDFlicker<Black,BrownNoiseFlicker<MAINCOLORTEMPLATE, FLICKERCOLORTEMPLATE,50>>,RandomFlicker<MAINCOLORTEMPLATE,FLARECOLORTEMPLATE>,25>,Strobe<White,RandomPerLEDFlicker<LOCKUPCOLORTEMPLATE,White>,50,1>,RandomPerLEDFlicker<DRAGCOLORTEMPLATE,MAINCOLORTEMPLATE>,Pulsing<Pulsing<Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,MAINCOLORTEMPLATE,300>,Gradient<MAINCOLORTEMPLATE,Strobe<White,RandomPerLEDFlicker<Blue,White>,50,5>,MAINCOLORTEMPLATE>,2000>,200,40>,BLASTCOLORTEMPLATE>,CLASHCOLORTEMPLATE>,RandomPerLEDFlicker<STABCOLORTEMPLATE,MAINCOLORTEMPLATE>>;
#endif