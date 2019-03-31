#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
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
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);
	for (int i = 4; i < 285; i++) {
		if (keyboard[i] == 1) {
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
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}