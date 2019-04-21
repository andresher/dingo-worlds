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
   driveController.setMaxVoltage(200);
   profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{len, 0_ft, 0_deg}}, "A");
   profileController.setTarget("A");
   profileController.waitUntilSettled();
}

void moveDistance(QLength len, bool isBackwards) {
  driveController.setMaxVoltage(200);
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{len, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A", isBackwards);
  profileController.waitUntilSettled();
}

void frontWithUltra() {
  for (int i=0; i<100; i++) {
		ultrasonic.get();
	}
  while(ultrasonic.get() > 422.0) {
    driveController.forward(0.10);
  }
  driveController.stop();
}

void autoBlueBack() {
  catapult.set_value(1);
  removeSlack();
  pros::delay(100);
  // Get first cap
  driveController.setMaxVelocity(40);
  driveController.moveDistance(-5_in);
  pros::delay(100);
  driveController.turnAngle(-84_deg);
  pros::delay(100);
  liftController.setTarget(-20);
  flipperController.setTarget(120);
  driveController.setMaxVelocity(100);
  driveController.moveDistance(20_in);
  driveController.setMaxVelocity(30);
  driveController.moveDistance(12_in);
  pros::delay(100);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(80);
  flipperController.waitUntilSettled();
  driveController.setMaxVelocity(40);
  driveController.moveDistance(-18_in);
  driveController.turnAngle(-85_deg);
  pros::delay(100);
  driveController.moveDistance(10_in);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  driveController.moveDistance(11_in);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(40);
  driveController.moveDistance(-12_in);
  pros::delay(100);
  driveController.turnAngle(52_deg);
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  driveController.setMaxVelocity(60);
  driveController.moveDistance(18_in);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  driveController.moveDistance(-18_in);
  driveController.turnAngle(-140_deg);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  driveController.moveDistance(10_in);
  liftController.setMaxVelocity(600);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(40);
  driveController.moveDistance(10_in);
  flipperController.setTarget(110);
  flipperController.waitUntilSettled();
  pros::delay(500);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(120);
  driveController.turnAngle(-105_deg);
  flipperController.setTarget(120);
  driveController.setMaxVelocity(100);
  driveController.moveDistance(48_in);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  driveController.moveDistance(-5_in);
  driveController.turnAngle(100_deg);
  // Place 3rd
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(60);
  driveController.moveDistance(7_in);
  flipperController.setTarget(95);
  flipperController.waitUntilSettled();
  pros::delay(700);
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
  liftController.setMaxVelocity(150);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(80);
  driveController.moveDistance(-11_in);
  driveController.turnAngle(-90_deg);
  driveController.moveDistance(-12_in);
  driveController.turnAngle(90_deg);
  liftController.setTarget(PLATFORM_LIFT_HEIGHT);
  driveController.forward(-0.7);
  pros::delay(400);
  driveController.forward(1);
  pros::delay(300);
  driveController.forward(-1);
  pros::delay(2000);
  driveController.stop();
}

void autoRedBack() {
  catapult.set_value(1);
  removeSlack();
  pros::delay(100);
  // Get first cap
  driveController.turnAngle(95_deg);
  pros::delay(100);
  liftController.setTarget(-20);
  flipperController.setTarget(120);
  moveDistance(24_in);
  driveController.setMaxVelocity(30);
  driveController.moveDistance(12_in);
  driveController.setMaxVelocity(200);
  pros::delay(100);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(90);
  flipperController.waitUntilSettled();
  moveDistance(10.5_in, true);
  pros::delay(100);
  driveController.turnAngle(95_deg);
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
  moveDistance(12_in, true);
  pros::delay(100);
  driveController.turnAngle(-42_deg);
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  moveDistance(18_in);
  flipperController.setTarget(90);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  moveDistance(5_in, true);
  driveController.turnAngle(140_deg);
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
  liftController.setTarget(720);
  liftController.waitUntilSettled();
  frontWithUltra();
  driveController.forward(0.02);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  pros::delay(700);
  driveController.stop();
  liftController.setMaxVelocity(150);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  moveDistance(11_in, true);
  driveController.turnAngle(90_deg);
  moveDistance(12_in, true);
  driveController.turnAngle(-90_deg);
  liftController.setTarget(180);
  transmission.set_value(0);
  driveController.forward(-1);
  pros::delay(2000);
  driveController.stop();
}

void autoRedFront() {
  catapult.set_value(1);
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
  moveDistance(37_in);
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
  driveController.turnAngle(95_deg);
  moveDistance(58.5_in);
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
  catapult.set_value(1);
  removeSlack();
  pros::delay(100);
  driveController.turnAngle(15_deg);
  pros::delay(400);
  liftController.setTarget(280);
  flipperController.setTarget(120);
  driveController.setMaxVelocity(80);
  driveController.moveDistance(33_in);
  driveController.moveDistance(-9_in);
  pros::delay(200);
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  flipperController.waitUntilSettled();
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(70);
  driveController.turnAngle(-90_deg);
  driveController.moveDistance(-10_in);
  flipperController.setTarget(120);
  flipperController.waitUntilSettled();
  driveController.moveDistance(23_in);
  liftController.setTarget(100);
  liftController.waitUntilSettled();
  driveController.moveDistance(-6_in);
  driveController.setMaxVelocity(40);
  driveController.turnAngle(-92_deg);
  driveController.setMaxVelocity(70);
  flipperController.setTarget(0);
  flipperController.waitUntilSettled();
  driveController.moveDistance(33_in);
  driveController.turnAngle(-92_deg);
  flipperController.setTarget(98);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(200);
  liftController.setTarget(HIGH_GOAL_HEIGHT);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(20);
  driveController.moveDistance(10_in);
  pros::delay(700);
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
  liftController.setMaxVelocity(80);
  liftController.setTarget(150);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  // End place first cap
  driveController.setMaxVelocity(70);
  driveController.turnAngle(-94_deg);
  driveController.moveDistance(10_in);
  driveController.turnAngle(-90_deg);
  driveController.forward(-0.7);
  pros::delay(1000);
  driveController.stop();
  flipperController.setTarget(120);
  driveController.setMaxVelocity(70);
  driveController.moveDistance(28_in);
  driveController.setMaxVelocity(30);
  driveController.moveDistance(12_in);
  pros::delay(100);
  liftController.setMaxVelocity(50);
  flipperController.setTarget(80);
  flipperController.waitUntilSettled();
  driveController.setMaxVelocity(40);
  driveController.moveDistance(-28_in);
  driveController.turnAngle(-90_deg);
  driveController.setMaxVelocity(70);
  driveController.moveDistance(57_in);
  driveController.turnAngle(-90_deg);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(30);
  driveController.moveDistance(9_in);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
}

void autonomous() {
  autoRedBack();
}
