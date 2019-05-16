#include "Globals.h"
#include "Application.h"
#include "ModuleController.h"
#include "SDL/include/SDL.h"

ModuleController::ModuleController() {
	SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
	for(int i=0;i<2;i++)controller[i] = NULL;
}

ModuleController::~ModuleController() {
}

bool ModuleController::Start() {
	numjoystick = SDL_NumJoysticks();
	for (int i = 0; i < numjoystick; ++i) {
		if (SDL_IsGameController(i) == SDL_TRUE) {
			controller[i] = SDL_GameControllerOpen(i);
			if (controller[i]==NULL) {
				LOG("Could not open gamecontroller %i: %s\n", i, SDL_GetError());
				return false;
			}
		}
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
	/*SDL_Event controllerevent[2];
	bool finish = false;
	for (int i = 0; i < 2; i++) {
		//SDL_PollEvent(&controllerevent[i]);
		if (controllerevent[i].type == SDL_CONTROLLERDEVICEADDED) {
			for (int j = 0; j < numjoystick; j++) {
				if (controller[j] == NULL&&finish==false) {
					if (SDL_IsGameController(j) == SDL_TRUE) controller[j] = SDL_GameControllerOpen(j);
					LOG("Game Controller Added\n\n\n");
					finish = true;
				}
			}
		}
		else if (controllerevent[i].type == SDL_CONTROLLERDEVICEREMOVED) {
			for (int j = 0; j < numjoystick; j++) {
				if (controller[j] != NULL&&finish==false) {
					SDL_GameControllerClose(controller[j]);
					LOG("Game Controller Removed\n\n\n");
					finish = true;
				}
			}
		}
	}*/
	//SDL_PumpEvents();
	
	for (int i = 0; i < numjoystick; i++) {
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
	}
	return UPDATE_CONTINUE;
}

bool ModuleController::CleanUp() {
	for (int i = 0; i < numjoystick; ++i) {
		if (controller[i] != NULL)SDL_GameControllerClose(controller[i]);
	}
	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
	return true;
}