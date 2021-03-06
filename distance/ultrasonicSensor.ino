/*
 * 
 * Code Written By Rohit Sattu
 * 
 * Ultrasonic Sensor: Trig sends out a signal and Echo receives the reflected signal.
 * Depending on how much time it took for the signal from trig to reach echo, ultrasonic sensor calculates the distance. 
 * 
 * Time = distance / speed; (Speed of sound = 340 m/s)
 * Using the formula above you can find the distance between sensor and object in centi-meters 
 * 
 * 
 * 
 */



const int trig = 11; // Variable trigger to be set to (pin 11)
const int echo = 10; // Variable echo to be set to (pin 10)
const int ledWhite = 9; // the PWM (pin 9) the LED is attached to
const int ledGreen = 8; //the ledRGB series attached to pin 8
const int ledBlue = 4; //the ledRGB series attached to pin 4
const int ledRed = 2; //the ledRGB series attached to pin 2
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
long duration = 0; //Defining duration to zero.
int distance = 0; //Defining distance from sensor to the object to be zero. 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT); //Set ledRGB (pin 2) to be an output
  pinMode(ledGreen, OUTPUT); //Set ledRGB (pin 4) to be an output
  pinMode(ledBlue, OUTPUT); //Set ledRGB (pin 8) to be an output
  pinMode(ledWhite, OUTPUT); //Set ledWhite (pin 9) to be an output
  pinMode(echo, INPUT); //Set echo (pin 10) to be an input
  pinMode(trig, OUTPUT); //Set trig (pin 11) to be an output
  
  Serial.begin(9600); //Start the serail communication to show results on the monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW); //Make sure trig is clear
  delayMicroseconds(2); //Wait for 2 microseconds

  digitalWrite(trig, HIGH); //Send a signal
  delayMicroseconds(10); //wait for 10 microseconds
  digitalWrite(trig, LOW); //Stop the signal 

  duration = pulseIn(echo, HIGH); // look for the reflected signal sent by trig
  distance = duration * 0.034/2; // Calculate the distance from sensor to the object (Speed of sound is 340 m/s)

  // Print Distance on the screen
  Serial.print("Distance: "); 
  Serial.println(distance); 
  if (distance < 500) { // to avoid false reading
    // if object is 20 cm away, blink led series else blink white led.
    if (distance > 20) {
      //turn white led off
      analogWrite(ledWhite, 0);
      // turn the Red, Green and Blue LED's on (HIGH is the voltage level):
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, HIGH);  
      digitalWrite(ledBlue, HIGH);     
      delay(1000);              // wait for a second
      // turn the Red, Green and Blue LED's off by making the voltage LOW:
      digitalWrite(ledRed, LOW);    
      digitalWrite(ledGreen, LOW); 
      digitalWrite(ledBlue, LOW);   
      delay(1000);              // wait for a second
    } else {
      analogWrite(ledWhite, brightness); // set the brightness of pin 9
      brightness = brightness + fadeAmount; // change the brightness for next time through the loop
    
      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
        
      // wait for 30 milliseconds to see the dimming effect
      delay(distance);
    }
  } else {
      analogWrite(ledWhite, 0);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
      delay(1000);
   }
}
