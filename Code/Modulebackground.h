#ifndef _MODULEBACKGROUNG_H
#define _MODULEBACKGROUND_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"

struct Mix_Chunk;
struct SDL_Texture;

class ModuleBackground :public Module {
public:
	ModuleBackground();
	~ModuleBackground();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Chunk* haohmaru;
	int scrollleft;
	int scrollright;
	int x1 = 0;
	Animation back;
	SDL_Texture* graphics = nullptr;
};
#endif //