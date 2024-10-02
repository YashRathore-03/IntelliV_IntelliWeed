#include <AFMotor.h>

// Define rover motors using the Adafruit Motor Shield motor ports
AF_DCMotor roverMotor1(1);  // Rover Motor 1 connected to M1 on the motor shield
AF_DCMotor roverMotor2(2);  // Rover Motor 2 connected to M2 on the motor shield
AF_DCMotor roverMotor3(3);  // Rover Motor 3 connected to M3 on the motor shield
AF_DCMotor roverMotor4(4);  // Rover Motor 4 connected to M4 on the motor shield

void setup() {
  // Set all motors' speed to 150 (range 0-255)
  roverMotor1.setSpeed(150);  
  roverMotor2.setSpeed(150);  
  roverMotor3.setSpeed(150);  
  roverMotor4.setSpeed(150);  

  // Start with all motors stopped
  stopAllMotors();
}

void loop() {
  // First iteration: Move forward for 2 seconds, wait for 13 seconds for arm movement
  moveForward();
  delay(2000);  // Move forward for 2 seconds
  stopAllMotors();
  delay(13000);  // Wait for 13 seconds (for arm movement)

  // Second iteration: Move forward for another 2 seconds, wait again for 13 seconds
  moveForward();
  delay(2000);  // Move forward for 2 seconds
  stopAllMotors();
  delay(13000);  // Wait for 13 seconds (for arm movement)

  // Stop the rover completely after second iteration
  stopAllMotors();
  while (true);  // Stop forever
}

// Function to move the rover forward
void moveForward() {
  // Set all motors to move forward
  roverMotor1.run(FORWARD);
  roverMotor2.run(FORWARD);
  roverMotor3.run(FORWARD);
  roverMotor4.run(FORWARD);
}

// Function to stop all motors
void stopAllMotors() {
  // Set all motors to stop
  roverMotor1.run(RELEASE);
  roverMotor2.run(RELEASE);
  roverMotor3.run(RELEASE);
  roverMotor4.run(RELEASE);
}
