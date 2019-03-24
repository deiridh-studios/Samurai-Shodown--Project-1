#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleBackground::ModuleBackground():Module(){}
ModuleBackground::~ModuleBackground(){}
bool ModuleBackground::Init() {
	rectbackground.x = 160;
	rectbackground.y = 113;
	rectbackground.w = SCREEN_WIDTH -703;
	rectbackground.h = SCREEN_HEIGHT -545;
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage2.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	App->audio->LoadChunk("Audio_FX/earthquake.wav");
	App->audio->PlayChunk(App->audio->chunks[0]);
	return true;
}
update_status ModuleBackground::Update() {
	if (scrollright != scrollleft) {
		if (scrollright == 1 && rectbackground.x < 320) {
			rectbackground.x++;
			//rectbackground.w--;
		}
		else if (scrollleft == 1 && rectbackground.x > 0) {
			rectbackground.x--;
			//rectbackground.w++;
		}
	}
	return UPDATE_CONTINUE;
}