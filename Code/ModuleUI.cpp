#include "Globals.h"
#include "Application.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_timer.h"

#include<stdio.h>


ModuleUI::ModuleUI(){}
ModuleUI::~ModuleUI() {}
bool ModuleUI::Start() {
	font_score = App->fonts->Load("Sprites/Numbers FONT.png", "0123456789abcdefghij", 2);
	initialtime = SDL_GetTicks();
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
	
	return UPDATE_CONTINUE;
}