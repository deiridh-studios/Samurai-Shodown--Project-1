#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "p2Point.h"

#define INPUTSOUTS 7

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
	void CheckState();
	void CheckSpecialAttacks();

public:

	Mix_Chunk *punchsound;
	Mix_Chunk *jumpsound;
	Mix_Chunk *kicksound;
	Mix_Chunk *hitted;
	Mix_Chunk *tornadosound;
	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation crouch;
	Animation jump;
	Animation tornado;

	iPoint position;
	Collider* bodyenemy;
	int mult;
	state actual3;
	inputin inputstate2[60];
	inputout inputstateout2[6];
	enum action {
		NONE = 0,
		PUNCH,
		CROUCH,
		KICK
	}actual = action::NONE;
	int inputsouts;
	Uint32 jump_timer;
	int punch_timer;
	int kick_timer;
	int tornado_timer;
	bool right;
	bool left;
	bool victory;
};
#endif