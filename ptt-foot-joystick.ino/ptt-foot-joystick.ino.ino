/* Teensy becomes a USB joystick with 16 or 32 buttons and 6 axis input

   You must select Joystick from the "Tools > USB Type" menu

   Pushbuttons should be connected between the digital pins and ground.
   Potentiometers should be connected to analog inputs 0 to 5.

   See: https://www.pjrc.com/teensy/td_joystick.html

*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);

// Configure the number of buttons.  Be careful not
// to use a pin for both a digital button and analog
// axis.  The pullup resistor will interfere with
// the analog voltage.
const int numButtons = 6;  // 16 for Teensy, 32 for Teensy++

void setup() {
  for (int i=0; i<numButtons; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}


byte allButtons[numButtons]={};

void loop() {
  for (int i=0; i<numButtons; i++) {
    byte b=!(digitalRead(i));
    if (b != allButtons[i]) {
      allButtons[i]=b;
      Joystick.button(i+1,b);
    }
  }
  delay(50);
}
