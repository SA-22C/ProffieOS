#SA22C Fork

Basic concept is at a speed and volume of your choosing, a standard polyphonic swing sound will be played. There are two new parameters in smoothswing.ini that control this effect: AccentSwingSpeedThreshold and AccentSwingVolume. By default, the accent swings will trigger at 650 deg/sec and will be at 3x the hum volume.

I don't think the accent swings are triggering as much as I would like, there seems to be some oddness where if the saber is being swung in smooth arcs back and forth that the accent only triggers about half the time I'd like. On quick swipes, it triggers really well and sounds pretty great.

Button mods are also present, incorporating Dmitry's changes, but in one lightsaber.ino file. Button actions change based on NUM_BUTTTONS in your config file

1 Button:

Activate Muted - fast double click while OFF

Activate - short click while OFF

Play/Stop Music - hold and release while ON

Turn off blade - hold and wait till blade is off while ON

Next Preset - hold and release while OFF

Lockup - hold + hit clash while ON

Drag - hold + hit clash while ON pointing the blade tip down

Blaster Blocks - short click while ON

Force Effects - hold + twist the hilt while ON

2 Button:

POWER

Activate Muted - fast double click while OFF

Activate - short click while OFF

Play/Stop Music - hold and release while OFF

Turn off blade - hold and wait till blade is off while ON

Blaster blocks - short click while ON

Force Effects - long click while ON

Volume UP - short click while OFF and in VOLUME MENU

AUX

Next Preset - short click while OFF

Lockup - hold while ON

Drag - hold while ON pointing the blade tip down

Enter VOLUME MENU - long click while OFF

Volume down - short click while OFF and in VOLUME MENU

3 Button:

Same as two button except for VOLUME MENU

AUX

Volume UP - short click while OFF and in VOLUME MENU

AUX2

Previous Preset - short click while OFF

Volume DOWN - short click while OFF and in VOLUME MENU

# Proffie OS

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
