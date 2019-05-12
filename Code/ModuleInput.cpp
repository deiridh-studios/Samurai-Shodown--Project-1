#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleController.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
		return ret;
	}
	LOG("Events initialized succesfully!\n\n");
	for (int i = 4; i < 285; i++) keyboardstate[i] = KEY_OUT;
	for (int i = 0; i < 285; i++)keyboard2[i] = false;
	space = false;
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_Event quitevent;
	SDL_PollEvent(&quitevent);
	if(quitevent.type==SDL_QUIT)return update_status::UPDATE_STOP;
	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);

	/////////////////CONTROLLER INPUT/////////////////////////

	if (App->controller->buttonstate[0][9] == true || App->controller->buttonstate[1][9] == true)keyboard2[44] = 1;
	else keyboard2[44] = 0;
	if (App->controller->axisstate[0][0] > 3276.7/*/ 32767 > 0.1*/) keyboard2[7] = 1;
	else keyboard2[7] = 0;
	if(App->controller->axisstate[0][0] <-3276.8/*/ 32768 < -0.1*/) keyboard2[4] = 1;
	else keyboard2[4] = 0;
	if (App->controller->axisstate[1][0] >3276.7/*/ 32767 > 0.1*/) keyboard2[79] = 1;
	else keyboard2[79] = 0;
	if (App->controller->axisstate[1][0] <-3276.8/*/ 32768 < -0.1*/) keyboard2[80] = 1;
	else keyboard2[80] = 0;



	for (int i = 4; i < 285; i++) {
		if (keyboard[i] == 1||keyboard2[i]==1) {
			if (keyboardstate[i] == KEY_PUSHED || keyboardstate[i]==KEY_REPEAT) keyboardstate[i] = KEY_REPEAT;
			else keyboardstate[i] = KEY_PUSHED;
		}
		else {
			if (keyboardstate[i] == KEY_PUSHED || keyboardstate[i] ==KEY_REPEAT) keyboardstate[i] = KEY_PULLED;
			else keyboardstate[i] = KEY_OUT;
		}
	}
	if (keyboardstate[SDL_SCANCODE_ESCAPE] == KEY_PUSHED) {
		LOG("Escape pressed, exiting the game.\n");
		return update_status::UPDATE_STOP;
	}
	if (keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED || keyboardstate[SDL_SCANCODE_SPACE] == KEY_REPEAT) space = true;
	else if (keyboardstate[SDL_SCANCODE_SPACE] == KEY_PULLED) space = false;


	
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}