/*
Code written by Rohit Sattu
Illuminati Eye? 
Required Items: 
- 32x32 LED Matrix
- Arduino Uno/Adafruit Feather Board?
*/

// include libraries
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// Define connections
#define CLK 8  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

// Make an instance LED Matrix 
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);


// Ref for functions I can use with matrix: https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h

// Quick Reference
// draw Pixel: x, y, c
// draw Rect: x, y, w, h, c
// draw Line: x0, y0, x1, y1, c
// draw Circle
// fill Circle
// fill Rect
// fill Screen
// set Cursor
// set Text Size
// set Text Wrap
// set Text Color
var eyex = 1; // adjust this to position eye on x axis
var eyey = 13; // adjust this to position eye on y axis

// Set Up
void setup() {
  Serial.begin(9600); // initialize serial port and wait for port to open
  matrix.begin(); // start matrix
  eye(eyex,eyey); // draw an eye on matrix with co-ordinates: x = 1 (eyex), y = 13 (eyey) (*I'm using a 32x32 LED Matrix) (call function eye with parameters eyex & eyey)
}

// Loop/Run
void loop() {
  
  delay(5000); // wait for 5 seconds
  lookLeft(eyex,eyey); // animate eye to look left (call function lookLeft with parameters eyex & eyey)
  delay(2000); // wait for 2 seconds
  eye(eyex,eyey); // animate eye to look straight (call function eye with parameters eyex & eyey)
  delay(3000); // wait for 3 seconds
  lookRight(eyex,eyey); // animate eye to look right  (call function lookRight with parameters eyex & eyey)
  delay(2000); // wait for 2 seconds
  eye(eyex,eyey); // animate eye to look straight (call function eye with parameters eyex & eyey)
  
}

// function to make a shape of an eye on led matrix
void eye(int x, int y) {
  eyeball(x+9,y+3); // draw a circle(eyeball) (call function eyeball with parameters eyex+9 & eyey+3) 
  eyep(x+9,y+3); // draw a circle(pupil) (call function eyep with parameters eyex+9 & eyey+3)
  eyelid(x, y); // draw a path in the shape of an eye lid (call function eyelid with parameters eyex+9 & eyey+3)
}

// function to animate eye to look left
void lookLeft(int x, int y) {
  for(int i = 1; i < 3; i++) {
    // create an effect of eye moving left
    // move eyeball to left by one leds
    eyeball(x+9-i,y+3); // draw a circle (eyeball) (call function eyeball with parameters eyex+9-i & eyey+3)
    // move pupil to left by one leds (*note: x position is x+8 instead of x+9
    eyep(x+8-i,y+3); // draw a circle (pupil) (call function eyep with parameters eyex+8-i & eyey+3)
    eyelid(x, y); // draw a path in the shape of an eye lid (call function eyelid with parameters eyex+9 & eyey+3)
  } // run for 2 times 
}

// function to animate eye to look right
void lookRight(int x, int y) {
  for(int i = 1; i < 3; i++) {
    // create an effect of eye moving left
    // move eyeball to right by one led
    eyeball(x+9+i,y+3);  // draw a circle (eyeball) (call function eyeball with parameters eyex+9+i & eyey+3)
    // move pupil to right by one led (*note: x position is x+10 instead of x+9
    eyep(x+10+i,y+3); // draw a circle (pupil) (call function eyep with parameters eyex+10-i & eyey+3)
    eyelid(x, y);// draw a path in the shape of an eye lid (call function eyelid with parameters eyex+9 & eyey+3)
  } // run for 2 times
}

// function to make an eyeball
void eyeball(int x, int y) {
  matrix.fillCircle(x+6,y+4,5,matrix.Color333(20,50,50)); // draw a filled circle (turn on led lights to form a circle with given co-ordinates)
  matrix.drawCircle(x+6,y+4,6,matrix.Color333(0,0,0)); // draw a circle outside the filled circle (turn off leds outside the circle)
  matrix.drawCircle(x+6,y+4,7,matrix.Color333(0,0,0)); // draw a circle outside the filled circle (turn off leds outside the circle)
}

// function to make a pupil
void eyep(int x, int y) 
  matrix.fillCircle(x+6,y+4,2,matrix.Color333(0,0,0)); // draw a filled circle (turn off leds to form a circle)
}

// function to make a path for eyelid
// There are better ways to do this step (like using some sin function? You can explore it.. 
void eyelid(int x, int y) {
  // path for 1
  matrix.drawLine(x+13,y,x+13+4, y,matrix.Color333(19,1,0));
  // path for 2
  matrix.drawLine(x+10,y+1,x+10+9, y+1,matrix.Color333(19,1,0));
  // path for 3
  matrix.drawLine(x+8,y+2,x+8+12, y+2,matrix.Color333(19,1,0));
  // path for 4
  matrix.drawLine(x+6,y+3,x+6+4, y+3,matrix.Color333(19,1,0));
  matrix.drawLine(x+20,y+3,x+20+2, y+3,matrix.Color333(19,1,0));
  // path for 5
  matrix.drawLine(x+5,y+4,x+5+2, y+4,matrix.Color333(19,1,0));
  matrix.drawLine(x+21,y+4,x+21+3, y+4,matrix.Color333(19,1,0));
  // path for 6
  matrix.drawLine(x+3,y+5,x+3+2, y+5,matrix.Color333(19,1,0));
  matrix.drawLine(x+22,y+5,x+22+3, y+5,matrix.Color333(19,1,0));
  // path for 7
  matrix.drawLine(x+2,y+6,x+2+2, y+6,matrix.Color333(19,1,0));
  matrix.drawLine(x+23,y+6,x+23+4, y+6,matrix.Color333(19,1,0));
  // path for 8
  matrix.drawLine(x+1,y+7,x+2+2, y+7,matrix.Color333(19,1,0));
  matrix.drawLine(x+24,y+7,x+24+4, y+7,matrix.Color333(19,1,0));
  // path for 9
  matrix.drawLine(x+2,y+8,x+2+3, y+8,matrix.Color333(19,1,0));
  matrix.drawLine(x+24,y+8,x+24+3, y+8,matrix.Color333(19,1,0));
  // path for 10
  matrix.drawLine(x+3,y+9,x+4+2, y+9,matrix.Color333(19,1,0));
  matrix.drawLine(x+23,y+9,x+23+3, y+9,matrix.Color333(19,1,0));
  // path for 11
  matrix.drawLine(x+5,y+10,x+3+5, y+10,matrix.Color333(19,1,00));
  matrix.drawLine(x+21,y+10,x+21+3, y+10,matrix.Color333(19,1,0));
  // path for 12
  matrix.drawLine(x+6,y+11,x+6+4, y+11,matrix.Color333(19,1,0));
  matrix.drawLine(x+20,y+11,x+20+3, y+11,matrix.Color333(19,1,0));
  // path for 13
  matrix.drawLine(x+8,y+12,x+7+14, y+12,matrix.Color333(19,1,0));
  // path for 14
  matrix.drawLine(x+10,y+13,x+9+10, y+13,matrix.Color333(19,1,0));
}

