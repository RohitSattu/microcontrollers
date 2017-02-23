/*
Code written by Rohit Sattu
Required Items:
- Particle Photon
- 3 Buttons
- 1 LED
*/
// LED and buttons are connected to:
const int D0button = D0;
const int D4button = D4;
const int A2button = A2;
const int led = A5;

// Set Device Name here
const String nameOfTheDevice = "MoniduhE"; 

// Buttons Status
int D0State = 0;
int D4State = 0;
int A2State = 0;

// To check if the device is connected to the internet
int readyStatus = 0;

void setup() {
    // Set up connections
    pinMode(D0button, INPUT_PULLDOWN);
    pinMode(D4button, INPUT_PULLDOWN);
    pinMode(A2button, INPUT_PULLDOWN);
    pinMode(led, OUTPUT);
}

void loop() {
    // Check if the device is connected to the internet
    if (readyStatus == 0) {
        sysReady(); // If it is, give a feedback
    }
    
    D0State = digitalRead(D0button);
    D4State = digitalRead(D4button);
    A2State = digitalRead(A2button);
    if (D0State == HIGH) {
        // flash light to give a feedback to the user
        feedback();
        // send a notification to Particle cloud
        Particle.publish(nameOfTheDevice, "btn1Pressed");
    } else if (D4State == HIGH) {
        feedback();
        Particle.publish(nameOfTheDevice, "btn2Pressed");
    } else if (A2State == HIGH) {
        feedback();
        Particle.publish(nameOfTheDevice, "btn3Pressed");
    }
    digitalWrite(led, LOW);
        // Particle.publish("buttonPressed", 0);
}

// Blink for 3 times
void feedback() {
    if (Particle.connected()) {
        for (int i = 0; i < 3; i++) {
            digitalWrite(led, HIGH);
            delay(500);
            digitalWrite(led, LOW);
            delay(500);
        }
    } 
}

// Blink for 5 times + turn the light on for 2 seconds
void sysReady() {
    if (Particle.connected()) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(led, HIGH);
            delay(200);
            digitalWrite(led, LOW);
            delay(200);
        }
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        readyStatus = 1;
    } 
}
