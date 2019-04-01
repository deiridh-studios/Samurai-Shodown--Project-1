#ifndef _MODULESCENEEARTHQUAKE_H
#define _MODULESCENEEARTHQUAKE_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

struct Mix_Chunk;

class ModuleSceneEarthquake :public Module {
public:
	ModuleSceneEarthquake();
	~ModuleSceneEarthquake();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Chunk* earthquake;
	SDL_Rect rectbackground;
	int scrollleft;
	int scrollright;
	int x1 = 0;
	Animation backearthquake;
	SDL_Texture* graphics = nullptr;
};
#endif //