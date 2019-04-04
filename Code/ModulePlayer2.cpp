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
	idle.PushBack({ 635, 569, 73, 115 });
	idle.PushBack({ 716, 569, 73, 115 });
	idle.PushBack({ 797, 569, 73, 115 });
	idle.PushBack({ 634, 692, 73, 115 });
	idle.PushBack({ 716, 692, 73, 115 });
	idle.PushBack({ 797, 692, 73, 115 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 1422, 1325, 79, 123 });
	forward.PushBack({ 1501, 1325, 71, 123 });
	forward.PushBack({ 1572, 1325, 61, 123 });
	forward.PushBack({ 1633, 1325, 74, 123 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	backward.PushBack({ 1633, 1325, 74, 123 });
	backward.PushBack({ 1572, 1325, 61, 123 });
	backward.PushBack({ 1501, 1325, 71, 123 });
	backward.PushBack({ 1422, 1325, 79, 123 });
	backward.speed = 0.1f;

	// Kick animation
	kick.PushBack({ 1577, 173, 79, 94 });
	kick.PushBack({ 1656, 175, 99, 92 });
	kick.PushBack({ 1755, 172, 110, 92 });
	kick.PushBack({ 1865, 173, 79, 94 });
	kick.PushBack({ 1944, 172, 62, 95 });
	kick.PushBack({ 1577, 173, 79, 94 });
	kick.PushBack({ 1577, 173, 79, 94 });
	kick.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 676, 1410, 72, 133 });
	punch.PushBack({ 748, 1410, 73, 133 });
	punch.PushBack({ 821, 1410, 81, 133 });
	punch.PushBack({ 902, 1410, 136, 133 });
	punch.PushBack({ 1038, 1410, 136, 133 });
	punch.PushBack({ 1175, 1410, 136, 133 });
	punch.PushBack({ 652, 1649, 135, 133 });
	punch.PushBack({ 787, 1649, 133, 133 }); //144
	punch.PushBack({ 932, 1649, 125, 133 });
	punch.PushBack({ 1057, 1649, 137, 133 });
	punch.PushBack({ 1194, 1649, 74, 133 });
	punch.speed = 0.2f;

	// Jump
	jump.PushBack({ 816, 813, 61, 112 });
	jump.PushBack({ 816, 813, 61, 112 });
	jump.PushBack({ 902, 834, 71, 91 });
	jump.PushBack({ 989, 844, 76, 81 });
	jump.PushBack({ 989, 844, 76, 81 });
	jump.PushBack({ 989, 844, 76, 81 });
	jump.PushBack({ 902, 834, 71, 91 });
	jump.PushBack({ 902, 834, 71, 91 });
	jump.PushBack({ 902, 834, 71, 91 });
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