#include <AFMotor.h>

// Define motors using the motor port numbers on the Adafruit Motor Shield
AF_DCMotor gripperMotor(1);  // Gripper motor (M1)
AF_DCMotor armMotor1(3);     // Arm Motor 1 (M3)
AF_DCMotor armMotor2(4);     // Arm Motor 2 (M4)

void setup() {
  // Set the motor speed for the gripper and both arm motors
  gripperMotor.setSpeed(150);  // Speed for Gripper to control opening size
  armMotor1.setSpeed(150);     // Speed for Arm Motor 1
  armMotor2.setSpeed(150);     // Speed for Arm Motor 2

  // Start with all motors stopped
  stopAllMotors();

  // Perform the entire movement sequence once
  performArmMovement();

  // Stop all motors after completing the movement
  stopAllMotors();
}

void loop() {
  // Empty loop
}

// Function to perform the entire arm and gripper movement
void performArmMovement() {
  // Step 1: Open the gripper at the top
  openGripper();
  delay(1000);  // Gripper remains open for 1 second

  // Step 2: Move the arm forward and down to grab the object
  moveArmsForwardAndDown();
  delay(2000);  // Allow time for arm to move down

  // Step 3: Close the gripper to grab the object
  closeGripper();
  delay(1000);  // Gripper remains closed for 1 second

  // Step 4: Move the arm back up with the object
  moveArmsUp();
  delay(2000);  // Allow time for arm to move back up

  // Step 5: Open the gripper at the top to drop the object
  openGripper();
  delay(1000);  // Gripper remains open to drop the object

  // Step 6: Close the gripper after dropping the object
  closeGripper();
  delay(500);  // Ensure the gripper closes
}

// Function to move both Arm Motor 1 and Arm Motor 2 forward and down (with more forward movement)
void moveArmsForwardAndDown() {
  for (int speed = 0; speed <= 150; speed += 15) {  // Increase the increment for faster forward movement
    armMotor1.setSpeed(speed);
    armMotor2.setSpeed(speed);
    armMotor1.run(FORWARD);  
    armMotor2.run(FORWARD);
    delay(200);  // Discrete steps for smooth forward and down motion
  }

  delay(1000);  // Hold time for the arm to fully reach a further down position without hitting extreme positions

  for (int speed = 150; speed >= 0; speed -= 15) {
    armMotor1.setSpeed(speed);
    armMotor2.setSpeed(speed);
    delay(150);
  }

  stopArms();
}

// Function to move both Arm Motor 1 and Arm Motor 2 back up
void moveArmsUp() {
  for (int speed = 0; speed <= 150; speed += 15) {
    armMotor1.setSpeed(speed);
    armMotor2.setSpeed(speed);
    armMotor1.run(BACKWARD);  
    armMotor2.run(BACKWARD);
    delay(150);  // Discrete steps for smooth upward motion
  }

  delay(500);  // Hold time for arm to return to the top position

  for (int speed = 150; speed >= 0; speed -= 15) {
    armMotor1.setSpeed(speed);
    armMotor2.setSpeed(speed);
    delay(150);
  }

  stopArms();
}

// Function to open the gripper (restrict opening size)
void openGripper() {
  gripperMotor.run(FORWARD);  // Run the gripper motor to open
  delay(200);                 // Restrict opening size
  gripperMotor.run(RELEASE);  // Stop the gripper motor after opening
}

// Function to close the gripper
void closeGripper() {
  gripperMotor.run(BACKWARD);  // Run the gripper motor to close
  delay(300);                  // Gripper stays closed for 300ms
  gripperMotor.run(RELEASE);   // Stop the gripper motor after closing
}

// Function to stop all motors
void stopAllMotors() {
  stopArms();
  stopGripper();
}

// Function to stop arm motors
void stopArms() {
  armMotor1.run(RELEASE);  // Stop Arm Motor 1
  armMotor2.run(RELEASE);  // Stop Arm Motor 2
}

// Function to stop the gripper motor
void stopGripper() {
  gripperMotor.run(RELEASE);  // Stop the gripper motor
}
