#include <IRremote.h>
/* you need to comment out two lines in energia\hardware\msp430\libraries\IRremote\IRremote.cpp:
//  pinMode(TIMER_PWM_PIN, OUTPUT);
//  digitalWrite(TIMER_PWM_PIN, LOW); // When not sending PWM, we want it low
*/


// check out multiple buttons with this code:
// http://www.adafruit.com/blog/2009/10/20/example-code-for-multi-button-checker-with-debouncing/

// check out serial event with this code:
// http://arduino.cc/en/Tutorial/SerialEvent

// from https://github.com/thomasfredericks/Bounce-Arduino-Wiring
#include <Bounce2.h>

IRsend irsend; // the IR transmit pin is 11, also requires a 50-150 ohm resistor
const int button1 = 8; //The power button on this pin and ground
const int button2 = 9; //The NoShow button on this pin and ground
const int led2 = 2; //The red status LED
// buttons can be connected to 3 through 10, 12 to 15, 18, and 19
// for a total of 14 (or 13 if we don't use pin 14 which is GREEN_LED)
// but if we use serial communication, we also can't use pins 3 and 4

// initialize a string variable for the serial data received from the computer
String controlCode = "";
boolean stringComplete = false;  // whether the string is complete

Bounce bouncer1 = Bounce(button1, 20); // 20 millisecond debounce
Bounce bouncer2 = Bounce(button2, 20);

void setup() {
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(led2,OUTPUT);
  // set up serial listen, so that we can receive OSC commands relayed from the computer
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // Update the debouncers
  bouncer1.update ( );
  bouncer2.update ( );

  if (bouncer1.read() == 0) {
    digitalWrite(led2, HIGH); // turn on the red status LED so we know something is happening
    irsend.sendNEC(0x5EA1F807, 32); // send power toggle
    delay(100);
    irsend.sendNEC(0x5EA1EA15, 32); // send sleep (120 minutes is the default, send again to decrement)
    digitalWrite(P2_3, LOW); // turn off the IR LED when not transmitting
    delay(1000); // wait for a second
  }
  else if (bouncer2.read() == 0) {
    digitalWrite(led2, HIGH); // turn on the red status LED so we know something is happening
    irsend.sendNEC(0x5EA1837C, 32); // send input DVD
    delay(100);
    irsend.sendNEC(0x5EA1A857, 32); // send input CD
    delay(100);
    digitalWrite(P2_3, LOW); // turn off the IR LED when not transmitting
    delay(1000); // wait for a second
  }
  else {
  }
}

/*
The IR Codes are (NEC format):
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
