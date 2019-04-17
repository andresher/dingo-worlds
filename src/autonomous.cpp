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
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{len, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
}

void autoBlue1() {
  catapult.set_value(0);
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
  liftController.setMaxVelocity(150);
  liftController.setTarget(540);
  liftController.waitUntilSettled();
  driveController.moveDistance(11_in);
  flipperController.setTarget(100);
  flipperController.waitUntilSettled();
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
  flipperController.setTarget(97);
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
  driveController.moveDistance(-3_in);
  driveController.turnAngle(100_deg);
  // Place 3rd
  liftController.setMaxVelocity(200);
  liftController.setTarget(720);
  liftController.waitUntilSettled();
  driveController.moveDistance(6_in);
  flipperController.setTarget(105);
  flipperController.waitUntilSettled();
  pros::delay(500);
  liftController.setMaxVelocity(70);
  liftController.setTarget(200);
  liftController.waitUntilSettled();
  flipperController.setTarget(0);
  liftController.setTarget(-20);
  liftController.waitUntilSettled();
  driveController.moveDistance(-8_in);
  driveController.turnAngle(-90_deg);
  driveController.moveDistance(-10_in);
  driveController.turnAngle(90_deg);
  driveController.forward(1);
  pros::delay(100);
  driveController.forward(-1);
  pros::delay(2000);
  driveController.stop();
  // flipperController.setTarget(0);
  // flipperController.waitUntilSettled();
  // pros::delay(200);
  // driveController.setMaxVelocity(60);
  // driveController.moveDistance(-14_in);
  // driveController.setMaxVelocity(600);
  // driveController.turnAngle(-90_deg);
}

void autonomous() {
  autoBlue1();
}
