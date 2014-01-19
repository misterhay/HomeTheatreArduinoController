#include <IRremote.h>
/* you need to comment out two lines in energia\hardware\msp430\libraries\IRremote\IRremote.cpp:
//  pinMode(TIMER_PWM_PIN, OUTPUT);
//  digitalWrite(TIMER_PWM_PIN, LOW); // When not sending PWM, we want it low
*/

#include <Bounce.h>

IRsend irsend; // the IR transmit pin is 11, also requires a 50-150 ohm resistor
const int button1 = 8; //The power button on this pin and ground
const int button2 = 9; //The NoShow button on this pin and ground
const int led2 = 2; //The red status LED

Bounce bouncer1 = Bounce(button1, 20); // 20 millisecond debounce
Bounce bouncer2 = Bounce(button2, 20);

void setup() {
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(led2,OUTPUT);
}

void loop() {
  // Update the debouncers
  bouncer1.update ( );
  bouncer2.update ( );

  if (bouncer1.read() == 0) {
    digitalWrite(led2, HIGH); // turn on the red status LED so we know something is happening
    irsend.sendNEC(0xC40BF, 32); // send Benq power button signal
    delay(100);
    irsend.sendNEC(0xCF300FF, 32); // send Sanyo power button pressed
    delay(100);
    irsend.sendNEC(0xC73FF00, 32); // send Sanyo power button released
    digitalWrite(P2_3, LOW); // turn off the IR LED when not transmitting
    delay(1000); // wait for a second
  }
  else if (bouncer2.read() == 0) {
    digitalWrite(led2, HIGH); // turn on the red status LED so we know something is happening
    irsend.sendNEC(0xCF3D12E, 32); // send Sanyo AV Mute (no show) command
    digitalWrite(P2_3, LOW); // turn off the IR LED when not transmitting
    delay(1000); // wait for a second
  }
  else {
  }
}
