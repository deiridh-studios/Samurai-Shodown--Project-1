#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 210;

	// Idle animation
	idle.PushBack({ 634, 569, 73, 115 });
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

	// Jump (To Do)
	jump.PushBack({ 250, 267, 64, 98 });
	jump.PushBack({ 329, 267, 81, 92 });
	jump.PushBack({ 793, 267, 113, 92 });
	jump.speed = 0.2f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Sprites/spritesHaohmaru.png"); // arcade version
	graphics2 = App->textures->Load("Sprites/Haohfix1.png"); // arcade version
	return ret;
}

int mult = 1; //JUMP UP-DOWN
int count = 0;

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	////////////////////RIGHT/////////////////////////

	if (App->input->keyright == 1)
	{
		if (position.x <= 580) {
			current_animation = &forward;
			position.x += speed;
		}
	}

	////////////////////LEFT/////////////////////////

	if (App->input->keyleft == 1)
	{
		if (position.x >= 20) {
			current_animation = &backward;
			position.x -= speed/2;
		}
	}

	////////////////////JUMP/////////////////////////

	if (((position.y < 210) || (App->input->keyup == 1)) && (position.y >= 130))
	{
		current_animation = &jump;
		if (position.y == 210) {
			mult = 1;
		}

		if (position.y == 130) {
			mult = -1;
		}
		position.y -= speed * mult;
	}

	////////////////////PUNCH/////////////////////////

	if (App->input->keyh == 1)
	{
		current_animation = &punch;
	}

	////////////////////KICK/////////////////////////

	if (App->input->keyg == 1)
	{
		current_animation = &kick;
		if (kick.GetCurrentFrame().x == 1577) {
	/*		if (count == 2) {
				App->input->keyg = 2;
				count = 0;
			}
			else count ++;
		}*/
	}



	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}