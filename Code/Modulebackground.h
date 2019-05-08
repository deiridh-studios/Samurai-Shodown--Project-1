#ifndef _MODULEBACKGROUNG_H
#define _MODULEBACKGROUND_H
#include"Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "p2Point.h"

struct Mix_Chunk;
struct SDL_Texture;
struct Collider;

class ModuleBackground :public Module {
public:
	ModuleBackground();
	~ModuleBackground();
	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:
	Mix_Chunk* Ukyo;
	int scrollleft;
	int scrollright;
	int x1 = 0;
	Animation back;
	SDL_Texture* graphics = nullptr;
	Collider *camerarightcol;
	Collider *cameraleftcol;
	iPoint cameraright;
	iPoint cameraleft;
};
#endif //