#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

#define INPUTSOUTS 8

enum state {
	A_NONE = 0,
	A_IDLE,
	A_WALK_RIGHT,
	A_WALK_LEFT,
	A_JUMP_NEUTRAL,
	A_JUMP_RIGHT,
	A_JUMP_LEFT,
	A_CROUCH,
	A_CROUCH_LEFT,
	A_CROUCH_RIGHT,
	A_ACTION
};

enum inputin {
	S_NONE = 0,
	S_LEFT_DOWN,
	S_RIGHT_DOWN,
	S_LEFT_AND_RIGHT, //delete with gamepad
	S_JUMP,
	S_JUMP_RIGHT,
	S_JUMP_LEFT,
	S_CROUCH_DOWN,
	S_CROUCH_RIGHT,
	S_CROUCH_LEFT,
	S_JUMP_AND_CROUCH, //delete with gamepad
};

enum inputout {
	SO_NONE = 0,
	SO_LEFT_UP,
	SO_RIGHT_UP,
	SO_CROUCH_UP,
	SO_JUMP_FINISH,
	SO_ACTION_FINISH
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:

	Mix_Chunk *jumpsound;
	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation walkright;
	Animation walkleft;
	Animation jump;
	Animation action;
	Animation crouch;
	Animation* current_animation;
	SDL_Rect shadowrect;



	int action_timer;
	int jump_timer;
	iPoint position;
	int mult;
	state actual;
	inputin inputstate[60];
	inputout inputstateout[INPUTSOUTS];
	Collider* body;
	Collider* attack;
};

#endif