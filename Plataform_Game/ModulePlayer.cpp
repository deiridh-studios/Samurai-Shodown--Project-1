#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "../Plataform_Game/ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleSceneOne.h"
#include "SDL/include/SDL_timer.h"


ModulePlayer::ModulePlayer ()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 0, 0, 75, 137 });
	idle.PushBack({ 75, 0, 75, 137 });
	idle.speed = 0.02f;
	
	// Walk forward animation
	walkright.PushBack({ 185, 0, 75, 137 });
	walkright.PushBack({ 260, 0, 72, 137 });
	walkright.PushBack({ 332, 0, 81, 137 });
	walkright.PushBack({ 413, 0, 87, 137 });
	walkright.PushBack({ 500, 0, 81, 137 });
	walkright.PushBack({ 581, 0, 72, 137 });
	walkright.PushBack({ 653, 0, 75, 137 });
	walkright.speed = 0.2f;
	
	// Walk backwards animation
	walkleft.PushBack({ 653, 0, 75, 137 });
	walkleft.PushBack({ 581, 0, 72, 137 });
	walkleft.PushBack({ 500, 0, 81, 137 });
	walkleft.PushBack({ 413, 0, 87, 137 });
	walkleft.PushBack({ 332, 0, 81, 137 });
	walkleft.PushBack({ 260, 0, 72, 137 });
	walkleft.PushBack({ 185, 0, 75, 137 });
	walkleft.speed = 0.2f;

	//crouch
	crouch.PushBack({ 1243 , 274 , 75 , 137 });
	crouch.PushBack({ 1318 , 274 , 68 , 137 });
	crouch.PushBack({ 1386 , 274 , 67 , 137 });
	crouch.speed = 0.2f;

	// ACTION animation (TO IMPROVE)
	action.PushBack({ 0, 274, 76, 137 });
	action.PushBack({ 117, 274, 75, 137 });
	action.PushBack({ 234, 274, 75, 137 });
	action.PushBack({ 351, 274, 102, 137 });
	action.PushBack({ 468, 274, 117, 137 });
	action.PushBack({ 351, 274, 102, 137 });
	action.PushBack({ 234, 274, 75, 137 });
	action.PushBack({ 117, 274, 75, 137 });
	action.PushBack({ 0, 274, 76, 137 });
	action.speed = 0.4f;

	// Jump
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1106, 0, 63, 137 });
	jump.PushBack({ 1040, 0, 66, 137 });
	jump.PushBack({ 979, 0, 61, 137 });
	jump.PushBack({ 904, 0, 75, 137 });
	jump.PushBack({ 836, 0, 68, 137 });
	jump.PushBack({ 761, 0, 75, 137 });
	jump.speed = 0.12f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/UkyoPlayer1SpriteSheet.png");
	jumpsound = App->audio->LoadChunk("Audio_FX/Punch.wav");

	position.x = 40;
	position.y = 210;

	body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);

	jump_timer = 0;
	action_timer = 0;
	return 0;
}

//Clean Up
bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphics);
	App->audio->UnLoadChunk(jumpsound);
	return true;
}

update_status ModulePlayer::PreUpdate() {
	
	return UPDATE_CONTINUE;
}


// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;
	int speed = 2;

	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F5] == KEY_PUSHED) {
		if (body->to_delete != false) {
			body = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_PLAYER, this);
		}
		else {
			body->to_delete = true;
		}
	}

	///////////////DRAW EVERYTHING////////////////////


	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* player, Collider* other) {
	/*
	if (player->type == COLLIDER_PLAYER) {
		if (other->type == COLLIDER_ENEMY_SHOT) {
			if (position.y == 210)actual = A_HITTED;
			else actual = A_HITTED_JUMP;
			if (hitted_timer == 0) {
				hitted_timer = 1;
				App->slowdown->StartSlowdown(100, 60);
			}
		}
	}
	*/
}