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
#include "ModuleSNKComplete.h"
#include "ModuleCharacterSelection.h"
#include "SDL/include/SDL.h"

ModuleSNKMenu::ModuleSNKMenu() :Module()
{
	//SNKTitle
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 608, 2688, 304, 224 });
	SNKMenu.PushBack({ 0, 0, 304, 224 });
	SNKMenu.PushBack({ 304, 0, 304, 224 });
	SNKMenu.PushBack({ 608, 0, 304, 224 });
	SNKMenu.PushBack({ 912, 0, 304, 224 });
	SNKMenu.PushBack({ 1216, 0, 304, 224 });
	SNKMenu.PushBack({ 1520, 0, 304, 224 });
	SNKMenu.PushBack({ 1824, 0, 304, 224 });
	SNKMenu.PushBack({ 2128, 0, 304, 224 });
	SNKMenu.PushBack({ 0, 224, 304, 224 });
	SNKMenu.PushBack({ 304, 224, 304, 224 });
	SNKMenu.PushBack({ 608, 224, 304, 224 });
	SNKMenu.PushBack({ 912, 224, 304, 224 });
	SNKMenu.PushBack({ 1216, 224, 304, 224 });
	SNKMenu.PushBack({ 1520, 224, 304, 224 });
	SNKMenu.PushBack({ 1824, 224, 304, 224 });
	SNKMenu.PushBack({ 2128, 224, 304, 224 });
	SNKMenu.PushBack({ 0, 448, 304, 224 });
	SNKMenu.PushBack({ 304, 448, 304, 224 });
	SNKMenu.PushBack({ 608, 448, 304, 224 });
	SNKMenu.PushBack({ 912, 448, 304, 224 });
	SNKMenu.PushBack({ 1216, 448, 304, 224 });
	SNKMenu.PushBack({ 1520, 448, 304, 224 });
	SNKMenu.PushBack({ 1824, 448, 304, 224 });
	SNKMenu.PushBack({ 2128, 448, 304, 224 });
	SNKMenu.PushBack({ 0, 672, 304, 224 });
	SNKMenu.PushBack({ 304, 672, 304, 224 });
	SNKMenu.PushBack({ 608, 672, 304, 224 });
	SNKMenu.PushBack({ 912, 672, 304, 224 });
	SNKMenu.PushBack({ 1216, 672, 304, 224 });
	SNKMenu.PushBack({ 1520, 672, 304, 224 });
	SNKMenu.PushBack({ 1824, 672, 304, 224 });
	SNKMenu.PushBack({ 2128, 672, 304, 224 });
	SNKMenu.PushBack({ 0, 896, 304, 224 });
	SNKMenu.PushBack({ 304, 896, 304, 224 });
	SNKMenu.PushBack({ 608, 896, 304, 224 });
	SNKMenu.PushBack({ 912, 896, 304, 224 });
	SNKMenu.PushBack({ 1216, 896, 304, 224 });
	SNKMenu.PushBack({ 1520, 896, 304, 224 });
	SNKMenu.PushBack({ 1824, 896, 304, 224 });
	SNKMenu.PushBack({ 2128, 896, 304, 224 });
	SNKMenu.PushBack({ 0, 1120, 304, 224 });
	SNKMenu.PushBack({ 304, 1120, 304, 224 });
	SNKMenu.PushBack({ 608, 1120, 304, 224 });
	SNKMenu.PushBack({ 912, 1120, 304, 224 });
	SNKMenu.PushBack({ 1216, 1120, 304, 224 });
	SNKMenu.PushBack({ 1520, 1120, 304, 224 });
	SNKMenu.PushBack({ 1824, 1120, 304, 224 });
	SNKMenu.PushBack({ 2128, 1120, 304, 224 });
	SNKMenu.PushBack({ 0, 1344, 304, 224 });
	SNKMenu.PushBack({ 304, 1344, 304, 224 });
	SNKMenu.PushBack({ 608, 1344, 304, 224 });
	SNKMenu.PushBack({ 912, 1344, 304, 224 });
	SNKMenu.PushBack({ 1216, 1344, 304, 224 });
	SNKMenu.PushBack({ 1520, 1344, 304, 224 });
	SNKMenu.PushBack({ 1824, 1344, 304, 224 });
	SNKMenu.PushBack({ 2128, 1344, 304, 224 });
	SNKMenu.PushBack({ 0, 1568, 304, 224 });
	SNKMenu.PushBack({ 304, 1568, 304, 224 });
	SNKMenu.PushBack({ 608, 1568, 304, 224 });
	SNKMenu.PushBack({ 912, 1568, 304, 224 });
	SNKMenu.PushBack({ 1216, 1568, 304, 224 });
	SNKMenu.PushBack({ 1520, 1568, 304, 224 });
	SNKMenu.PushBack({ 1824, 1568, 304, 224 });
	SNKMenu.PushBack({ 2128, 1568, 304, 224 });
	SNKMenu.PushBack({ 0, 1792, 304, 224 });
	SNKMenu.PushBack({ 304, 1792, 304, 224 });
	SNKMenu.PushBack({ 608, 1792, 304, 224 });
	SNKMenu.PushBack({ 912, 1792, 304, 224 });
	SNKMenu.PushBack({ 1216, 1792, 304, 224 });
	SNKMenu.PushBack({ 1520, 1792, 304, 224 });
	SNKMenu.PushBack({ 1824, 1792, 304, 224 });
	SNKMenu.PushBack({ 2128, 1792, 304, 224 });
	SNKMenu.PushBack({ 0, 2016, 304, 224 });
	SNKMenu.PushBack({ 304, 2016, 304, 224 });
	SNKMenu.PushBack({ 608, 2016, 304, 224 });
	SNKMenu.PushBack({ 912, 2016, 304, 224 });
	SNKMenu.PushBack({ 1216, 2016, 304, 224 });
	SNKMenu.PushBack({ 1520, 2016, 304, 224 });
	SNKMenu.PushBack({ 1824, 2016, 304, 224 });
	SNKMenu.PushBack({ 2128, 2016, 304, 224 });
	SNKMenu.PushBack({ 0, 2240, 304, 224 });
	SNKMenu.PushBack({ 304, 2240, 304, 224 });
	SNKMenu.PushBack({ 608, 2240, 304, 224 });
	SNKMenu.PushBack({ 912, 2240, 304, 224 });
	SNKMenu.PushBack({ 1216, 2240, 304, 224 });
	SNKMenu.PushBack({ 1520, 2240, 304, 224 });
	SNKMenu.PushBack({ 1824, 2240, 304, 224 });
	SNKMenu.PushBack({ 2128, 2240, 304, 224 });
	SNKMenu.PushBack({ 0, 2464, 304, 224 });
	SNKMenu.PushBack({ 304, 2464, 304, 224 });
	SNKMenu.PushBack({ 608, 2464, 304, 224 });
	SNKMenu.PushBack({ 912, 2464, 304, 224 });
	SNKMenu.PushBack({ 1216, 2464, 304, 224 });
	SNKMenu.PushBack({ 1520, 2464, 304, 224 });
	SNKMenu.PushBack({ 1824, 2464, 304, 224 });
	SNKMenu.PushBack({ 2128, 2464, 304, 224 });
	SNKMenu.PushBack({ 0, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.PushBack({ 304, 2688, 304, 224 });
	SNKMenu.speed = 0.35f;
}

ModuleSNKMenu::~ModuleSNKMenu() {}

bool  ModuleSNKMenu::Start() {
	App->audio->LoadMusic("Music/NeoGeo.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/Neo Geo Intro.png");
	SNKMenu.current_frame = 0;
	return true;
}

update_status  ModuleSNKMenu::Update() {

	App->render->Blit(graphics, 0, 0, &(SNKMenu.GetCurrentFrame()), 0.0f);


	if (SNKMenu.current_frame > 130||App->input->keyboardstate[SDL_SCANCODE_RETURN]==KEY_PUSHED) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->SNKMenu, App->SNKComplete, 1.0F);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleSNKMenu::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}