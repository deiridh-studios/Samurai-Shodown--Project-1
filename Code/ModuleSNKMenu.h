#ifndef _MODULESNKMENU_H
#define _MODULESNKMENU_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSNKMenu :public Module {
public:
	ModuleSNKMenu();
	~ModuleSNKMenu();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Animation SNKMenu;
	SDL_Texture* graphics = nullptr;
};
#endif //