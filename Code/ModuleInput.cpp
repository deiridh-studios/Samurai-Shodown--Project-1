#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleController.h"
#include "ModuleUI.h"
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

	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_START] == true || App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_START] == true)keyboard2[SDL_SCANCODE_SPACE] = 1;
	else keyboard2[SDL_SCANCODE_SPACE] = 0;
	if (App->controller->axisstate[0][SDL_CONTROLLER_AXIS_LEFTX] > 0.4) keyboard2[SDL_SCANCODE_D] = 1;
	else keyboard2[SDL_SCANCODE_D] = 0;
	if(App->controller->axisstate[0][SDL_CONTROLLER_AXIS_LEFTX] <-0.4) keyboard2[SDL_SCANCODE_A] = 1;
	else keyboard2[SDL_SCANCODE_A] = 0;
	if (App->controller->axisstate[1][SDL_CONTROLLER_AXIS_LEFTX] > 0.4) keyboard2[SDL_SCANCODE_RIGHT] = 1;
	else keyboard2[SDL_SCANCODE_RIGHT] = 0;
	if (App->controller->axisstate[1][SDL_CONTROLLER_AXIS_LEFTX] <-0.4) keyboard2[SDL_SCANCODE_LEFT] = 1;
	else keyboard2[SDL_SCANCODE_LEFT] = 0;
	if (App->controller->axisstate[0][SDL_CONTROLLER_AXIS_LEFTY] > 0.4/*6553.4 o +2*/) keyboard2[SDL_SCANCODE_S] = 1;
	else keyboard2[SDL_SCANCODE_S] = 0;
	if (App->controller->axisstate[0][SDL_CONTROLLER_AXIS_LEFTY] < -0.4) keyboard2[SDL_SCANCODE_W] = 1;
	else keyboard2[SDL_SCANCODE_W] = 0;
	if (App->controller->axisstate[1][SDL_CONTROLLER_AXIS_LEFTY] > 0.4) keyboard2[SDL_SCANCODE_DOWN] = 1;
	else keyboard2[SDL_SCANCODE_DOWN] = 0;
	if (App->controller->axisstate[1][SDL_CONTROLLER_AXIS_LEFTY] < -0.4) keyboard2[SDL_SCANCODE_UP] = 1;
	else keyboard2[SDL_SCANCODE_UP] = 0;
	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_Y] == true)keyboard2[SDL_SCANCODE_T] = 1;
	else keyboard2[SDL_SCANCODE_T] = 0;
	if (App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_Y] == true)keyboard2[SDL_SCANCODE_P] = 1;
	else keyboard2[SDL_SCANCODE_P] = 0;
	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_X] == true)keyboard2[SDL_SCANCODE_R] = 1;
	else keyboard2[SDL_SCANCODE_R] = 0;
	if (App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_X] == true)keyboard2[SDL_SCANCODE_O] = 1;
	else keyboard2[SDL_SCANCODE_O] = 0;
	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_B] == true)keyboard2[SDL_SCANCODE_U] = 1;
	else keyboard2[SDL_SCANCODE_U] = 0;
	if (App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_B] == true)keyboard2[SDL_SCANCODE_SEMICOLON] = 1;
	else keyboard2[SDL_SCANCODE_SEMICOLON] = 0;
	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_A] == true)keyboard2[SDL_SCANCODE_Y] = 1;
	else keyboard2[SDL_SCANCODE_Y] = 0;
	if (App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_A] == true)keyboard2[SDL_SCANCODE_L] = 1;
	else keyboard2[SDL_SCANCODE_L] = 0;
	if (App->controller->buttonstate[0][SDL_CONTROLLER_BUTTON_BACK] == true || App->controller->buttonstate[1][SDL_CONTROLLER_BUTTON_BACK] == true)keyboard2[SDL_SCANCODE_RETURN] = 1;
	else keyboard2[SDL_SCANCODE_RETURN] = 0;


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

	if (keyboardstate[SDL_SCANCODE_RETURN] == KEY_PUSHED) App->UI->credits++;

	
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}