/*
 * Code written by Rohit Sattu
 * PIR (Passive Infrared Sensor), LEDStrip and Servo Motor
 * track user motion
*/

// include libraries
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <Servo.h> 


// define pins 
#define PIN 10 // led lights connected to pin 10
int pirPin1 = 3; // pin connected to the first PIR sensor's output
int pirPin2 = 5; // pin connected to the second PIR sensor's output
int pirPin3 = 6; // pin connected to the second PIR sensor's output
int servoPin = 9; // pin connected to the servo motor

// make an instance of led lights
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// create servo object
Servo servom; 

// Set up
void setup() {
   // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  // begin led lights
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600); // initialize serial port and wait for port to open
  servom.attach(servoPin); // attach servo to specified pin (output)
  pinMode(pirPin1, INPUT); // initialize PIR pin as an input
  pinMode(pirPin2, INPUT); // initialize PIR pin as an input
  pinMode(pirPin3, INPUT); // initialize PIR pin as an input
  
  // Make the voltage of PIR pins to LOW for calibaration
  digitalWrite(pirPin1, LOW);
  digitalWrite(pirPin2, LOW);
  digitalWrite(pirPin3, LOW);
  
  // calibarate for 30 seconds
  for(int i = 0; i < 30; i++) { 
    Serial.print("."); // print "." on Serial Monitor
    delay(1000); // wait for a second
  }
  Serial.print("PIR is ready"); // print "PIR is ready" on Serial Monitor (when Calibaration is done)
  
}

void loop() {
  // Check for motion
  if(digitalRead(pirPin1) == HIGH) {
    if (digitalRead(pirPin2) == HIGH) {
      if (digitalRead(pirPin3) == HIGH) { // There is movement everywhere
        Serial.println("There is movement everywhere!");
        if (servom.read() != 90) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(90);
          delay(1000); 
        } 
        colorWipe(strip.Color(128, 255, 255), 50); // change colors on led strip
      } else { // PIR 1, 2 are HIGH and PIR 3 is LOW
        Serial.println("Movement detected between area 1 and 2.");
        if (servom.read() != 45) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(45); 
          delay(1000);
        }
        colorWipe(strip.Color(255, 255, 0), 50); // change colors on led strip
      }
    } else {
      if (digitalRead(pirPin3) == HIGH) { // PIR 1, 3 are HIGH and PIR 2 is LOW
        Serial.println("Movement detected between area 1 and 3.");
        if (servom.read() != 90) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(90);
          delay(1000);
        }
        colorWipe(strip.Color(128, 255, 255), 50); // change colors on led strip
      } else { // PIR 1 is HIGH and PIR 2, 3 are LOW
        Serial.println("Movement detected in area 1.");
        if (servom.read() != 0) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(0);
          delay(1000);
        }
        colorWipe(strip.Color(255, 0, 0), 50); // change colors on led strip
      }
    }
  } else {
    if (digitalRead(pirPin2) == HIGH) {
      if (digitalRead(pirPin3) == HIGH) { // PIR 2, 3 are HIGH and 1 is LOW
        Serial.println("Movement detected between area 2 and 3.");
        if (servom.read() != 135) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(135);
          delay(1000);
        }
        colorWipe(strip.Color(255, 0, 255), 50); // change colors on led strip
      } else { // PIR 2 is HIGH and PIR 1, 3 are LOW
        Serial.println("Movement detected in area 2.");
        if (servom.read() != 90) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(90);
          delay(1000);
        }
         colorWipe(strip.Color(0, 255, 0), 50); // change colors on led strip
      }
    } else {
      if (digitalRead(pirPin3) == HIGH) { // PIR 3 is HIGH and PIR 1, 2 are LOW
       Serial.println("Movement detected in area 3.");
       if (servom.read() != 180) { // Check for servo motor's handle angle
          // turn servo motor's handle to angle specified, if servo motor's handle is not a;ready at that angle
          servom.write(180); 
          delay(1000);
       }
       colorWipe(strip.Color(0, 0, 255), 50); // change colors on led strip
      } else {
        Serial.println("No Motion"); 
        colorWipe(strip.Color(128, 255, 255), 50); // change colors on led strip
      }
    }
  }
  delay(50);
   
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // change colors
    strip.show();
    delay(wait);
  } // run till the end of the strip
}
