#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	Mix_Chunk *punchsound;
	Mix_Chunk *jumpsound;
	Mix_Chunk *kicksound;
	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation jump;
	iPoint position;

	int mult;
	enum action {
		NONE,
		PUNCH,
		KICK
	}actual = action::NONE;

	bool right;
	bool left;
};
#endif