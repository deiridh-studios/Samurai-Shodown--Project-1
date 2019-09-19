#include "Globals.h"
#include "Application.h"
#include "ModuleController.h"
#include "SDL/include/SDL.h"

ModuleController::ModuleController() {
	SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
	for (int i = 0; i < 2; i++)controller[i] = NULL;
}

ModuleController::~ModuleController() {
}

bool ModuleController::Start() {
	numjoystick = SDL_NumJoysticks();
	for (int i = 0; i < numjoystick; ++i) {
		if (SDL_IsGameController(i) == SDL_TRUE) {
			controller[i] = SDL_GameControllerOpen(i);
			if (controller[i] == NULL) {
				LOG("Could not open gamecontroller %i: %s\n", i, SDL_GetError());
				return false;
			}
		}
		else return false;
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 12; ++j) {
			buttonstate[i][j] = false;
		}
		for (int j = 0; j < 6; ++j) {
			axisstate[i][j] = 0;
		}
	}
	return true;
}

update_status ModuleController::PreUpdate() {
	if (SDL_NumJoysticks() != numjoystick) {
		if (SDL_NumJoysticks() > numjoystick) {
			for (int i = 0; i < SDL_NumJoysticks(); ++i) {
				if (SDL_GameControllerGetAttached(controller[i]) == SDL_FALSE) {
					if (SDL_IsGameController(i) == SDL_TRUE) {
						controller[i] = SDL_GameControllerOpen(i);
						if (controller[i] == NULL) {
							LOG("Could not open gamecontroller %i: %s\n", i, SDL_GetError());
							return UPDATE_ERROR;
						}
					}
					else return UPDATE_ERROR;
				}
			}
		}
		else {
			for (int i = 0; i < numjoystick; ++i) {
				if (SDL_GameControllerGetAttached(controller[i]) == SDL_FALSE) {
					SDL_GameControllerClose(controller[i]);
					controller[i] == NULL;
				}
			}
		}
		numjoystick = SDL_NumJoysticks();
	}

	for (int i = 0; i < 2; i++) {
		buttonstate[i][0] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_A);
		buttonstate[i][1] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_B);
		buttonstate[i][2] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_X);
		buttonstate[i][3] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_Y);
		buttonstate[i][4] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_BACK);
		buttonstate[i][5] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_GUIDE);
		buttonstate[i][6] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_START);
		buttonstate[i][7] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_LEFTSTICK);
		buttonstate[i][8] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_RIGHTSTICK);
		buttonstate[i][9] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
		buttonstate[i][10] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
		buttonstate[i][11] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_DPAD_UP);
		buttonstate[i][12] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
		buttonstate[i][13] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
		buttonstate[i][14] = SDL_GameControllerGetButton(controller[i], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
		axisstate[i][0] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_LEFTX);
		axisstate[i][1] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_LEFTY);
		axisstate[i][2] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_RIGHTX);
		axisstate[i][3] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_RIGHTY);
		axisstate[i][4] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_TRIGGERLEFT);
		axisstate[i][5] = SDL_GameControllerGetAxis(controller[i], SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
		for (int j = 0; j < 6; j++) {
			axisstate[i][j] /= 32767;
		}
	}

	return UPDATE_CONTINUE;
}

bool ModuleController::CleanUp() {
	for (int i = 0; i < 2; ++i) {
		if (controller[i] != NULL)SDL_GameControllerClose(controller[i]);
	}
	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
	return true;
}