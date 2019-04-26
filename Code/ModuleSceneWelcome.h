#ifndef _MODULESCENEWELCOME_H
#define _MODULESCENEWELCOME_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSceneWelcome :public Module {
public:
	ModuleSceneWelcome();
	~ModuleSceneWelcome();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect rectbackground;
	SDL_Rect recttitle;
	SDL_Texture* graphics = nullptr;
	Animation Words;
	Animation Title;
};
#endif //