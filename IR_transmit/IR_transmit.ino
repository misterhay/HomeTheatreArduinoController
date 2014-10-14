// This code runs on a TI LaunchPad with MSP430G2553, but can be modified to run on an Arduino
// It is in the public domain

#include <IRremote.h>
/* you need to comment out two lines in energia\hardware\msp430\libraries\IRremote\IRremote.cpp:
//  pinMode(TIMER_PWM_PIN, OUTPUT);
//  digitalWrite(TIMER_PWM_PIN, LOW); // When not sending PWM, we want it low
*/

// from https://github.com/thomasfredericks/Bounce-Arduino-Wiring
#include <Bounce.h> // not Bounce2.h

IRsend irsend; // the IR transmit pin is 11, also requires a 50-150 ohm resistor
const int irLED = 11;
int serialMessage; // for data we'll receive from the serial port

int debounceTime = 20;

// buttons can be connected to 3 through 10, 12 to 15, 18, and 19
// for a total of 14 (or 13 if we don't use pin 14 which is GREEN_LED)
// but if we use serial communication, we also can't use pins 3 and 4
int buttonPower = 5;
int buttonVolumeUp = 6;
int buttonVolumeDown = 7;
int buttonPresetPrevious = 8;
int buttonXbox = 9;
int buttonRadio = 10;
int buttonAppleTV = 12;
int buttonComputer = 13;
int buttonNightMode = 15;//*/

Bounce debouncePower = Bounce(buttonPower, debounceTime);
Bounce debounceVolumeUp = Bounce(buttonVolumeUp, debounceTime);
Bounce debounceVolumeDown = Bounce(buttonVolumeDown, debounceTime);
Bounce debouncePresetPrevious = Bounce(buttonPresetPrevious, debounceTime);
Bounce debounceXbox = Bounce(buttonXbox, debounceTime);
Bounce debounceRadio = Bounce(buttonRadio, debounceTime);
Bounce debounceAppleTV = Bounce(buttonAppleTV, debounceTime);
Bounce debounceComputer = Bounce(buttonComputer, debounceTime);
Bounce debounceNightMode = Bounce(buttonNightMode, debounceTime);//*/

void setup() {
  pinMode(GREEN_LED,OUTPUT); // pin 14
  pinMode(RED_LED,OUTPUT); // pin 2
  Serial.begin(9600); // set up serial listen, so that we can receive commands relayed from the OSC server computer
  pinMode(buttonPower, INPUT_PULLUP);
  pinMode(buttonVolumeUp, INPUT_PULLUP);
  pinMode(buttonVolumeDown, INPUT_PULLUP);
  pinMode(buttonPresetPrevious, INPUT_PULLUP);
  pinMode(buttonXbox, INPUT_PULLUP);
  pinMode(buttonRadio, INPUT_PULLUP);
  pinMode(buttonAppleTV, INPUT_PULLUP);
  pinMode(buttonComputer, INPUT_PULLUP);
  pinMode(buttonNightMode, INPUT_PULLUP);
  digitalWrite(RED_LED, HIGH);
  delay(500); // wait half a second
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, LOW);
}

/*
void irMessage(int messageNumber) {
  if (messageNumber == 1){irsend.sendNEC(0x5EA1F807, 32); delay(1000); irsend.sendNEC(0x5EA1EA15, 32);}// Power toggle, wait, start sleeping for 120 minutes
  if (messageNumber == 2){irsend.sendNEC(0x5EA158A7, 32);} // VolumeUp
  if (messageNumber == 3){irsend.sendNEC(0x5EA1D827, 32);} // VolumeDown
  if (messageNumber == 4){irsend.sendNEC(0x5EA18877, 32);} // PresetPrevious
  if (messageNumber == 5){irsend.sendNEC(0x5EA1837C, 32);} // Xbox
  if (messageNumber == 6){irsend.sendNEC(0x5EA16897, 32);} // Radio
  if (messageNumber == 7){irsend.sendNEC(0x5EA12AD5, 32);} // AppleTV
  if (messageNumber == 8){irsend.sendNEC(0x5EA1AA55, 32);} // Computer
  if (messageNumber == 9){irsend.sendNEC(0x5EA1A956, 32);} // NightMode
}
//*/

void irMessage(int messageNumber) {
  if (messageNumber == 1){Serial.write('Power toggle, wait, start sleeping for 120 minutes');}
  if (messageNumber == 2){Serial.write('VolumeUp');}
  if (messageNumber == 3){Serial.write('VolumeDown');}
  if (messageNumber == 4){Serial.write('PresetPrevious');}
  if (messageNumber == 5){Serial.write('Xbox');}
  if (messageNumber == 6){Serial.write('Radio');}
  if (messageNumber == 7){Serial.write('AppleTV');}
  if (messageNumber == 8){Serial.write('Computer');}
  if (messageNumber == 9){Serial.write('NightMode');}
}

void loop() {
  // update the debouncers
  debouncePower.update();
  debounceVolumeUp.update();
  debounceVolumeDown.update();
  debouncePresetPrevious.update();
  debounceXbox.update();
  debounceRadio.update();
  debounceAppleTV.update();
  debounceComputer.update();
  debounceNightMode.update();//*/

  // read from the serial port
  while(Serial.available()) {serialMessage = Serial.read();}
  if(serialMessage == '1'){irMessage(1);}
  //if(serialMessage == '1'){irsend.sendNEC(0x5EA1F807, 32);}
  if(serialMessage == '2'){irMessage(2);}
  if(serialMessage == '3'){irMessage(3);}
  if(serialMessage == '4'){irMessage(4);}
  if(serialMessage == '5'){irMessage(5);}
  if(serialMessage == '6'){irMessage(6);}
  if(serialMessage == '7'){irMessage(7);}
  if(serialMessage == '8'){irMessage(8);}
  if(serialMessage == '9'){irMessage(9);}

  // for testing serial messages
  if (serialMessage == 100){digitalWrite(GREEN_LED, HIGH);}
  if (serialMessage == 200){digitalWrite(RED_LED, HIGH);}
  
  // read the debouncers
  if(debouncePower.read() == 0) {irMessage(1);}
  if(debounceVolumeUp.read() == 0) {irMessage(2);}
  if(debounceVolumeDown.read() == 0) {irMessage(3);}
  if(debouncePresetPrevious.read() == 0) {irMessage(4);}
  if(debounceXbox.read() == 0) {irMessage(5);}
  if(debounceRadio.read() == 0) {irMessage(6);}
  if(debounceAppleTV.read() == 0) {irMessage(7);}
  if(debounceComputer.read() == 0) {irMessage(8);}
  if(debounceNightMode.read() == 0) {irMessage(9);}//*/

  // otherwise turn off all of the LEDs
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(irLED, LOW);
  }
}

/*
The IR Codes are (NEC format, 32 bit):
Power Toggle	5EA1F807
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
*/
