#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

typedef unsigned char Uint8;
enum keystate {
	KEY_OUT = 0,
	KEY_PUSHED,
	KEY_PULLED,
	KEY_REPEAT,
};


class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	const Uint8 *keyboard = nullptr;
	bool space;
	bool keyboard2[285];
	keystate keyboardstate[285];
};

#endif // __ModuleInput_H__