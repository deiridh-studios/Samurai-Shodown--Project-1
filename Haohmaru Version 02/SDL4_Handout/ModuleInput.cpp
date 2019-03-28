#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
}

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
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);

	if(keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;
	if (keyboard[SDL_SCANCODE_UP]) {
		if (keyup == 0)  keyup = 1;
	}
	else keyup = 0;
	if (keyboard[SDL_SCANCODE_LEFT]) {
		if (keyleft == 0) keyleft = 1;
	}
	else keyleft = 0;
	if (keyboard[SDL_SCANCODE_RIGHT]) {
		if (keyright == 0) keyright = 1;
	}
	else keyright = 0;
	if (keyboard[SDL_SCANCODE_G]) {
		if (keyg == 0)  keyg = 1;
	}
	else/* if(keyg!=1)*/ keyg = 0;
	if (keyboard[SDL_SCANCODE_H]) {
		if (keyh == 0)  keyh = 1;
	}
	else keyh = 0;

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}