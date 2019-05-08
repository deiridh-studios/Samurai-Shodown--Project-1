#ifndef __ModuleUkyoPlayer2_H__
#define __ModuleUkyoPlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "p2Point.h"

#define INPUTSOUTS 8

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

class ModuleUkyoPlayer2 : public Module
{
public:
	ModuleUkyoPlayer2();
	~ModuleUkyoPlayer2();

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
	Mix_Chunk *hittedsound;
	Mix_Chunk *tornadosound;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation jump;
	Animation jumpforward;
	Animation jumpbackward;
	Animation tornado;
	Animation hittedan;
	Animation crouch;
	Animation punchair;
	Animation punchcrouch;
	Animation kickair;
	Animation kickcrouch;

	iPoint position;
	Collider* bodyenemy;
	Collider* bodyenemy2;
	Collider* bodyenemy3;
	Collider* enemyattack;
	int mult;
	state actualukyo3;
	inputin inputstateukyo2[60];
	inputout inputstateoutukyo2[6];
	/*enum action {
		NONE = 0,
		PUNCH,
		CROUCH,
		KICK
	}actual = action::NONE;*/
	int inputsouts;
	Uint32 jump_timer;
	int punch_timer;
	int kick_timer;
	int tornado_timer;
	int hitted_timer;
	//bool right;
	//bool left;
	bool victory;
	bool stopleft;
	bool flip;
	bool stopright;
};
#endif