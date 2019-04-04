#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer2.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 200;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 3406, 530, 79, 123 });
	idle.PushBack({ 3324, 530, 79, 123 });
	idle.PushBack({ 3243, 530, 79, 123 });
	idle.PushBack({ 3406, 653, 79, 123 });
	idle.PushBack({ 3324, 653, 79, 123 });
	idle.PushBack({ 3243, 653, 79, 123 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 2409 , 1298 , 75 , 118 });
	forward.PushBack({ 2479 , 1290 , 67 , 123 });
	forward.PushBack({ 2542 , 1293 , 75 , 129 });
	forward.PushBack({ 2615 , 1298 , 81 , 116 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	backward.PushBack({ 2615 , 1298 , 81 , 116 });
	backward.PushBack({ 2542 , 1293 , 75 , 129 });
	backward.PushBack({ 2479 , 1290 , 67 , 123 });
	backward.PushBack({ 2409 , 1298 , 75 , 118 });
	backward.speed = 0.1f;

	// Kick animation
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.PushBack({ 2459, 133, 81, 102 });
	kick.PushBack({ 2359, 133, 99, 108 });
	kick.PushBack({ 2248, 133, 112, 98 });
	kick.PushBack({ 2459, 133, 81, 102 });
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.PushBack({ 2545, 133, 80, 105 });
	kick.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 3368 , 1388 , 83 , 124 });
	punch.PushBack({ 3296 , 1372 , 78 , 137 });
	punch.PushBack({ 3211 , 1398 , 84 , 114 });
	punch.PushBack({ 3075 , 1398 , 142 , 113 });
	punch.PushBack({ 2939 , 1401 , 138 , 108 });
	punch.PushBack({ 2801 , 1406 , 142 , 105 });
	punch.PushBack({ 3327 , 1656 , 138 , 106 });
	punch.PushBack({ 3186 , 1656 , 138 , 106 });
	punch.PushBack({ 3058 , 1656 , 138 , 106 });
	punch.PushBack({ 2920 , 1637 , 139 , 112 });
	punch.PushBack({ 2680 , 1657 , 147 , 100 });
	punch.speed = 0.2f;

	// Jump
	jump.PushBack({ 3234 , 775 , 78 , 116 });
	jump.PushBack({ 3234 , 775 , 78 , 116 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3046 , 804 , 84 , 88 });
	jump.PushBack({ 3046 , 804 , 84 , 88 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.PushBack({ 3138 , 791 , 91 , 100 });
	jump.speed = 0.1f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaru.png"); // arcade version
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	actual = NONE;
	right = false;
	left = false;
	return ret;
}

//Clean Up
bool ModulePlayer2::CleanUp() {
	App->textures->Unload(graphics);
	App->audio->StopChunk();
	App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	////////////////////RIGHT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_RIGHT] == App->input->KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_RIGHT] == App->input->KEY_PUSHED) && actual == NONE && (position.y == 210 || right == true)) {
		if (position.x <= (SCREEN_WIDTH*SCREEN_SIZE - 410)) {
			current_animation = &backward;
			position.x += speed / 2;
			right = true;

			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 2.75;
		}
	}
	else right = false;

	////////////////////LEFT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_LEFT] == App->input->KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_LEFT] == App->input->KEY_PUSHED) && actual == NONE && (position.y == 210 || left == true)) {
		if (position.x >= 20) {
			current_animation = &forward;
			position.x -= speed;
			left = true;
			if (App->render->camera.x < 0)	App->render->camera.x += speed;
		}
	}
	else (left = false);
	////////////////////JUMP/////////////////////////

	if (((position.y < 210) || ((App->input->keyboardstate[SDL_SCANCODE_UP] == App->input->KEY_PUSHED || App->input->keyboardstate[SDL_SCANCODE_UP] == App->input->KEY_REPEAT) && actual == NONE)) && (position.y >= 130)) {
		current_animation = &jump;

		if (position.y == 210) {
			App->audio->PlayChunk(jumpsound);
			mult = 1;
		}

		if (position.y == 130) {
			mult = -1;
		}
		position.y -= speed * mult;
	}

	////////////////////PUNCH/////////////////////////
	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_H] == App->input->KEY_PUSHED) || actual == PUNCH) {
		current_animation = &punch;
		if (actual == NONE)App->audio->PlayChunk(punchsound);
		if (current_animation->GetFinished() == 0)actual = PUNCH;
		else actual = NONE;
	}

	////////////////////KICK/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_G] == App->input->KEY_PUSHED) || actual == KICK) {
		current_animation = &kick;
		if (actual == NONE)App->audio->PlayChunk(kicksound);
		if (current_animation->GetFinished() == 0)actual = KICK;
		else actual = NONE;
	}

	// Draw everything --------------------------------------

	SDL_Rect r = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	return UPDATE_CONTINUE;
}