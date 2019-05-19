#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "Modulebackground.h"
#include "ModuleUI.h"
#include "StateMachine.h"
#include "SDL/include/SDL_timer.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 200;
	position.y = 210;

	//Shadow animation
	shadow.PushBack({ 2005, 411, 70, 14 });
	shadow.PushBack({ 2005, 425, 70, 14 });
	shadow.speed = 0.4f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites//UkyoPlayer2SpriteSheet.png"); // arcade version
	graphics2 = App->textures->Load("sprites/spritesHaohmaruFIXED.png");
	position.x = 200;
	position.y = 210;
	bodyenemy = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_ENEMY, this);
	bodyenemy2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_ENEMY, this);
	bodyenemy3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_ENEMY, this);
	actual3 = A_IDLE;
	victory = false;
	for (int i = 0; i < 60; i++) inputstate2[i] = S_NONE;
	for (int i = 0; i < 6; i++)inputstateout2[i] = SO_NONE;
	jump_timer = 0;
	punch_timer = 0;
	kick_timer = 0;
	tornado_timer = 0;
	inputsouts = 0;
	victory = false;
	flip = true;
	stopleft = stopright = false;
	return ret;
}

//Clean Up
bool ModulePlayer2::CleanUp() {
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->audio->StopChunk();
	return true;
}

update_status ModulePlayer2::PreUpdate() {
	if (position.x > App->player->position.x && position.y == 210)flip = true;
	else if (position.x < App->player->position.x&&position.y == 210) {
		flip = false;
	}
	for (int i = 59; i > 0; i--)inputstate2[i] = inputstate2[i - 1];
	inputstate2[0] = S_NONE;
	for (int i = 0; i < INPUTSOUTS; i++) inputstateout2[i] = SO_NONE;
	inputsouts = 0;
	Preupdate(jump_timer, punch_timer, kick_timer, tornado_timer, hitted_timer, inputsouts, position, flip, actual3, inputstate2, inputstateout2, App->player2);
	CheckSpecialAttacks(inputstate2);
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	//Animation* current_animation = &App->player->idle;
	int speed = 2;
	CheckState(jump_timer, punch_timer, kick_timer, tornado_timer, inputsouts, actual3, inputstate2, inputstateout2);

	

	

	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F6] == KEY_PUSHED) {
		if (bodyenemy->to_delete != false) {
			bodyenemy = App->collision->AddCollider({ position.x,(position.y - 100),35,20 }, COLLIDER_ENEMY, this);
			bodyenemy2 = App->collision->AddCollider({ position.x,(position.y - 50),25,15 }, COLLIDER_ENEMY, this);
			bodyenemy3 = App->collision->AddCollider({ position.x,(position.y - 20),45,35 }, COLLIDER_ENEMY, this);
		}
		else {
			bodyenemy->to_delete = true;
			bodyenemy2->to_delete = true;
			bodyenemy3->to_delete = true;
		}

	}

	// Draw everything --------------------------------------
	SDL_Rect r = ExecuteState(jump_timer, punch_timer, kick_timer, tornado_timer, hitted_timer, actual3, flip, speed, mult, stopright, stopleft, *bodyenemy, *bodyenemy2, *bodyenemy3, &enemyattack, position, App->player2)->GetCurrentFrame();


	if (flip == false) {
		App->render->Blit(graphics, App->player2->position.x + 6, 202, &(shadow.GetCurrentFrame()), 1.0f, true, false, App->render->zoom);
	}
	if (flip == true) {
		App->render->Blit(graphics, App->player2->position.x, 202, &(shadow.GetCurrentFrame()), 1.0f, true, false, App->render->zoom);
	}
	
	if (actual3 != A_TORNADO) {
		if (flip == false)	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, false, App->render->zoom);
		else App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true, App->render->zoom);
	}
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);



	return UPDATE_CONTINUE;
}

update_status ModulePlayer2::PostUpdate() {
	stopright = false;
	stopleft = false;
	return UPDATE_CONTINUE;
}


void ModulePlayer2::OnCollision(Collider* enemy, Collider* other) {
	//
	if (enemy->type == COLLIDER_ENEMY) {
		if (other->type == COLLIDER_PLAYER_SHOT) {
			actual3 = A_HITTED;
			if (hitted_timer == 0)hitted_timer = 1;
		}
			if (other->type == COLLIDER_WALL_LEFT) {
			stopleft = true;
		}
		if (other->type == COLLIDER_WALL_RIGHT) {
			stopright = true;
		}
		if (other->type == COLLIDER_PLAYER) {
			if (flip == false && App->player->stopright == true) {
				stopright = true;
				if (position.y > 200 && position.y < 210 && mult == -2)position.x-=5;
			}
			else if (flip == true && App->player->stopleft == true) {
				stopleft = true;
				if (position.y > 200 && position.y < 210 && mult == -2)position.x += 5;
			}
			else if (actual3 == A_WALK_FORWARD) {
				if (flip == false) App->player->position.x++;
				else App->player->position.x--;
			}
			else if (actual3 == A_JUMP_FORWARD && App->player->position.y < 210) {
				if (App->player->actual == A_JUMP_FORWARD) {
					if (flip == false)stopright = true;
					else stopleft = true;
				}
				else {
					if (flip == false)App->player->position.x++;
					else App->player->position.x--;
				}
			}
			else if (position.y > 200 && position.y < 210 && mult == -2 && App->player->position.y == 210) {
				if (flip == false) {
					App->player->position.x++;
					position.x--;
				}
				else {
					App->player->position.x--;
					position.x++;
				}
			}
		}
	}
	else {
		if (other->type == COLLIDER_PLAYER) enemy->to_delete = true;
	}
}