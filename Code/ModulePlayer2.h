#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "p2Point.h"

#define INPUTSOUTS 8

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:


	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;

	iPoint position;
	Collider* bodyenemy;
	Collider* bodyenemy2;
	Collider* bodyenemy3;
	Collider* enemyattack;
	int mult;
	state actual3;
	inputin inputstate2[60];
	inputout inputstateout2[INPUTSOUTS];
	int inputsouts;
	int jump_timer;
	int punch_timer;
	int kick_timer;
	int tornado_timer;
	int hitted_timer;
	bool victory;
	bool stopleft;
	bool flip;
	bool stopright;
};
#endif