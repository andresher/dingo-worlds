#include "main.h"
#include "robot.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void removeSlack() {
   driveController.forward(0.5);
   pros::delay(75);
   driveController.stop();
 }

void moveDistance(QLength len) {
   driveController.setMaxVelocity(200);
   profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{len, 0_ft, 0_deg}}, "A");
   profileController.setTarget("A");
   profileController.waitUntilSettled();
}

void moveDistance(QLength len, bool isBackwards) {
  driveController.setMaxVelocity(200);
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{len, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A", isBackwards);
  profileController.waitUntilSettled();
}

void frontWithUltra() {
  for (int i=0; i<100; i++) {
		ultrasonic.get();
	}
  while(ultrasonic.get() > 365.0) {
    driveController.forward(0.10);
  }
  driveController.stop();
}

void autoBlueBack() {
  int turnSpeed = 70;
  catapult.set_value(0);
  removeSlack();
  pros::delay(100);
  // Get first cap
  moveDistance(2.75_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-85_deg);
  pros::delay(100);
  liftController.setTarget(-20);
  flipperController.setTarget(120);
  moveDistance(30_in);
  pros::delay(100);
  flipperController.setTarget(80);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(100);
  liftController.setTarget(180);
  liftController.waitUntilSettled();
  moveDistance(14.5_in, true);
  pros::delay(100);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-90_deg);
  removeSlack();
  moveDistance(10_in);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(11_in, true);
  pros::delay(100);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(40_deg);
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  moveDistance(18_in);
  flipperController.setTarget(90);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  moveDistance(7_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-140_deg);
  removeSlack();
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(10_in);
  liftController.setMaxVelocity(600);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  flipperController.setTarget(110);
  flipperController.waitUntilSettled();
  pros::delay(500);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(3_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-85_deg);
  flipperController.setTarget(120);
  moveDistance(49_in);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(2_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(100_deg);
  // Place 3rd
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  frontWithUltra();
  driveController.forward(0.02);
  // shaky shaky
  liftController.flipDisable();
  for (int i=0; i<4; i++){
    lift.moveVoltage(5000);
    pros::delay(120);
    lift.moveVoltage(-5000);
    pros::delay(100);
  }
  liftController.flipDisable();
  // end shaky shaky
  driveController.stop();
  pros::delay(300);
  liftController.setMaxVelocity(100);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(11_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-90_deg);
  moveDistance(14_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(90_deg);
  liftController.setTarget(180);
  transmission.set_value(0);
  driveController.forward(-1);
  pros::delay(2000);
  driveController.stop();
}

void autoRedBack() {
  catapult.set_value(0);
  removeSlack();
  pros::delay(100);
  // Get first cap
  driveController.turnAngle(95_deg);
  pros::delay(100);
  liftController.setTarget(-20);
  flipperController.setTarget(120);
  moveDistance(36_in);
  pros::delay(100);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(90);
  flipperController.waitUntilSettled();
  moveDistance(10.5_in, true);
  pros::delay(100);
  driveController.turnAngle(90_deg);
  removeSlack();
  moveDistance(10_in);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(11_in, true);
  pros::delay(100);
  driveController.turnAngle(-42_deg);
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  moveDistance(18_in);
  flipperController.setTarget(90);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  moveDistance(5_in, true);
  driveController.turnAngle(137_deg);
  removeSlack();
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(10_in);
  liftController.setMaxVelocity(600);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  flipperController.setTarget(110);
  flipperController.waitUntilSettled();
  pros::delay(500);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  driveController.turnAngle(95_deg);
  flipperController.setTarget(120);
  moveDistance(49_in);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(2_in, true);
  driveController.turnAngle(-100_deg);
  // Place 3rd
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  frontWithUltra();
  driveController.forward(0.02);
  // shaky shaky
  liftController.flipDisable();
  for (int i=0; i<4; i++){
    lift.moveVoltage(5000);
    pros::delay(120);
    lift.moveVoltage(-5000);
    pros::delay(100);
  }
  liftController.flipDisable();
  // end shaky shaky
  driveController.stop();
  pros::delay(300);
  liftController.setMaxVelocity(100);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(11_in, true);
  driveController.turnAngle(90_deg);
  moveDistance(14_in, true);
  driveController.turnAngle(-90_deg);
  liftController.setTarget(180);
  transmission.set_value(0);
  driveController.forward(-1);
  pros::delay(2000);
  driveController.stop();
}

void autoRedFront() {
  catapult.set_value(0);
  removeSlack();
  pros::delay(100);
  liftController.setTarget(280);
  flipperController.setTarget(120);
  moveDistance(38_in);
  moveDistance(5_in, true);
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  flipperController.waitUntilSettled();
  liftController.waitUntilSettled();
  driveController.turnAngle(90_deg);
  driveController.forward(-0.4);
  pros::delay(600);
  driveController.stop();
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  moveDistance(23_in);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  moveDistance(6_in, true);
  driveController.turnAngle(93_deg);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(35.5_in);
  driveController.turnAngle(95_deg);
  flipperController.setTarget(103);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  frontWithUltra();
  driveController.forward(0.02);
  // shaky shaky
  liftController.flipDisable();
  for (int i=0; i<4; i++){
    lift.moveVoltage(5000);
    pros::delay(120);
    lift.moveVoltage(-5000);
    pros::delay(100);
  }
  liftController.flipDisable();
  // end shaky shaky
  driveController.stop();
  liftController.setMaxVelocity(80);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  liftController.waitUntilSettled();
  // End place first cap
  driveController.setMaxVelocity(200);
  driveController.turnAngle(90_deg);
  moveDistance(12_in);
  driveController.turnAngle(95_deg);
  driveController.forward(-0.3);
  pros::delay(800);
  driveController.stop();
  flipperController.setTarget(120);
  moveDistance(28_in);
  driveController.setMaxVelocity(30);
  driveController.moveDistance(12_in);
  driveController.setMaxVelocity(200);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(90);
  flipperController.waitUntilSettled();
  moveDistance(28_in, true);
  driveController.turnAngle(95_deg);
  pros::delay(2500);
  moveDistance(58_in);
  flipperController.setMaxVelocity(20);
  flipperController.setTarget(50);
  driveController.turnAngle(95_deg);
  flipperController.setTarget(105);
  flipperController.setMaxVelocity(200);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  liftController.waitUntilSettled();
  driveController.turnAngle(-95_deg);
  moveDistance(37.5_in, true);
  driveController.turnAngle(95_deg);
  liftController.setTarget(PLATFORM_LIFT_HEIGHT);
  transmission.set_value(0);
  driveController.forward(-1);
  pros::delay(2200);
  driveController.stop();
}

void autoBlueFront() {
  int turnSpeed = 120;
  catapult.set_value(1);
  removeSlack();
  pros::delay(100);
  driveController.turnAngle(15_deg);
  liftController.setTarget(280);
  flipperController.setTarget(120);
  moveDistance(36_in);
  moveDistance(6_in, true);
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  flipperController.waitUntilSettled();
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-90_deg);
  driveController.forward(-0.4);
  pros::delay(600);
  driveController.stop();
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  moveDistance(23_in);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  moveDistance(7_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-93_deg);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  moveDistance(35_in);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-95_deg);
  flipperController.setTarget(103);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  frontWithUltra();
  driveController.forward(0.02);
  // shaky shaky
  liftController.flipDisable();
  for (int i=0; i<4; i++){
    lift.moveVoltage(5000);
    pros::delay(120);
    lift.moveVoltage(-5000);
    pros::delay(100);
  }
  liftController.flipDisable();
  // end shaky shaky
  driveController.stop();
  liftController.setMaxVelocity(80);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  liftController.waitUntilSettled();
  // End place first cap
  driveController.setMaxVelocity(200);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-90_deg);
  moveDistance(12_in);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-95_deg);
  driveController.forward(-0.4);
  pros::delay(600);
  driveController.stop();
  flipperController.setTarget(120);
  moveDistance(28_in);
  driveController.setMaxVelocity(30);
  driveController.moveDistance(12_in);
  driveController.setMaxVelocity(200);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(90);
  flipperController.waitUntilSettled();
  moveDistance(28_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-95_deg);
  moveDistance(57_in);
  flipperController.setMaxVelocity(20);
  flipperController.setTarget(50);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-95_deg);
  flipperController.setTarget(105);
  flipperController.setMaxVelocity(200);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  frontWithUltra();
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-50);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(95_deg);
  moveDistance(37.5_in, true);
  driveController.setMaxVelocity(turnSpeed);
  driveController.turnAngle(-95_deg);
  liftController.setTarget(PLATFORM_LIFT_HEIGHT);
  transmission.set_value(0);
  driveController.forward(-1);
  pros::delay(4000);
  driveController.stop();
}

void autonomous() {
  autoBlueBack();
  pros::delay(1000000);
  switch (AUTO_SELECTOR) {
		case 0: {
			autoRedFront();
			break;
		}
		case 1: {
			autoRedBack();
			break;
		}
		case 2: {
			autoBlueFront();
			break;
		}
		case 3: {
			autoBlueBack();
			break;
		}
		default: {
			break;
		}
	}
}
