#include "main.h"
#include "robot.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// Gyro: port G
// Line Follower Izq E
// Line Follower Der F

Controller controller;
ControllerButton bumperRightUp(ControllerDigital::R1);
ControllerButton bumperRigthDown(ControllerDigital::R2);
ControllerButton bumperLeftUp(ControllerDigital::L1);
ControllerButton bumperLeftDown(ControllerDigital::L2);
ControllerButton up(ControllerDigital::up);
ControllerButton down(ControllerDigital::down);
ControllerButton A(ControllerDigital::A);
ControllerButton B(ControllerDigital::B);
ControllerButton X(ControllerDigital::X);
ControllerButton Y(ControllerDigital::Y);
void opcontrol() {
	while (true) {
		printf("ultra = %f\n", ultrasonic.get());
		// Drive
		if (lift.getPosition() > 300) {
			driveController.arcade(
				controller.getAnalog(ControllerAnalog::leftY) * 0.5,
				controller.getAnalog(ControllerAnalog::leftX) * 0.5
			);
		} else {
			driveController.arcade(
				controller.getAnalog(ControllerAnalog::leftY),
				controller.getAnalog(ControllerAnalog::leftX)
			);
		}

    // Flipper
		flipperFSM();
		if(bumperRightUp.changedToPressed()) {
			flipperInput = 1;
		} else if (bumperRigthDown.changedToPressed()) {
			flipperInput = 2;
		}

    // Transmission
    if (bumperLeftUp.changedToPressed()) {
         TRANSMISSION_STATE = !TRANSMISSION_STATE;
         transmission.set_value(TRANSMISSION_STATE);
    }

    // Catapult
    if (up.changedToPressed()) {
         CATAPULT_STATE = !CATAPULT_STATE;
         catapult.set_value(CATAPULT_STATE);
    }

    // brake
    if (down.changedToPressed()) {
         BRAKE_STATE = !BRAKE_STATE;
         brake.set_value(BRAKE_STATE);
    }

    // Lift
		if (bumperLeftDown.isPressed()) {
			if (B.changedToPressed())      //Press button to go to raise lift to height
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(CAP_PLATFORM_LIFT_HEIGHT);
				 CURRENT_HEIGHT = CAP_PLATFORM_LIFT_HEIGHT;
			 }
			 else if (A.changedToPressed())
			 {
					if(liftController.isDisabled()){
						liftController.flipDisable();
					}
					liftController.setTarget(LOW_GOAL_HEIGHT-DROP_HEIGHT-20);
					CURRENT_HEIGHT = LOW_GOAL_HEIGHT-DROP_HEIGHT-20;
				}
			 else if (X.changedToPressed())
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(HIGH_GOAL_HEIGHT-DROP_HEIGHT);
				 CURRENT_HEIGHT = HIGH_GOAL_HEIGHT-DROP_HEIGHT;
			 }
			 else if (Y.changedToPressed() && (CURRENT_HEIGHT >= DROP_HEIGHT))
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(CURRENT_HEIGHT-DROP_HEIGHT);      //Drop lift a bit to place cap on post
			 }
			 else if ( abs(controller.getAnalog(ControllerAnalog::rightY)) > 0.1) {
				 if(!liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 lift.moveVoltage(12000*controller.getAnalog(ControllerAnalog::rightY));
			 } else if (liftController.isDisabled() && abs(controller.getAnalog(ControllerAnalog::rightY)) <= 0.1) {
				 lift.moveVoltage(0);
			 }
		} else {
			if (B.changedToPressed())      //Press button to go to raise lift to height
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(STARTING_HEIGHT);
				 CURRENT_HEIGHT = STARTING_HEIGHT;
			 }
			 else if (A.changedToPressed())
			 {
					if(liftController.isDisabled()){
						liftController.flipDisable();
					}
					liftController.setTarget(LOW_GOAL_HEIGHT);
					CURRENT_HEIGHT = LOW_GOAL_HEIGHT;
				}
			 else if (X.changedToPressed())
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(HIGH_GOAL_HEIGHT);
				 CURRENT_HEIGHT = HIGH_GOAL_HEIGHT;
			 }
			 else if (Y.changedToPressed() && (CURRENT_HEIGHT >= DROP_HEIGHT))
			 {
				 if(liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 liftController.setTarget(CURRENT_HEIGHT-DROP_HEIGHT);      //Drop lift a bit to place cap on post
			 }
			 else if ( abs(controller.getAnalog(ControllerAnalog::rightY)) > 0.1) {
				 if(!liftController.isDisabled()){
					 liftController.flipDisable();
				 }
				 lift.moveVoltage(12000*controller.getAnalog(ControllerAnalog::rightY));
			 } else if (liftController.isDisabled() && abs(controller.getAnalog(ControllerAnalog::rightY)) <= 0.1) {
				 lift.moveVoltage(0);
			 }
		}


     pros::delay(20);
	}
}
