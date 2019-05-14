#ifndef _MODULESNKCOMPLETE_H_
#define _MODULESNKCOMPLETE_H_
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSNKComplete :public Module {
public:
	ModuleSNKComplete();
	~ModuleSNKComplete();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Animation Background;
	SDL_Texture* graphics = nullptr;
};
#endif //