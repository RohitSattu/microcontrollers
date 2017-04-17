/*
Code written by Rohit Sattu
Required Items:
- Arduino Uno/Adafruit Feather Board
- Stretch sensor
- LED
*/

int led = 13;         // the PWM pin the LED is attached to
int aveStretch= 670;  // default average stretch // varies depends on your device and power input (3v or 5v)
int stretch = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int i = 0; i < 10; i++) {
  Serial.print(".");
} // Calibaration
Serial.println("Stretch Ready");
// Set average stretch value
aveStretch = analogRead(A0);
// declare pin 9 to be an output:
Serial.println(analogRead(A0));
pinMode(led, OUTPUT);
}

void loop() {
 Serial.println(analogRead(A0)); // Print average stretch value
 stretch = analogRead(A0);

 if (stretch  < aveStretch - 10) {
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
 }
}
