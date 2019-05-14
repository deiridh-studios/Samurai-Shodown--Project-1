#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
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
	/*App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	App->audio->UnLoadChunk(hittedsound);*/
	return true;
}

update_status ModulePlayer2::PreUpdate() {
	stopright = false;
	stopleft = false;
	if (position.x > App->player->position.x&&position.y == 210)flip = true;
	else if (position.x < App->player->position.x&&position.y == 210)flip = false;
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
	Animation* current_animation = &App->player->idle;
	int speed = 2;
	CheckState(jump_timer, punch_timer, kick_timer, tornado_timer, inputsouts, actual3, inputstate2, inputstateout2);
	//ExecuteState(jump_timer, punch_timer, kick_timer, tornado_timer, hitted_timer, actual3, flip, speed, mult, stopright, stopleft,*current_animation, *bodyenemy, *bodyenemy2, *bodyenemy3, enemyattack, position, App->player2);

	
	switch (actual3) {
	case A_IDLE:
		current_animation = &App->player->idle;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 20, (position.y - 57));
			bodyenemy3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 26, (position.y - 57));
			bodyenemy3->SetPos(position.x + 16, (position.y - 40));
		}

		break;
	case A_WALK_FORWARD:
		current_animation = &App->player->forward;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 20, (position.y - 57));
			bodyenemy3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 26, (position.y - 57));
			bodyenemy3->SetPos(position.x + 16, (position.y - 40));
		}

		if (flip == false) {
			if (stopright == false)position.x += speed;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraright.x + 1 > App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		else {
			if (stopleft == false)position.x -= speed;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		break;
	case A_WALK_BACKWARD:
		current_animation = &App->player->backward;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 20, (position.y - 57));
			bodyenemy3->SetPos(position.x + 10, (position.y - 40));
		}
		else {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 26, (position.y - 57));
			bodyenemy3->SetPos(position.x + 16, (position.y - 40));
		}

		if (flip == false) {
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;	
		}
		break;
	case A_JUMP_NEUTRAL:
		current_animation = &App->player->jump;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 90));
			bodyenemy2->SetPos(position.x + 12, (position.y - 69));
			bodyenemy3->SetPos(position.x + 5, (position.y - 55));
		}
		else {
			bodyenemy->SetPos(position.x + 35, (position.y - 90));
			bodyenemy2->SetPos(position.x + 42, (position.y - 69));
			bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		break;
	case A_JUMP_FORWARD:
		current_animation = &App->player->jumpforward;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 90));
			bodyenemy2->SetPos(position.x + 12, (position.y - 69));
			bodyenemy3->SetPos(position.x + 5, (position.y - 55));
		}
		else {
			bodyenemy->SetPos(position.x + 35, (position.y - 90));
			bodyenemy2->SetPos(position.x + 42, (position.y - 69));
			bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		else {
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		break;
	case A_JUMP_BACKWARD:
		current_animation = &App->player->jumpbackward;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 90));
			bodyenemy2->SetPos(position.x + 12, (position.y - 69));
			bodyenemy3->SetPos(position.x + 5, (position.y - 55));
		}
		else {

			bodyenemy->SetPos(position.x + 35, (position.y - 90));
			bodyenemy2->SetPos(position.x + 42, (position.y - 69));
			bodyenemy3->SetPos(position.x + 30, (position.y - 55));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		break;
	case A_CROUCH:
		current_animation = &App->player->crouch;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 50, (position.y - 70));
			bodyenemy2->SetPos(position.x + 67, (position.y - 54));
			bodyenemy3->SetPos(position.x + 47, (position.y - 40));
		}
		else {
			bodyenemy->SetPos(position.x + 15, (position.y - 70));
			bodyenemy2->SetPos(position.x + 8, (position.y - 54));
			bodyenemy3->SetPos(position.x + 8, (position.y - 40));
		}
		break;
	case A_PUNCH_STANDING:
		current_animation = &App->player->punch;
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			punch_timer = 2;
			if (flip == false) {
				enemyattack = App->collision->AddCollider({ position.x + 60,(position.y - 75),75,50 }, COLLIDER_ENEMY_SHOT, this);
			}
			else {
				position.x = position.x - 20;
				enemyattack = App->collision->AddCollider({ position.x,(position.y - 75),75,50 }, COLLIDER_ENEMY_SHOT, this);
			}
		}

		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			enemyattack->to_delete = true;
		}
		break;

	case A_PUNCH_NEUTRAL_JUMP:

		current_animation = &App->player->punchair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 50, (position.y - 120));
			bodyenemy2->SetPos(position.x + 52, (position.y - 99));
			bodyenemy3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			bodyenemy->SetPos(position.x + 50, (position.y - 120));
			bodyenemy2->SetPos(position.x + 52, (position.y - 99));
			bodyenemy3->SetPos(position.x + 45, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		if (punch_timer == 1) {
			position.x = position.x - 40;
			App->audio->PlayChunk(App->player->punchsound);
			enemyattack = App->collision->AddCollider({ position.x + 50,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			position.x = position.x + 40;
			enemyattack->to_delete = true;
		}
		break;
	case A_PUNCH_FORWARD_JUMP:
		current_animation = &App->player->punchair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 50, (position.y - 120));
			bodyenemy2->SetPos(position.x + 52, (position.y - 99));
			bodyenemy3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			bodyenemy->SetPos(position.x, (position.y - 120));
			bodyenemy2->SetPos(position.x, (position.y - 99));
			bodyenemy3->SetPos(position.x, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		else {
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			enemyattack = App->collision->AddCollider({ position.x + 70,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			enemyattack->to_delete = true;
			punch_timer = 3;
		}
		break;
	case A_PUNCH_BACKWARD_JUMP:
		current_animation = &App->player->punchair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 50, (position.y - 120));
			bodyenemy2->SetPos(position.x + 52, (position.y - 99));
			bodyenemy3->SetPos(position.x + 45, (position.y - 85));
		}
		else {
			bodyenemy->SetPos(position.x + 50, (position.y - 120));
			bodyenemy2->SetPos(position.x + 52, (position.y - 99));
			bodyenemy3->SetPos(position.x + 45, (position.y - 85));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (stopleft == false)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		else {
			if (stopright == false)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			enemyattack = App->collision->AddCollider({ position.x + 40,(position.y - 110),75,40 }, COLLIDER_ENEMY_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			enemyattack->to_delete = true;
			punch_timer = 3;
		}
		break;
	case A_PUNCH_CROUCH:
		current_animation = &App->player->punchcrouch;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 35, (position.y - 65));
			bodyenemy2->SetPos(position.x + 52, (position.y - 50));
			bodyenemy3->SetPos(position.x + 32, (position.y - 35));
		}
		else {
			bodyenemy->SetPos(position.x + 50, (position.y - 65));
			bodyenemy2->SetPos(position.x + 67, (position.y - 50));
			bodyenemy3->SetPos(position.x + 47, (position.y - 35));
		}

		if (punch_timer == 1) {
			App->audio->PlayChunk(App->player->punchsound);
			enemyattack = App->collision->AddCollider({ position.x + 50,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, this);
			punch_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			punch_timer = 3;
			enemyattack->to_delete = true;
		}
		break;
	case A_KICK_STANDING:
		current_animation = &App->player->kick;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 20, (position.y - 57));
			bodyenemy3->SetPos(position.x + 20, (position.y - 40));
		}
		else {
			bodyenemy->SetPos(position.x + 18, (position.y - 80));
			bodyenemy2->SetPos(position.x + 20, (position.y - 57));
			bodyenemy3->SetPos(position.x + 20, (position.y - 40));
		}

		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			enemyattack = App->collision->AddCollider({ position.x + 40,(position.y - 90),65,20 }, COLLIDER_ENEMY_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			enemyattack->to_delete = true;
			kick_timer = 3;
		}
		break;
	case A_KICK_NEUTRAL_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 60));
			bodyenemy2->SetPos(position.x + 12, (position.y - 49));
			bodyenemy3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			bodyenemy->SetPos(position.x + 35, (position.y - 60));
			bodyenemy2->SetPos(position.x + 42, (position.y - 49));
			bodyenemy3->SetPos(position.x + 45, (position.y - 35));
		}
		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) {
			mult = -2;
		}
		position.y -= speed * mult;
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			enemyattack = App->collision->AddCollider({ position.x + 40,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			enemyattack->to_delete = true;
		}
		break;
	case A_KICK_FORWARD_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 60));
			bodyenemy2->SetPos(position.x + 12, (position.y - 49));
			bodyenemy3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			bodyenemy->SetPos(position.x + 35, (position.y - 60));
			bodyenemy2->SetPos(position.x + 42, (position.y - 49));
			bodyenemy3->SetPos(position.x + 45, (position.y - 35));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if ((position.x + 23 * SCREEN_SIZE) < (App->player->position.x)) position.x += speed / 2;
			else if (position.y < App->player->position.y)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		else {
			if ((position.x) > (App->player->position.x + 23 * SCREEN_SIZE)) position.x -= speed / 2;
			else if (position.y < App->player->position.y)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			enemyattack = App->collision->AddCollider({ position.x + 50,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			enemyattack->to_delete = true;
		}
		break;
	case A_KICK_BACKWARD_JUMP:
		current_animation = &App->player->kickair;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 10, (position.y - 60));
			bodyenemy2->SetPos(position.x + 12, (position.y - 49));
			bodyenemy3->SetPos(position.x + 15, (position.y - 35));
		}
		else {
			bodyenemy->SetPos(position.x + 35, (position.y - 60));
			bodyenemy2->SetPos(position.x + 42, (position.y - 49));
			bodyenemy3->SetPos(position.x + 45, (position.y - 35));
		}

		if (position.y == 210) {
			App->audio->PlayChunk(App->player->jumpsound);
			mult = 2;
		}
		if (position.y <= 80) mult = -2;
		position.y -= speed * mult;
		if (flip == false) {
			if (position.x > App->background->cameraleft.x) position.x -= speed / 2;
			else if (position.y < App->player->position.y)position.x -= speed / 2;
			if ((App->background->cameraright.x > position.x + 70) && (App->background->cameraleft.x > 0) && (App->background->cameraleft.x > App->player->position.x + (23 * SCREEN_SIZE) * 2))App->render->camera.x += speed;// *1.25;
		}
		else {
			if (position.x + 23 * SCREEN_SIZE < App->background->cameraright.x - 1) position.x += speed / 2;
			else if (position.y < App->player->position.y)position.x += speed / 2;
			if ((App->background->cameraleft.x < position.x) && (App->background->cameraright.x < 670) && (App->background->cameraleft.x + 1 < App->player->position.x - 23 * SCREEN_SIZE))App->render->camera.x -= speed;// *1.25;
		}
		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			enemyattack = App->collision->AddCollider({ position.x + 30,(position.y - 30),65,20 }, COLLIDER_ENEMY_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			enemyattack->to_delete = true;
		}
		break;
	case A_KICK_CROUCH:
		current_animation = &App->player->kickcrouch;
		if (flip == false) {
			bodyenemy->SetPos(position.x + 15, (position.y - 65));
			bodyenemy2->SetPos(position.x + 25, (position.y - 50));
			bodyenemy3->SetPos(position.x + 12, (position.y - 35));
		}
		else {
			bodyenemy->SetPos(position.x + 50, (position.y - 65));
			bodyenemy2->SetPos(position.x + 67, (position.y - 50));
			bodyenemy3->SetPos(position.x + 47, (position.y - 35));
		}

		if (kick_timer == 1) {
			App->audio->PlayChunk(App->player->kicksound);
			enemyattack = App->collision->AddCollider({ position.x + 25,(position.y - 30),75,30 }, COLLIDER_ENEMY_SHOT, this);
			kick_timer = 2;
		}
		if (current_animation->GetFinished() == 1) {
			kick_timer = 3;
			enemyattack->to_delete = true;
		}
		break;
	case A_HITTED:
		current_animation = &App->player->hittedan;
		if (hitted_timer == 1 && position.y == 210) {
			App->audio->PlayChunk(App->player->hittedsound);
			App->UI->DamageTaken(2, 5);
			hitted_timer = 2;
		}

		if(flip==false)position.x -= 1;
		else position.x += 1;

		if (position.y == 130) {
			mult = -1;
		}
		if (position.y < 210)position.y -= speed * mult;
		if (current_animation->GetFinished() == 1 && hitted_timer == 2)hitted_timer = 3;
		break;
	case A_TORNADO:
		current_animation = &App->player->tornado;
		if (tornado_timer == 1) {
			App->particles->AddParticle(App->particles->tornado, position.x, position.y - 100, COLLIDER_ENEMY_SHOT, 0);
			App->audio->PlayChunk(App->player->tornadosound);
			tornado_timer = 2;
		}
		if (current_animation->GetFinished() == 1)tornado_timer = 3;
		break;
	}

	

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
	SDL_Rect r = current_animation->GetCurrentFrame();

	if (actual3 != A_TORNADO) {
		if (flip == false)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
		else App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true);
	}
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}



void ModulePlayer2::OnCollision(Collider* enemy, Collider* other) {
	//
	if (enemy->type == COLLIDER_ENEMY) {
		if (other->type == COLLIDER_PLAYER_SHOT) {
			actual3 = A_HITTED;
			if (hitted_timer == 0)hitted_timer = 1;
		}
		if (other->type == COLLIDER_WALL) {
			if (position.x > 0) position.x = other->rect.x - 23 * SCREEN_SIZE;
			else position.x = other->rect.x + 1;
		}
		if (other->type == COLLIDER_PLAYER) {
			if (flip == false) {
				stopright = true;
				position.x -= 1;
			}
			else {
				stopleft = true;
				position.x += 1;
			}
		}
	}
	else {
		if (other->type == COLLIDER_PLAYER) enemy->to_delete = true;
	}
}