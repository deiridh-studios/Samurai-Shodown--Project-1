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
#include "ModuleSNKMenu.h"
#include "ModuleCharacterSelection.h"
#include "ModuleSNKComplete.h"
#include "SDL/include/SDL.h"

ModuleSceneWelcome::ModuleSceneWelcome() :Module()
{
	//Words
	Words.PushBack({ 1012, 1600, 253, 15 });
	Words.PushBack({ 1012, 1650, 253, 15 });
	Words.speed = 0.02f;
	
	//Title
	Title.PushBack({ 0, 0, 253, 200 });
	Title.PushBack({ 253, 0, 253, 200 });
	Title.PushBack({ 506, 0, 253, 200 });
	Title.PushBack({ 759, 0, 253, 200 });
	Title.PushBack({ 1012, 0, 253, 200 });
	Title.PushBack({ 1265, 0, 253, 200 });
	Title.PushBack({ 1518, 0, 253, 200 });
	Title.PushBack({ 1771, 0, 253, 200 });
	Title.PushBack({ 0, 200, 253, 200 });
	Title.PushBack({ 253, 200, 253, 200 });
	Title.PushBack({ 506, 200, 253, 200 });
	Title.PushBack({ 759, 200, 253, 200 });
	Title.PushBack({ 1012, 200, 253, 200 });
	Title.PushBack({ 1265, 200, 253, 200 });
	Title.PushBack({ 1518, 200, 253, 200 });
	Title.PushBack({ 1771, 200, 253, 200 });
	Title.PushBack({ 0, 400, 253, 200 });
	Title.PushBack({ 253, 400, 253, 200 });
	Title.PushBack({ 506, 400, 253, 200 });
	Title.PushBack({ 759, 400, 253, 200 });
	Title.PushBack({ 1012, 400, 253, 200 });
	Title.PushBack({ 1265, 400, 253, 200 });
	Title.PushBack({ 1518, 400, 253, 200 });
	Title.PushBack({ 1771, 400, 253, 200 });
	Title.PushBack({ 0, 600, 253, 200 });
	Title.PushBack({ 253, 600, 253, 200 });
	Title.PushBack({ 506, 600, 253, 200 });
	Title.PushBack({ 759, 600, 253, 200 });
	Title.PushBack({ 1012, 600, 253, 200 });
	Title.PushBack({ 1265, 600, 253, 200 });
	Title.PushBack({ 1518, 600, 253, 200 });
	Title.PushBack({ 1771, 600, 253, 200 });
	Title.PushBack({ 0, 800, 253, 200 });
	Title.PushBack({ 253, 800, 253, 200 });
	Title.PushBack({ 506, 800, 253, 200 });
	Title.PushBack({ 759, 800, 253, 200 });
	Title.PushBack({ 1012, 800, 253, 200 });
	Title.PushBack({ 1265, 800, 253, 200 });
	Title.PushBack({ 1518, 800, 253, 200 });
	Title.PushBack({ 1771, 800, 253, 200 });
	Title.PushBack({ 0, 1000, 253, 200 });
	Title.PushBack({ 253, 1000, 253, 200 });
	Title.PushBack({ 506, 1000, 253, 200 });
	Title.PushBack({ 759, 1000, 253, 200 });
	Title.PushBack({ 1012, 1000, 253, 200 });
	Title.PushBack({ 1265, 1000, 253, 200 });
	Title.PushBack({ 1518, 1000, 253, 200 });
	Title.PushBack({ 1771, 1000, 253, 200 });
	Title.PushBack({ 0, 1200, 253, 200 });
	Title.PushBack({ 253, 1200, 253, 200 });
	Title.PushBack({ 506, 1200, 253, 200 });
	Title.PushBack({ 759, 1200, 253, 200 });
	Title.PushBack({ 1012, 1200, 253, 200 });
	Title.PushBack({ 1265, 1200, 253, 200 });
	Title.PushBack({ 1518, 1200, 253, 200 });
	Title.PushBack({ 1771, 1200, 253, 200 });
	Title.PushBack({ 0, 1400, 253, 200 });
	Title.PushBack({ 253, 1400, 253, 200 });
	Title.PushBack({ 506, 1400, 253, 200 });
	Title.PushBack({ 759, 1400, 253, 200 });
	Title.PushBack({ 1012, 1400, 253, 200 });
	Title.PushBack({ 1265, 1400, 253, 200 });
	Title.PushBack({ 1518, 1400, 253, 200 });
	Title.PushBack({ 1771, 1400, 253, 200 });
	Title.PushBack({ 0, 1600, 253, 200 });
	Title.PushBack({ 253, 1600, 253, 200 });
	Title.PushBack({ 506, 1600, 253, 200 });
	Title.PushBack({ 759, 1600, 253, 200 });
	Title.speed = 0.3;

}

ModuleSceneWelcome::~ModuleSceneWelcome() {}

bool  ModuleSceneWelcome::Start() {
	rectbackground.x = 1065;
	rectbackground.y = 1776;
	rectbackground.w = SCREEN_WIDTH;
	rectbackground.h = SCREEN_HEIGHT;
	recttitle.x = 759;
	recttitle.y = 1600;
	recttitle.w = 253;
	recttitle.h = 200;
	snkrect.x = 0;
	snkrect.y = 1800;
	snkrect.w = 276;
	snkrect.h = 30;
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/DEFINITIVETitle.png");
	Title.current_frame = 0;
	return true;
}

update_status  ModuleSceneWelcome::Update() {
	SDL_Rect rect{ 0,0,rectbackground.w*SCREEN_SIZE, rectbackground.h*SCREEN_SIZE };
	App->render->Blit(graphics, 0, 0, &rectbackground, 0.0f);  //Background
	if (App->fade->finished == true&&SDL_GetTicks()>3500) {
		if (Title.current_frame <= 67) {
			App->render->Blit(graphics, 30, 15, &(Title.GetCurrentFrame()), 0.0f);
		}
		else {
			App->render->Blit(graphics, 30, 15, &recttitle, 0.0f);  //Background
			App->render->Blit(graphics, 65, 165, &(Words.GetCurrentFrame()), 0.0f);
			App->render->Blit(graphics, 23, 190, &snkrect, 0.0f);
		}
	}
	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED && App->fade->finished == true && Title.current_frame > 67) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->scenewelcome, App->characterselection, 2);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleSceneWelcome::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}