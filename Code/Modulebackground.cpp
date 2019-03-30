#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
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
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = (SCREEN_WIDTH )*SCREEN_SIZE;
	rectbackground.h = (SCREEN_HEIGHT) *SCREEN_SIZE;
	scrollleft = 0;
	scrollright = 0;
	App->audio->LoadMusic("Music/stage.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	App->audio->LoadChunk("Audio_FX/haohmaru.wav");
	App->audio->PlayChunk(App->audio->chunks[0]);
	graphics=App->textures->Load("Sprites/Back.png");
	App->player->Enable();
	return true;
}
update_status ModuleBackground::Update() {
	App->render->Blit(graphics, 0, -170, &(back.GetCurrentFrame()), 0.9f);  //Background
	return UPDATE_CONTINUE;
}
bool ModuleBackground::CleanUp()
{
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}