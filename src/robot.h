#ifndef _ROBOT_
#define _ROBOT_

#include "main.h"

// Auto selector
extern int AUTO_SELECTOR;
const int AUTO_ROUTINES = 4;

// Lift definitions
const int STARTING_HEIGHT = 0;
const int LOW_GOAL_HEIGHT = 520;
const int HIGH_GOAL_HEIGHT = 700;
const int DROP_HEIGHT = 80;
const int PLATFORM_LIFT_HEIGHT = 180;
const int CAP_PLATFORM_LIFT_HEIGHT = 80;
extern int CURRENT_HEIGHT;

const int LIFT_MOTOR_1 = -18;
const int LIFT_MOTOR_2 = 19;
const int LIFT_MOTOR_3 = -10;

inline auto liftController = AsyncControllerFactory::posIntegrated(
   {LIFT_MOTOR_1, LIFT_MOTOR_2, LIFT_MOTOR_3}
);
inline MotorGroup lift({LIFT_MOTOR_1, LIFT_MOTOR_2, LIFT_MOTOR_3});

// Flipper Definitions
const int FLIPPER_MOTOR_1 = 17;
const int FLIPPER_MOTOR_2 = -9;
const int FLIPPER_MAX_RPM = 60;
inline auto flipperController = AsyncControllerFactory::posIntegrated(
  {FLIPPER_MOTOR_1, FLIPPER_MOTOR_2}, FLIPPER_MAX_RPM
);

extern int flipperState;
extern int flipperInput;
void flipperFSM(void);

// Drive definitions
const int DRIVE_LEFT_1 = 14;
const int DRIVE_LEFT_2 = -15;
const int DRIVE_LEFT_3 = 16;
const int DRIVE_RIGTH_1 = -11;
const int DRIVE_RIGTH_2 = 12;
const int DRIVE_RIGTH_3 = -13;

inline auto driveController = ChassisControllerFactory::create(
  {DRIVE_LEFT_1,DRIVE_LEFT_2, DRIVE_LEFT_3},
  {DRIVE_RIGTH_1, DRIVE_RIGTH_2, DRIVE_RIGTH_3},
  // IterativePosPIDController::Gains{0.0022, 0.001, 0.0001}, // Distance
  // IterativePosPIDController::Gains{0.001, 0.001, 0.0001}, // Straight
  // IterativePosPIDController::Gains{0.003, 0.001, 0.0001}, // Turn
  AbstractMotor::gearset::green * (3.0/5.0), // Speed
  {4_in, 12.75_in}
);

inline auto profileController = AsyncControllerFactory::motionProfile(
  2.0,  // Maximum linear velocity of the Chassis in m/s
  1.5,  // Maximum linear acceleration of the Chassis in m/s/s
  10.0, // Maximum linear jerk of the Chassis in m/s/s/s
  driveController // Chassis Controller
);

// Piston definitions
extern bool CATAPULT_STATE;
const int CATAPULT = 2;
inline pros::ADIDigitalOut catapult (CATAPULT);

extern bool TRANSMISSION_STATE;
const int TRANSMISSION = 3;
inline pros::ADIDigitalOut transmission (TRANSMISSION, true);

extern bool BRAKE_STATE;
const int BRAKE = 1;
inline pros::ADIDigitalOut brake (BRAKE);
inline ADIUltrasonic ultrasonic ('g', 'h'); // g = input, h = output

// Utilities
double map(double value, double low1, double high1, double low2, double high2);
void initUltrasonic();

#endif // _ROBOT_
