#ifndef __ModuleUkyoPlayer1_H__
#define __ModuleUkyoPlayer1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;

#define INPUTSOUTS 8

enum action {
	NONE = 0,
	PUNCH,
	KICK,
	TORNADO,
	HITTED,
	CROUCH,
	PUNCHAIR,
	PUNCHCROUCH,
	KICKAIR
};

enum state {
	A_NONE = 0,
	A_IDLE,
	A_WALK_FORWARD,
	A_WALK_BACKWARD,
	A_JUMP_NEUTRAL,
	/*
	A_JUMP_FORWARD,
	A_JUMP_BACKWARD,
	A_CROUCH,
	A_PUNCH_STANDING,
	A_PUNCH_NEUTRAL_JUMP,
	A_PUNCH_FORWARD_JUMP,
	A_PUNCH_BACKWARD_JUMP,
	A_PUNCH_CROUCH,
	A_KICK_STANDING,
	A_KICK_NEUTRAL_JUMP,
	A_KICK_FORWARD_JUMP,
	A_KICK_BACKWARD_JUMP,
	A_KICK_CROUCH,
	A_TORNADO,
	A_HITTED
	*/
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
	S_JUMP_AND_CROUCH, //delete with gamepad
	S_T,
	S_Y,
	S_T_LEFT,
	S_T_RIGHT,
	S_T_JUMP,
	S_T_JUMP_RIGHT,
	S_T_JUMP_LEFT,
	S_T_CROUCH,
	S_T_CROUCH_RIGHT,
	S_Y_LEFT,
	S_Y_RIGHT,
	S_Y_JUMP,
	S_Y_JUMP_RIGHT,
	S_Y_JUMP_LEFT,
	S_Y_CROUCH,
	S_Y_CROUCH_RIGHT,
	S_TORNADO
};

enum inputout {
	SO_NONE = 0,
	SO_LEFT_UP,
	SO_RIGHT_UP,
	SO_CROUCH_UP,
	SO_JUMP_FINISH,
	SO_PUNCH_FINISH,
	SO_KICK_FINISH,
	SO_TORNADO_FINISH,
	SO_HITTED_FINISH
};

class ModuleUkyoPlayer1 : public Module
{
public:
	ModuleUkyoPlayer1();
	~ModuleUkyoPlayer1();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);
	void CheckState();
	void CheckSpecialAttacks();

public:
	//Sounds
	/*
	Mix_Chunk *punchsound;
	Mix_Chunk *jumpsound;
	Mix_Chunk *kicksound;
	Mix_Chunk *hittedsound;
	Mix_Chunk *tornadosound;
	*/
	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	//Animations
	/*
	Animation punch;
	Animation kick;
	Animation jumpforward;
	Animation jumpbackward;
	Animation tornado;
	Animation hittedan;
	Animation crouch;
	Animation punchair;
	Animation punchcrouch;
	Animation kickair;
	Animation kickcrouch;
	*/

	iPoint position;
	int mult;
	state actual;
	inputin inputstate[60];
	inputout inputstateout[INPUTSOUTS];
	Collider* body;
	Collider* body2;
	Collider* body3;
	Collider* attack;
	Uint32 jump_timer;
	int punch_timer;
	int kick_timer;
	int tornado_timer;
	int hitted_timer;
	int inputsouts;
	bool victory;
	bool flip;
	bool stopleft;
	bool stopright;
};

#endif