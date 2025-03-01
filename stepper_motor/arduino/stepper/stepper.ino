#include <AccelStepper.h>


#define DIRECTION_PIN 2
#define STEP_PIN 3
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIRECTION_PIN);

void setup() {
  stepper.setMaxSpeed(250);
  stepper.setAcceleration(100);

  stepper.setCurrentPosition(0);

  Serial.begin(115200);
  Serial.println("Entering main loop...");
}


void loop() {
  stepper.moveTo(200);
  while (stepper.currentPosition() != 200) // Full speed up to 300
    stepper.run();
}
