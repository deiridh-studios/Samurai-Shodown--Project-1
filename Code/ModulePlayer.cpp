#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 628, 539, 73, 115 });
	idle.PushBack({ 710, 539, 73, 115 });
	idle.PushBack({ 791, 539, 73, 115 });
	idle.PushBack({ 628, 662, 73, 115 });
	idle.PushBack({ 710, 662, 73, 115 });
	idle.PushBack({ 791, 662, 73, 115 });
	idle.speed = 0.2f;

	// Walk forward animation (To IMPROVE)
	forward.PushBack({ 1416, 1295, 79, 123 });
	forward.PushBack({ 1497, 1295, 71, 123 });
	forward.PushBack({ 1566, 1295, 61, 123 });
	forward.PushBack({ 1627, 1295, 74, 123 });
	forward.speed = 0.2f;

	// Walk backwards animation (To Do)
	backward.PushBack({ 1627, 1295, 74, 123 });
	backward.PushBack({ 1566, 1295, 61, 123 });
	backward.PushBack({ 1497, 1295, 71, 123 });
	backward.PushBack({ 1416, 1295, 79, 123 });
	backward.speed = 0.1f;

	// Kick animation
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.PushBack({ 1650, 145, 99, 92 });
	kick.PushBack({ 1749, 142, 110, 92 });
	kick.PushBack({ 1859, 143, 79, 94 });
	kick.PushBack({ 1938, 142, 62, 95 });
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.PushBack({ 1571, 143, 79, 94 });
	kick.speed = 0.2f;


	// Punch animation (TO IMPROVE)
	punch.PushBack({ 670, 1381, 72, 133 });
	punch.PushBack({ 742, 1381, 73, 133 });
	punch.PushBack({ 815, 1381, 81, 133 });
	punch.PushBack({ 896, 1381, 136, 133 });
	punch.PushBack({ 1032, 1381, 136, 133 });
	punch.PushBack({ 1169, 1381, 136, 133 });
	punch.PushBack({ 1296, 1638, 96, 130 });
	punch.PushBack({ 649, 1614, 133, 144 }); //144
	punch.PushBack({ 781, 1615, 133, 133 });
	punch.PushBack({ 914, 1625, 133, 133 });
	punch.PushBack({ 1190, 1617, 74, 133 });
	punch.speed = 0.2f;

	// Jump
	jump.PushBack({ 810, 783, 61, 112 });
	jump.PushBack({ 810, 783, 61, 112 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 983, 814, 76, 81 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.PushBack({ 896, 804, 71, 91 });
	jump.speed = 0.1f;

	//Tornado
	////////////Animation tornado;
	tornado.PushBack({ 40, 1295, 88, 144});
	tornado.PushBack({ 186, 1295, 70, 144});
	tornado.PushBack({ 326, 1295, 74,144 });
	tornado.PushBack({ 484, 1295, 60, 144 });
	tornado.PushBack({ 615, 1295, 97, 144 });
	tornado.PushBack({ 777, 1295, 59, 1446 });
	tornado.PushBack({ 880, 1295, 100, 144 });
	tornado.PushBack({ 1020, 1295, 100, 144});
	tornado.PushBack({ 1158, 1295, 100, 144});
	tornado.PushBack({ 1317, 1295, 100, 144});
	tornado.PushBack({ 1458, 1295, 100, 144});
	tornado.PushBack({ 1604, 1295, 100, 144 });
	tornado.PushBack({ 1734, 1295, 100, 144 });
	tornado.PushBack({ 1875, 1295, 100, 144});
	tornado.PushBack({ 27, 1461, 85, 122 });
	tornado.PushBack({ 184,1461, 72, 122 });
	tornado.PushBack({ 327,1461, 72, 122 });
	
	
	tornado.speed = 0.1f;

	////////////Animation hitted;
	hittedan.PushBack({ 372, 8, 78, 97 });
	hittedan.PushBack({ 257, 8, 85, 97 });
	hittedan.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaru.png"); // arcade version
	graphics2 = App->textures->Load("sprites/Haohfix1.png");
	punchsound = App->audio->LoadChunk("Audio_FX/Punch.wav");
	kicksound = App->audio->LoadChunk("Audio_FX/Kick.wav");
	jumpsound = App->audio->LoadChunk("Audio_FX/Jump.wav");
	hittedsound = App->audio->LoadChunk("Audio_FX/Hitted.wav");
	tornadosound = App->audio->LoadChunk("Audio_FX/Tornado.wav");
	body = App->collision->AddCollider({ position.x,(position.y-100),73,95 }, COLLIDER_PLAYER, this);
	actual = NONE;
	right = false;
	left = false;
	godmode = false;
	return ret;
}

//Clean Up
bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->audio->StopChunk();
	App->audio->UnLoadChunk(punchsound);
	App->audio->UnLoadChunk(kicksound);
	App->audio->UnLoadChunk(jumpsound);
	App->audio->UnLoadChunk(hittedsound);
	App->audio->UnLoadChunk(tornadosound);
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	////////////////////RIGHT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_D] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_D] == KEY_PUSHED) && actual == NONE && (position.y == 210 || right == true)) {
		if (position.x <= (SCREEN_WIDTH*SCREEN_SIZE - 410)) {
			current_animation = &forward;
			position.x += speed;
			right = true;

			if (App->render->camera.x > (-SCREEN_WIDTH * SCREEN_SIZE))App->render->camera.x -= speed * 1.25;
		}
	}
	else right = false;

	////////////////////LEFT/////////////////////////

	if ((App->input->keyboardstate[SDL_SCANCODE_A] == KEY_REPEAT || App->input->keyboardstate[SDL_SCANCODE_A] == KEY_PUSHED) && actual == NONE && (position.y == 210 || left == true)) {
		if (position.x >= 20) {
			current_animation = &backward;
			position.x -= speed / 2;
			left = true;
			if (App->render->camera.x < 0)	App->render->camera.x += speed * 1.25;
		}
	}
	else (left = false);

	////////////////////JUMP/////////////////////////

	if (((position.y < 210) || ((App->input->keyboardstate[SDL_SCANCODE_W] == KEY_PUSHED|| App->input->keyboardstate[SDL_SCANCODE_W] == KEY_REPEAT) && actual == NONE)) && (position.y >= 130)) {
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
	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_T] == KEY_PUSHED) || actual == PUNCH) {
		current_animation = &punch;
		if (actual == NONE)App->audio->PlayChunk(punchsound);
		if(current_animation->GetFinished()==0)actual = PUNCH;
		else actual = NONE;
	}

	////////////////////KICK/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_Y] == KEY_PUSHED) || actual == KICK) {
		current_animation = &kick;
		if (actual == NONE)App->audio->PlayChunk(kicksound);
		if (current_animation->GetFinished() == 0)actual = KICK;
		else actual = NONE;
	}

	////////////////////TORNADO/////////////////////////

	if ((actual == NONE && App->input->keyboardstate[SDL_SCANCODE_R] == KEY_PUSHED) || actual == TORNADO) {
		current_animation = &tornado;
		if (actual == NONE) {
			App->particles->AddParticle(App->particles->tornado, position.x, position.y-100, COLLIDER_PLAYER_SHOT, 0);
			App->audio->PlayChunk(tornadosound);
		}
		if (current_animation->GetFinished() == 0)actual = TORNADO;
		else actual = NONE;
	}

	////////////////////GODMODE/////////////////////////

	if (App->input->keyboardstate[SDL_SCANCODE_F5] == KEY_PUSHED) {
		godmode = !godmode;
		if (godmode == true) body->to_delete = true;
		else body = App->collision->AddCollider({ position.x,(position.y-100),73,95 }, COLLIDER_PLAYER, this);
	}
	body->SetPos(position.x, (position.y - 100));
	
	
	if (actual == HITTED) {
		current_animation = &hittedan;
		if(current_animation->GetFinished()==1)	actual = NONE;
	}
		// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();		

	if(actual!=TORNADO)	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	else App->render->Blit(graphics2, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* player, Collider* enemy) {
	if (actual != HITTED) {
		App->audio->PlayChunk(hittedsound);
		//Sprites hitted
		position.x = position.x - 25;
	}
	actual = HITTED;
}