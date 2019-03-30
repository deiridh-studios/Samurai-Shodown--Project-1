#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

typedef unsigned char Uint8;

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
	enum keystate {
		KEY_PUSHED,
		KEY_PULLED,
		KEY_REPEAT,
		KEY_OUT
	};
	keystate keyboardstate[285];
};

#endif // __ModuleInput_H__