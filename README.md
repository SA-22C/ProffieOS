# ProffieOS - SA-22C Fork

The open source operating system. Proffie OS is supported on various platforms ranging from Teensy 3.2 development boards to its own dedicated ProffieBoard reference hardware.

Proffie OS supports:
- :fire: SmoothSwing V1/V2 Algorithm
- :fire: NEC styled lightsaber sound fonts (polyphonic)
- :fire: Plecter styled lightsaber sound fonts ( monophonic)
- :fire: Driving Adressable LED strips
- :fire: Driving Segmented LED strips
- :fire: Quad/Tri LED stars.

### Getting started  
* Github Wiki: https://github.com/profezzorn/ProffieOS/wiki
* ProffieOS: https://fredrik.hubbe.net/lightsaber/proffieos.html
* Proffieboard: https://fredrik.hubbe.net/lightsaber/v4/
* TeensySaber: http://fredrik.hubbe.net/lightsaber/v3/
* Support forum: http://imperialroyalarms.com/board/97/profezzorns-lab

### SA-22C Features
* Color/Effect Change On-The-Fly, by Fernando Darosa  
* Saber save state - saber remembers last activated preset and volume level and resumes after sleep/power cut.
* Plecter fonts - spin and stab effects
* NEC fonts - slsh effects
* Smooth Swing V2.1 - Accent effects - spin, swng, slsh, stab layered over the high/low swing pairs
* CFX Smooth Swing Fonts - automatically detect and activate in hybrid mode, no file renames required.
* Volume control on the fly
* Stab blade effect
* spoken battery command
* 1/2/3 button mods
* button mash control - no false triggers of button holds while rapidly pressing buttons

## Color / Effect Change Functionality
### How color/effect change works:
There are multiple style options but they all operate on the same principal, you can build a list (array) of the color or effects within the style, the first option in each is your "default".  Every action will progress to the next in the list until the end is reached, then it will cycle back to beginning, just like presets.
For example: 

* AudioFlicker<ColorChange<Red,Green,Blue>,ColorChange<Rgb<128,0,0>,Rgb<0,128,0>,Rgb<0,0,128>>>

In the above style default is  AudioFlicker<Red, Rgb<128,0,0>>

the first change then makes the style  AudioFlicker<Green,Rgb<0,128,0>

the next would make it  AudioFlicker<Blue,Rgb<0,0,128>>

and another would return to AudioFlicker<Red, Rgb<128,0,0>>

