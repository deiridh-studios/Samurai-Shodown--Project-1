#ifndef _MODULESCENEONE_H
#define _MODULESCENEONE_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "p2Point.h"

struct Mix_Chunk;
struct SDL_Texture;
struct Collider;

class ModuleSceneOne :public Module {
public:
	ModuleSceneOne();
	~ModuleSceneOne();
	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:
	Mix_Chunk* Ukyo;
	int scrollleft;
	int scrollright;
	bool fade;
	int x1 = 0;

	Animation back;

	SDL_Texture* graphics = nullptr;
	Collider *camerarightcol;
	Collider *cameraleftcol;
	iPoint cameraright;
	iPoint cameraleft;
};
#endif //