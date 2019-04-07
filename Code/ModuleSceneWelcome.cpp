#include "Globals.h"
#include "Application.h"
#include "Modulebackground.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWelcome.h"
#include "SDL/include/SDL.h"

ModuleSceneWelcome::ModuleSceneWelcome() :Module()
{
	//Title
	Words.PushBack({ 1518, 1800, 416, 16 });
	Words.PushBack({ 1518, 1816, 416, 16 });
	Words.speed = 0.03f;
}

ModuleSceneWelcome::~ModuleSceneWelcome() {}
bool  ModuleSceneWelcome::Start() {
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = SCREEN_WIDTH;
	rectbackground.h = SCREEN_HEIGHT;
	graphics2 = App->textures->Load("Sprites/Title.png");
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/intro.png");
	return true;
}
update_status  ModuleSceneWelcome::Update() {
	SDL_Rect rect{ 0,0,rectbackground.w*SCREEN_SIZE, rectbackground.h*SCREEN_SIZE };
	App->render->Blit(graphics, 0, 0, &rectbackground, 0.0f);  //Background
	App->render->Blit(graphics2, 56, 174, &(Words.GetCurrentFrame()));
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED&&App->fade->finished == true) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->scenewelcome, App->background, 2);
	}
	return UPDATE_CONTINUE;
}
bool  ModuleSceneWelcome::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	return true;
}