#include "Globals.h"
#include "Application.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_timer.h"
#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include<stdio.h>

SDL_Renderer *renderer;
SDL_Texture *textlife;
SDL_Surface *surlife;

ModuleUI::ModuleUI(){}
ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789abcdefghij", 2);
	initialtime = SDL_GetTicks();
	surlife = IMG_Load("Sprites/textlife.png");
	textlife = SDL_CreateTextureFromSurface(renderer, surlife);
	SDL_FreeSurface(surlife);
	return true;
}
bool ModuleUI::CleanUp() {
	App->fonts->UnLoad(font_score);
	return true;
}
update_status ModuleUI::Update() {
	time = (100000)-(SDL_GetTicks() - initialtime);
	sprintf_s(time_text, 10, "%7d", (time/1000));
	App->fonts->BlitText(65, 10, font_score, time_text);
	if (time / 1000 == 0)App->input->space = true;


	lifebarplayer1.x = 0;
	lifebarplayer1.y = 0;
	lifebarplayer1.w = 100;
	lifebarplayer1.h = 29;

	SDL_RenderCopy(renderer, textlife, NULL, &lifebarplayer1);
	return UPDATE_CONTINUE;
}