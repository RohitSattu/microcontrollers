/*
 Code written by Rohit Sattu
 Get max/min readings of your GSR
*/
int AnalogPin0 = A0;
int Value; // Data collected into the GSR sensor
int Mapped; // Mapped Value variable

int minValue = 1023; // Insert minValue from calibration session
int maxValue = 0; // tInsert maxValue from calibration session

void setup() {
  Serial.begin (9600);
}

void loop() {
  Value = analogRead(AnalogPin0); // Collect data from GSR
  // Serial.print ("Original Value = ");
  // Serial.println (Value); // Print the Value Data

  if (Value < minValue) {
  minValue = Value;
  } // Continuously searching for a value that is less than the current

  if (Value > maxValue) {
  maxValue = Value;
  } // Continuously search for a value that is great than the maxValue

  Mapped = map(Value, 0, 1023, 0, 1023);
  Serial.print("Mapped Value = ");
  Serial.println(Mapped);
  Serial.print("Your Sensor Value: ");
  Serial.println(Value);
  Serial.print("Your min Value for this session: ");
  Serial.println(minValue);
  Serial.print("Your max Value for this session: ");
  Serial.println(maxValue);
  delay(500); // Delay of 1/2 second
}
