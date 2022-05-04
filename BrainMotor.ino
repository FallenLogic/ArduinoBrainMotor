#include <Brain.h>
#include <Servo.h>

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);
Servo myservo;

// Define the servo pin:
#define servoPin 9

void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
    myservo.attach(servoPin);
}

void loop() {
    // Expect packets about once per second.
    if (brain.update()) {
        byte E = brain.readAttention();
        //This is just so it shows up on the Serial Monitor - it's not strictly necessary
        Serial.println(E);
        int I = (int) E;
        if(I > 60) {
          myservo.write(50);
        }
        if(I < 50) {
          myservo.write(90);  
        }
    }
}
