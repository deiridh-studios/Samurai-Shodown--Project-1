#ifndef __ModuleReferee_H__
#define __ModuleReferee_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleReferee : public Module{
public:
	ModuleReferee();
	~ModuleReferee();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
		

public:
	bool flip;
	SDL_Texture* graphics = nullptr;
	iPoint position;
	state actual;
	SDL_Rect rect;//WHEN IMPLEMENTED ANIMATION, THIS RECT WILL HAVE TO BE ELIMINATED
};

#endif