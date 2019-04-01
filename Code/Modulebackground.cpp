#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include"ModuleSceneEarthquake.h"
#include "SDL/include/SDL.h"

ModuleBackground::ModuleBackground():Module(){
	// Water1 animation
	back.PushBack({ 0, 0, 640, 416 });
	back.PushBack({ 640, 0, 640, 416 });
	back.PushBack({ 1280, 0, 640, 416 });
	back.PushBack({ 1920, 0, 640, 416 });
	back.PushBack({ 2560, 0, 640, 416 });
	back.PushBack({ 0, 416, 640, 416 });
	back.PushBack({ 640, 416, 640, 416 });
	back.PushBack({ 1280, 416, 640, 416 });
	back.PushBack({ 1920, 416, 640, 416 });
	back.PushBack({ 2560, 416, 640, 416 });
	back.PushBack({ 0, 832, 640, 416 });
	back.PushBack({ 640, 832, 640, 416 });
	back.PushBack({ 1280, 832, 640, 416 });
	back.PushBack({ 1920, 832, 640, 416 });
	back.PushBack({ 2560, 832, 640, 416 });
	back.PushBack({ 0, 1248, 640, 416 });
	back.PushBack({ 640, 1248, 640, 416 });
	back.PushBack({ 1280, 1248, 640, 416 });
	back.PushBack({ 1920, 1248, 640, 416 });
	back.PushBack({ 2560, 1248, 640, 416 });
	back.PushBack({ 0, 1664, 640, 416 });
	back.PushBack({ 640, 1664, 640, 416 });
	back.PushBack({ 1280, 1664, 640, 416 });
	back.PushBack({ 1920, 1664, 640, 416 });
	back.speed = 0.08f;
}
ModuleBackground::~ModuleBackground(){}
bool ModuleBackground::Start() {
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	haohmaru=App->audio->LoadChunk("Audio_FX/haohmaru.wav");
	App->audio->PlayChunk(haohmaru);
	graphics=App->textures->Load("Sprites/Back.png");
	App->player->Enable();
	return true;
}
update_status ModuleBackground::Update() {
	App->render->Blit(graphics, 0, -170, &(back.GetCurrentFrame()), 0.9f);  //Background
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == App->input->KEY_PUSHED&&App->fade->finished == true) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->background, App->sceneearthquake, 2);
	}
	return UPDATE_CONTINUE;
}
bool ModuleBackground::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(haohmaru);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}