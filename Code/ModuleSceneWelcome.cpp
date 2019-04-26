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
	//Words
	Words.PushBack({ 1518, 1800, 416, 16 });
	Words.PushBack({ 1518, 1816, 416, 16 });
	Words.speed = 0.03f;
	
	//Title
	Title.PushBack({ 0, 0, 250, 200 });
	Title.PushBack({ 250, 0, 250, 200 });
	Title.PushBack({ 500, 0, 250, 200 });
	Title.PushBack({ 750, 0, 250, 200 });
	Title.PushBack({ 1000, 0, 250, 200 });
	Title.PushBack({ 1250, 0, 250, 200 });
	Title.PushBack({ 1500, 0, 250, 200 });
	Title.PushBack({ 1750, 0, 250, 200 });
	Title.PushBack({ 0, 0, 250, 200 });
	Title.PushBack({ 250, 200, 250, 200 });
	Title.PushBack({ 500, 200, 250, 200 });
	Title.PushBack({ 750, 200, 250, 200 });
	Title.PushBack({ 1000, 200, 250, 200 });
	Title.PushBack({ 1250, 200, 250, 200 });
	Title.PushBack({ 1500, 200, 250, 200 });
	Title.PushBack({ 1750, 200, 250, 200 });
	Title.PushBack({ 0, 400, 250, 200 });
	Title.PushBack({ 250, 400, 250, 200 });
	Title.PushBack({ 500, 400, 250, 200 });
	Title.PushBack({ 750, 400, 250, 200 });
	Title.PushBack({ 1000, 400, 250, 200 });
	Title.PushBack({ 1250, 400, 250, 200 });
	Title.PushBack({ 1500, 400, 250, 200 });
	Title.PushBack({ 1750, 400, 250, 200 });
	Title.PushBack({ 0, 600, 250, 200 });
	Title.PushBack({ 250, 600, 250, 200 });
	Title.PushBack({ 500, 600, 250, 200 });
	Title.PushBack({ 750, 600, 250, 200 });
	Title.PushBack({ 1000, 600, 250, 200 });
	Title.PushBack({ 1250, 600, 250, 200 });
	Title.PushBack({ 1500, 600, 250, 200 });
	Title.PushBack({ 1750, 600, 250, 200 });
	Title.PushBack({ 0, 800, 250, 200 });
	Title.PushBack({ 250, 800, 250, 200 });
	Title.PushBack({ 500, 800, 250, 200 });
	Title.PushBack({ 750, 800, 250, 200 });
	Title.PushBack({ 1000, 800, 250, 200 });
	Title.PushBack({ 1250, 800, 250, 200 });
	Title.PushBack({ 1500, 800, 250, 200 });
	Title.PushBack({ 1750, 800, 250, 200 });
	Title.speed = 0.1;
}

ModuleSceneWelcome::~ModuleSceneWelcome() {}
bool  ModuleSceneWelcome::Start() {
	rectbackground.x = 0;
	rectbackground.y = 0;
	rectbackground.w = SCREEN_WIDTH;
	rectbackground.h = SCREEN_HEIGHT;
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/DEFINITIVETitle.png");
	return true;
}
update_status  ModuleSceneWelcome::Update() {
	SDL_Rect rect{ 0,0,rectbackground.w*SCREEN_SIZE, rectbackground.h*SCREEN_SIZE };
	//App->render->Blit(graphics, 1665, 1720, &rectbackground, 0.0f);  //Background
	App->render->Blit(graphics, 0, 0, &(Title.GetCurrentFrame()), 0.0f);
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
	return true;
}