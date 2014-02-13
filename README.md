HomeTheatreArduinoController
============================
This is an Arduino-based controller for my home theatre receiver with OSC for networked remote controllers.

The Arduino (Launchpad, Teensy, et al.) has an IR LED for transmitting codes based on the serial messages it receives from the computer that is running the Python program that receives OSC messages. The OSC messages can be transmitted by the Processing sketch or TouchOSC (on iOS or Android)



The IR Codes for my Yamaha receiver are (in NEC format):

Power		5EA1F807

Mute		5EA138C7

VolumeUp	5EA158A7

VolumeDown	5EA1D827

PresetPrevious	5EA18877

InputCD		5EA1A857

InputDVD	5EA1837C

InputMD/CDR	5EA1936C

InputTuner	5EA16897

InputDTV/CBL	5EA12AD5

InputV-Aux	5EA1AA55

InputVCR	5EA1F00F

Night Mode	5EA1A956

Sleep		5EA1EA15

The "repeat previous" code is NEC: FFFFFFFF
