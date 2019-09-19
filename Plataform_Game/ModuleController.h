#ifndef __ModuleController_H__
#define __ModuleController_H__

#include "Module.h"
#include "Globals.h"


struct _SDL_GameController;

class ModuleController : public Module {
public:
	ModuleController();
	~ModuleController();
	bool Start();
	bool CleanUp();
	update_status PreUpdate();


public:
	_SDL_GameController *controller[2];
	bool buttonstate[2][12];
	float axisstate[2][6];
	int numjoystick;
	int mapping;

};
#endif