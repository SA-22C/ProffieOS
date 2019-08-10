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
* Save state - saber remembers current preset and volume level across reboot/sleep
* Plecter fonts - spin and stab effects, plus CFX smooth swing.
* NEC fonts - slsh effects
* Smooth Swing V2.1 - Accent effects - spin, swng, slsh, stab layered over the high/low swing pairs
* Volume control on the fly
* Stab blade effect
* spoken battery command
* 1/2/3 button mods 
* button mash control - no false triggers of button holds while rapidly pressing buttons

### Button functions
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


For your Stab blade style effect, here are the values:

Stab(BASE, STAB_COLOR, MILLIS)

BASE - the base color of the blade.  Like any other style, this can be any effect that returns a color.

STAB_COLOR - the color of the stab effect.  Can be any effect just like base color.

MILLIS - duration of the effect.  Just like in/out millis you will want to tune this to match your font.

