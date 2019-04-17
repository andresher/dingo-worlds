#include "main.h"
#include "robot.h"

// Extern init
bool TRANSMISSION_STATE = 0;
bool CATAPULT_STATE = 0;
bool BRAKE_STATE = 0;
int CURRENT_HEIGHT = 0;
int flipperState = 0;
int flipperInput = 0;

void flipperFSM(){
	int flipHeight = 20;
	int flipLow = lift.getPosition() > 300 ? 95 : 120;

	if (flipperState == 0) {
		flipperController.setTarget(0);
		if (flipperController.isSettled() && (flipperInput == 1 || flipperInput == 2)) {
			flipperState = 1;
			flipperInput = 0;
		}
	} else if (flipperState == 1) {
		flipperController.setTarget(flipLow);
		if (flipperController.isSettled() && flipperInput == 1) {
			flipperState = 3;
			flipperInput = 0;
		} else if (flipperController.isSettled() && flipperInput == 2) {
			flipperState = 4;
			flipperInput = 0;
		}
	} else if (flipperState == 3) {
		flipperController.setTarget(flipHeight);
		if (flipperController.isSettled()) {
			flipperState = 1;
		}
	} else if (flipperState == 4) {
		flipperController.setTarget(0);
    if (flipperController.isSettled() && (flipperInput == 1 || flipperInput == 2)) {
			flipperState = 1;
			flipperInput = 0;
		}
	}
}

// void alignStep(int vel, int line) {
// 	auto driveControllerL = AsyncControllerFactory::velIntegrated(
// 		{DRIVE_LEFT_1,DRIVE_LEFT_2, DRIVE_LEFT_3});
// 	auto driveControllerR = AsyncControllerFactory::velIntegrated(
// 		{DRIVE_RIGTH_1, DRIVE_RIGTH_2, DRIVE_RIGTH_3});
//   bool seenLineR = false;
//   bool seenLineL = false;
//   driveControllerR.setTarget(vel);
//   driveControllerL.setTarget(vel);
//   while (!seenLineR || !seenLineL) {
//     if (linetrackerR.get_value() < line && !seenLineR) {
//       seenLineR = true;
//       printf("LINE RIGTH at vel %f\n", driveR.getActualVelocity());
//     }
//     if (linetrackerL.get_value() < line && !seenLineL) {
//       seenLineL = true;
//       printf("LINE LEFT at vel %f\n", driveL.getActualVelocity());
//     }
//     if (seenLineR) {
//       driveControllerR.setTarget(0);
//     }
//     if (seenLineL) {
//       driveControllerL.setTarget(0);
//     }
//   }
//   driveControllerR.setTarget(0);
//   driveControllerL.setTarget(0);
// }
//
// void alignWithLine(int vel, int line, int alignSteps) {
//   alignStep(vel, line);
//   int fixvel = vel > 0 ? 30 : -30;
//   for (int i = 0; i < alignSteps; i++) {
//     if (!i%2) {
//       fixvel = -fixvel;
//     }
//     alignStep(fixvel, line);
// }

double map(double value, double low1, double high1, double low2, double high2) {
	if (value < low1) {
		value = low1;
	} else if (value > high1) {
		value = high1;
	}
  return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}
