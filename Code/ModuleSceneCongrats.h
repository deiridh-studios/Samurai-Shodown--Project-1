#ifndef _MODULESCENECONGRATS_H
#define _MODULESCENECONGRATS_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "Globals.h"

class ModuleSceneCongrats :public Module {
public:
	ModuleSceneCongrats();
	~ModuleSceneCongrats();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect rectbackground;
	SDL_Texture* graphics = nullptr;
	int font_victory;
	char victory_text[2];
};
#endif //