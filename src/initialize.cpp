#include "main.h"
#include "robot.h"

void show_auto_name() {
	switch (AUTO_SELECTOR) {
		case 0: {
			pros::lcd::set_text(6, "AUTO RED FRONT");
			break;
		}
		case 1: {
			pros::lcd::set_text(6, "AUTO RED BACK");
			break;
		}
		case 2: {
			pros::lcd::set_text(6, "AUTO BLUE FRONT");
			break;
		}
		case 3: {
			pros::lcd::set_text(6, "AUTO BLUE BACK");
			break;
		}
		default: {
			pros::lcd::set_text(6, "NO AUTO HERE");
			break;
		}
	}
}

void on_right_button() {
	if (AUTO_SELECTOR < AUTO_ROUTINES - 1) {
		AUTO_SELECTOR++;
	} else {
		AUTO_SELECTOR = 0;
	}
	show_auto_name();
}

void on_left_button() {
	if (AUTO_SELECTOR > 0) {
		AUTO_SELECTOR--;
	} else {
		AUTO_SELECTOR = AUTO_ROUTINES - 1;
	}
	show_auto_name();
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "DINGO by AON Robotics");
	pros::lcd::set_text(3, "\"Think out of the box\"");
	pros::lcd::set_text(4, "- Eduardo Rodriguez");

	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn2_cb(on_right_button);
	show_auto_name();

	initUltrasonic();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