and so on and so forth.  You are not limited in the number of colors you can have in a ColorChange<> or how many ColorChange<> lists you include in a style.  You can also have different number of colors in each list but it will create random results as you progress since each change goes to next in list no matter the number.  
## Functions
There are mutliple new styles that run color/effect change in this fork.  There are two functions available; on-the-fly and scroll/select.  You can use either or both to enable color/effect change.  
### "On-the-fly"
"On-the-fly" - ColorChange<>, ColorChangeFade<> and ColorScroll<>* all feature immediate color change (using either click-to-change or swing-to-change depending on the button selection in your config/saber.h file.  Both control options will change the color or effect once per button press or swing (swing-to-change uses a menu system which you must enter to enable and exit to disable for normal operation).

*ColorScroll<> has both "on-the-fly" and "scroll/select" functionality for the list items so you can use both methods to run through all of the items in the list.

The styles themselves can be used for color or effects or both, they are not limited.  So even within ColorChange<> you can build different color/effect mixes:

### For example:
* ColorChange<AudioFlicker<DeepSkyBlue,SteelBlue>,BrownNoiseFlicker<Red,Rgb<80,0,0>,200>,StyleFire<Green,Rgb<0,80,0>>> contains three different effects and colors and each change will go through the list. 

Default is AudioFlicker<DeepSkyBlue,SteelBlue>,

first change then will be BrownNoiseFlicker<Red,Rgb<80,0,0>,200>,

next change will be StyleFire<Green,Rgb<0,80,0>>.

As with colors you are not limited on the number of effects you can have in your list.
### "Scroll / Select"
"Scroll / Select" - EffectScroll<> and ColorScroll<>* feature a scroll mode (can also be used as Demo Mode) that is activated and will scroll through all colors/effects in your list until you "Select" (exit).  There is a Display Time parameter (ms) defined in the style that controls how long each color/effect in the list is displayed before the next is shown.  Scroll mode will run continuously until you "Select" a color/effect.
*ColorScroll<> has both "on-the-fly" and "scroll/select" functionality for the list items so you can use both methods to run through all of the items in the list.
For example:
* EffectScroll<2000,AudioFlicker<Red,Rgb<128,0,0>>,BrownNoiseFlicker<Red,Rgb<80,0,0>,200>,StyleFire<Red,Rgb<80,0,0>>>
When scroll mode is activated it will display each AudioFlicker, BrownNoiseFlicker, StyleFire for 2000 ms and then move to the next until you "select" one.  You can enter scroll mode as often as you like and make selections.
There are different controls for activating Scroll Mode and Selecting depending on your config or saber.h set up.
### Dual Change Styles
By combining ColorChange<> or ColorChangeFade<> with EffectScroll<> you can build a dual change style.  This enables you to build list(s) of colors or effects that are changed with "on-the-fly" controls and a separate list(s) of colors or effects that are changed with "scroll/select".  Just as above, you are not limited to colors or effects or the number of either in your lists.
### For example:
* EffectScroll<1500,AudioFlicker<ColorChange<Red,Green,Blue>,ColorChange<Rgb<128,0,0>,Rgb<0,128,0>,Rgb<0,0,128>>>,StyleFire<ColorChange<Red,Green,Blue>,ColorChange<Rgb<128,0,0>,Rgb<0,128,0>,Rgb<0,0,128>>>,Pulsing<ColorChange<Red,Green,Blue>,ColorChange<Rgb<128,0,0>,Rgb<0,128,0>,Rgb<0,0,128>>,800>>

In this style there are two things that will happen, separately.
EffectScroll<> will advance the AudioFlicker<>, StyleFire<> and Pulsing<> styles at a 1500 ms display time when scroll mode is activated until an effect is selected.  The colors within ColorChange<> will remain unchanged unless the "on-the-fly" control is used. 

ColorChange<> will advance the colors within each "on-the-fly" change without affecting the effects in EffectScroll<> so you can step through the colors with the "on-the-fly" control within the current effect selected from "scroll/select".

 Since the controls are separate you can use "on-the-fly" while the scroll mode is active so you can have the effects changing every 1500 ms (above) but also change your colors at the same time with the "on-the-fly" control.  You can also "select" an effect from scroll mode and then change your colors "on-the-fly" or select a color with "on-the-fly" and then activate "scroll/select" to choose the effect.
 
Lastly, you can mix and match however you like for some truly unique blade styles and changes.

### For example:
* Gradient<EffectScroll<1000,AudioFlicker<White,Red>,AudioFlicker<White,Green>,AudioFlicker<White,Blue>>,AudioFlicker<ColorChange<Red,Green,Blue>,ColorChange<Rgb<128,0,0>,Rgb<0,128,0>,Rgb<0,0,128>>>>

will create a blade where the bottom half of the blade is changed using "scroll/select" while the top half of the blade is changed with "on-the-fly".  With 3 colors/effects in both lists, you can run through 9 blade results.  And as always, you're not limited in the number of either effect you include in a style or the number of colors or effects you have in each list so you can develop as many as you like.

### Simple implementation:
In addition to the style library and the Easy templates available, any existing blade style can be made into a color/effect change style following the below approach.

Say I have a style AudioFlicker<DeepSkyBlue, White>, I can enable color change in either or both instances of the colors.  Since the color/effects all advance by one with each change you will want to "plan" out your color options.

First build ColorA's list:

ColorA = ColorChangeFade<400,DeepSkyBlue,Red,Green,Yellow>

then build ColorB's list (you will want each location to line up (or not if you want different mixes).

ColorB = ColorChangeFade<400,SteelBlue,Rgb<128,0,0>,Rgb<0,128,0>,LemonChiffon>

now we go back to the style itself and we will replace DeepSkyBlue with the ColorA list we created and SteelBlue with the ColorB list we created to end up with:

* AudioFlicker<ColorChangeFade<400,DeepSkyBlue,Red,Green,Yellow>,ColorChangeFade<400,SteelBlue,Rgb<128,0,0>,Rgb<0,128,0>,LemonChiffon>>

and now we have our DeepSkyBlue/SteelBlue blade as default and then we advance the colors with each "on-the-fly" change.
Current Styles

- 1 ColorChange<COLORS...> =  List as many colors (or effects) within the style and advance through list using "on-the-fly" change.  Example =  ColorChange<Red,Orange,Yellow,Green,DeepSkyBlue,Blue,Pink,Magenta>
- 2 ColorChangeFade<TRANSITION (ms), COLORS...> =  List as many colors (or effects) within the style and advance through list using "on-the-fly" change. Each color will fade into the next over the TRANSITION TIME (ms). Example =  ColorChange<400,Red,Orange,Yellow,Green,DeepSkyBlue,Blue,Pink,Magenta> (fade will take 400ms per color)
- 3 EffectScroll<DISPLAY (ms), COLORS...> =  List as many colors (or effects) within the style and advance through list using "scroll/select". To change colors/effects activate "Scroll Mode" and continously advance through the list with each item showing for DISPLAY (ms) until you "Select".  Shorter display times will act as a quick menu, longer display times will allow the Scroll Mode to act like a DEMO Mode, which can be entered or exited at will.
- 4 ColorScroll<DISPLAY (ms), COLORS...> =  List as many colors (or effects) within the style and advance through list using "on-the-fly" change OR "scroll/select".  Each "on-the-fly" change will advance through the list one at a time OR activate "Scroll Mode" and continuously advance through the list with each item showing for DISPLAY (ms) until you "Select".  Shorter display times will act as a quick menu, longer display times will allow the Scroll Mode to act like a DEMO Mode, which can be entered or exited at will.


### Color Change Templates

To make the transition to color change easier, we have provided four templates:

* CCAudio - Audio flicker, localized lockup, clash, lightning block, stab
* CCAudioFlare - Audio flicker, localized lockup, clash, lightning block, stab, base flare
* CCUnstable - Unstable blade, localized lockup, clash, lightning block, stab
* CCUnstableFlare - Unstable blade, localized lockup, clash, lightning block, stab, base flare

Each template has 12 color change variations, and can take in color change parameters for the base color, flicker color, lockup, drag, stab, clash, blast and flare.

So, as an example, here is a 12 color Audio Flicker:

* StylePtr<InOutHelper<CCAudio<Red,OrangeRed,Orange,Yellow,GreenYellow,Green,Cyan,DeepSkyBlue,SteelBlue,Blue,Magenta,Pink, Rgb<128,0,0>,Rgb<128,34,0>,Rgb<128,82,0>,Rgb<128,128,0>,Rgb<0,87,128>,Rgb<0,128,0>,Rgb<0,128,128>,Rgb<0,95,128>,Rgb<35,65,90>,Rgb<0,0,128>,Rgb<128,0,128>,Rgb<128,96,101>, Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan>,180,500>>(),

So the only arguments to the CC templates are the colors.  All other parameters are stored in templates.h.  The arguments are broken up into groups of 12, so 12 base colors, 12 flicker colors, 12 lockup colors, etc.  Because of the way that templates work, you need to specify all 12 of each color (base, flicker, lockup, etc) before moving to the next effect.  By default, stab, drag, clash, blast and flare are all set to white, so if you don’t want to alter those settings, you only need to input 12 colors for base, flicker and lockup for a template to function.

As a shorthand for the CC styles, you could do something like this in your config file.

- #define SET1MAIN Red,OrangeRed,Orange,Yellow,GreenYellow,Green,Cyan,DeepSkyBlue,SteelBlue,Blue,Magenta,Pink
- #define SET1FLICKER Rgb<128,0,0>,Rgb<128,34,0>,Rgb<128,82,0>,Rgb<128,128,0>,Rgb<0,87,128>,Rgb<0,128,0>,Rgb<0,128,128>,Rgb<0,95,128>,Rgb<35,65,90>,Rgb<0,0,128>,Rgb<128,0,128>,Rgb<128,96,101>
- #define SET1LOCKUP Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
- #define SET1DRAG Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
- #define SET1STAB Blue,Blue,Blue,Red,Red,Red,Red,Red,Red,Red,Cyan,Cyan
- #define SET1CLASH White,White,White,White,White,White,White,White,White,White,White,White
- #define SET1BLAST White,White,White,White,White,White,White,White,White,White,White,White
- #define SET1FLARE White,White,White,White,White,White,White,White,White,White,White,White

Then define the CCAudio template like this:
StylePtr<InOutHelper<CCAudio<SET1MAIN,SET1FLICKER,SET1LOCKUP,SET1DRAG,SET1STAB,SET1CLASH,SET1BLAST>,180,500>>(),

In this way, you can define your colors in groups and then add the group names to the templates.  THIS IS ONLY VALID for the CC templates but can make editing color groups easier to manage.  If you want to define different color sets, simply name them SET2, SET3, etc.

For the more complex scrolling styles, there are too many variations to easily template out but a library of styles will be provided by Fernando Darosa (Fett263) for easy cut/paste into your config file.

## Config File Options

In this release, we’ve created several customization options that can be used to tune your saber experience.


### Buttons

### 1 Button Operation:
- Enter Color Change + Scroll (if available in your current style) Twist + Pow
- Change colors - Swing
- Exit Color Change + Scroll: Twist + Pow

For a one-button saber, both color change and scroll mode has been condensed to a single motion.  To enter the change mode, simply twist the saber while holding down power.  Then a swing will change colors as the effects scroll automatically.  To select the current effect and color and lock it in, twist + power will exit scroll and color mode.  It is a bit difficult to time the twist + power on exit, but given the limited options for one-button sabers, it was the best that could be done.

### 2 Button Operation:
For the standard two-button saber, we’ve added some config file options to customize the color change experience. 

### DEFAULT
- Enter Color Change Mode - hold power while clicking aux
- Change Colors - Swing
- Exit Color Change - hold power while clicking aux

- Enter Scroll (color or effect) - twist + power
- Select current style and exit scroll - hold power while clicking aux.  

- Lockup: hold aux
- Lightning Block: hold power while clashing

### NO_LOCKUP_HOLD
- This removes the hold aux to lockup and moves lockup to aux + clash.  
- Select current style and exit scroll - hold aux and click power

### NO_COLOR_SWING
- This removes the hold power + aux action to enter a color change mode and instead simply changes color on each hold power + click aux action

### SAVED_PRESET
- I’ve moved the saved preset option from a default ON to default OFF.  If you want your saber to remember the current font and volume settings when the saber is powered off, you need to add this to your config file.

## Fett263 Optional Button Configuration

By default, “props/saber_sa22c_buttons.h” are set, if you wish to use base OS buttons with ColorChange controls you will change this line in ProffieOS.ino

Roughly 1/3 way down find:

#include “props/saber_sa22c_buttons.h”

Change this to

#include “props/fett263_saber.h” to utilize Base OS button config

Controls for ColorChange in this button config are

ChangeColor = Hold Aux + press Power

Enter Scroll = Hold Aux + Twist

Select/Exit Scroll = Hold Power + press Aux

Localized Lockup = Hold Aux + Clash

Force Lightning Lockup = Hold Power + Clash


## Sounds:
- There are three sounds that can be added to your font directory to enhance your color change experience: menter.wav, mexit.wav and mselect.wav.  A set of defaults will be provided (Thanks to Jesse Kirkbride of Kyberphonic for these!.). For any font used in a preset, add these three files to the font root directory and the saber will play them (rather than beeps) for these actions:
- Enter Color Swing or Effect Color Scroll = menter.wav
- Select Current Effect = mselect.wav
- Exit Color Swing or Effect Color Scroll = mexit.wav
- Enter Volume Menu = menter.wav
- Change Volume = mselect.wav
- Exit Volume Menu = mexit.wav
You can use any sounds you would like for each of these and use different sounds in each font by simply naming each accordingly, in demos Fett263 uses different boot.wav files that were renamed accordingly.

### Examples:
- An example config file with sample template styles and the DEFINE options listed above will be provided for reference.  See sample_cc.h in the /config folder for details

## Additional new Styles in this fork release:

LocalizedLockup<Base, Lockup, Drag, Block, Lockup Walk (ms), Lockup Width (% of blade), Block Walk (ms), Block Width (size)> Matt McGeary (sa22c) developed a style that implements Localized Lockup and Force Lightning Lockup (Block) animation effects based on Fett263’s Dual Lockup mod in a single compact style to create a super easy implantation, greatly reducing style sizes – I really want to call attention to the work Matt did on this, this was a very complex and painstaking amount of work to create this excellent update to the effects.

- ChangeSpark<Base, Spark, Transition (ms)>
ChangeSpark allows a Color of Effect to be implemented with “on-the-fly” color change effects.  The Spark color/effect will display and fade over the Transition Time every time the Color Change Effect is activated to add additional “accents” to your color change styles.

- EndSpark<Base, Spark, Transition (ms)>
EndSpark allows a Color or Effect to be implemented anytime a Lockup is ended, the color/effect will display and fade over the Transition Time to mimic the blade normalizing or cooling off.

- OffSpark<Base, Spark, Transition (ms)>
OffSpark allows a Color or Effect to be implemented during blade retraction, the color/effect will display and fade over the Transition Time to mimic the blade normalizing or cooling off, when used with an InOutHelper you will want to allow adequate retraction time for the effect to display.


### General OS Button functions
1 Button:

* Activate Muted - fast double click while OFF
* Activate - short click while OFF
* Play/Stop Music - hold and release while ON
* Turn off blade - hold and wait till blade is off while ON
* Next Preset - hold and release while OFF
* Prev Preset - hold and wait while OFF
* Lockup - hold + hit clash while ON
* Drag - hold + hit clash while ON pointing the blade tip down
* Blaster Blocks - short click while ON
* Force Effects - hold + twist the hilt while ON

2 Button:
POWER

* Activate Muted - fast double click while OFF
* Activate - short click while OFF
* Play/Stop Music - hold and release while OFF
* Turn off blade - hold and wait till blade is off while ON
* Force Effects - double click while ON
* Volume UP - short click while OFF and in VOLUME MENU
* Prev Preset - hold and wait while OFF

AUX
* Blaster blocks - short click while ON
* Next Preset - short click while OFF
* Lockup - hold while ON
* Drag - hold while ON pointing the blade tip down
* Enter VOLUME MENU - long click while OFF
* Volume down - short click while OFF and in VOLUME MENU
* Battery level - hold while off

3 Button:
Same as two button except for VOLUME MENU

AUX
* Volume UP - short click while OFF and in VOLUME MENU

AUX2
* Lockup - hold while ON
* Previous Preset - short click while OFF
* Volume DOWN - short click while OFF and in VOLUME MENU

### Important Configuration Parameters
:fire: smoothsw.ini needs to be present in each font directory and has two settings relevant to accent swings/spins:

AccentSwingSpeedThreshold=450.0
* // speed in deg/sec that the blade needs to be travelling to trigger an accent swings.  Higher numbers mean the saber must be swinging faster to trigger, lower the opposite. (1 - 999)

AccentSlashAccelerationThreshold=2.3
* // the g-force registered by the accelerometer that, in combination to the speed setting above, causes slashes to trigger rather than swings.  Higher numbers mean slashes trigger less often, lower the opposite. (0.1 - 4.0)

:fire:config.ini has 8 settings relevant to swings/spins/stabs for both accent and LEGACY fonts

ProffieOSSwingSpeedThreshold=350.0
* // speed in deg/sec for LEGACY Plecter/NEC fonts to trigger a swing sound (1 - 999)

ProffieOSSlashAccelerationThreshold=2.3
* // g-force to trigger LEGACY NEC slashes (0.1 - 4.0)

ProffieOSSwingVolumeSharpness=0.5
* // volume fade in for swing/slash/spin sounds.  Lower values mean more gradual fade, higher values will be more abrupt (0.1 - 2.0)

ProffieOSMaxSwingVolume=2.0
* // multiplier of hum volume, uses swing speed to ramp up swing/slash/spin volume to max value. (0.1 - 3.0)

ProffieOSSwingOverlap=0.5
* // how long into a sound before another can overlap it (percentage value, 0.1 - 1.0)

ProffieOSSmoothSwingDucking=0.2
* // how much we should duck or lower the volume of the smooth swing pairs during an accent swing/slash/stab (seems to not work as well in this version, should be no higher than 0.2)

ProffieOSSwingLowerThreshold=125.0
* // speed in deg/sec the saber must be moving to clear a 'swinging' state.  used to try and limit 'double' swings during long sweeping motions. (should be lower than speed threshold or it will cause issues.  Used for both LEGACY and accent sounds)

ProffieOSSpinRotation=360.0
* //degrees traversed before triggering a spin sound (both LEGACY and accent).  For staff sabers, cutting this value could help give a better 'dual - bladed' effect without having two proffieboards. (0 - 999 but for 1 blade, can't see why you'd change this.  For dual-blades, try 180 or 270)

ProffieOSStabAccelerationThreshold=3.0

*//G force required to trigger a stab effect. Stab effects are triggered while the saber is NOT swinging and the saber is thrust forward with a force greater than the threshold. Default is 3.0, lower values make stab more responsive, higher values less responsive. Used for both legacy Plecter AND smoothswing fonts where stab files are present.
For your Stab blade style effect, here are the values:

Stab(BASE, STAB_COLOR, MILLIS)

BASE - the base color of the blade. Like any other style, this can be any effect that returns a color.

STAB_COLOR - the color of the stab effect. Can be any effect just like base color.

MILLIS - duration of the effect. Just like in/out millis you will want to tune this to match your font.
