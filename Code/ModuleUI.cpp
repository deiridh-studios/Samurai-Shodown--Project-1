#include "Globals.h"
#include "Application.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleController.h"
#include "SDL/include/SDL_timer.h"
#include<stdio.h>


ModuleUI::ModuleUI(){}
ModuleUI::~ModuleUI() {}

bool ModuleUI::Init() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789-.,defghij", 2);
	textlife = App->textures->Load("Sprites/Sprite_Sheet_UI_1.png");
	doinitialtime = false;
	lifebarplayer1.x = 273;
	lifebarplayer1.y = 421;
	lifebarplayer1.w = 134;
	lifebarplayer1.h = 15;
	lifebarplayer2.x = 273;
	lifebarplayer2.y = 405;
	lifebarplayer2.w = 134;
	lifebarplayer2.h = 15;
	lifeplayer1.x = 273;
	lifeplayer1.y = 308;
	lifeplayer1.w = 128;
	lifeplayer1.h = 15;
	lifeplayer2.x = 273;
	lifeplayer2.y = 308;
	lifeplayer2.w = 128;
	lifeplayer2.h = 15;
	player1life = 32;
	player2life = 32;
	komessage.x = 484;
	komessage.y = 393;
	komessage.w = 28;
	komessage.h = 23;
	komessagewhite.x = 484;
	komessagewhite.y = 416;
	komessagewhite.w = 28;
	komessagewhite.h = 23;
	play = false;
	credits = 0;
	koblink = 0;
	//App->input->space = false;
	return true;
}
bool ModuleUI::CleanUp() {
	App->fonts->UnLoad(font_score);
	App->textures->Unload(textlife);
	return true;
}
update_status ModuleUI::Update() {
	if (play == true) {
		if (doinitialtime == true) {
			initialtime = SDL_GetTicks();
			doinitialtime = false;
		}
		time = (100000) - (SDL_GetTicks() - initialtime);
		sprintf_s(time_text, 10, "%7d", (time / 1000));
		App->fonts->BlitText(65, 50, font_score, time_text);
		if (time / 1000 == 0)App->input->space = true;
		lifeplayer1.w = player1life * 4;
		lifeplayer2.w = player2life * 4;
		App->render->Blit(textlife, 5, 20, &lifebarplayer1, 0.0f, false);
		App->render->Blit(textlife, 180, 20, &lifebarplayer2, 0.0f, false);
		App->render->Blit(textlife, (137 - (player1life * 4)), 20, &lifeplayer1, 0.0f, false);
		App->render->Blit(textlife, 182, 20, &lifeplayer2, 0.0f, false);
		if (lifeplayer1.w <= 10 || lifeplayer2.w <= 10) {
			koblink ++;
			if (koblink > 6)koblink = 0;
		}
		if (koblink == 6) {
			App->render->Blit(textlife, 145, 10, &komessagewhite, 0.0f, false);
		}
		else App->render->Blit(textlife, 145, 10, &komessage, 0.0f, false);
		if (lifeplayer1.w <= 0) {
			App->input->space = true;
			App->player2->victory = true;
			play = false;
		}
		if (lifeplayer2.w <= 0) {
			App->input->space = true;
			App->player->victory = true;
			play = false;
		}
	}
	else {
		koblink = 0;
		lifeplayer1.w = 128;
		lifeplayer2.w = 128;
	}
	return UPDATE_CONTINUE;
}

void ModuleUI::DamageTaken(int numplayer, int damage) {
	if (numplayer == 1)	player1life -= damage;
	else if (numplayer == 2) player2life -= damage;
}