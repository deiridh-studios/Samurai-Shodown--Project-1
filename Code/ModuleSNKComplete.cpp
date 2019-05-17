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

ModuleSNKComplete::ModuleSNKComplete() :Module()
{
	//Title
	Background.PushBack({ 0, 0, 304, 224 });
	Background.PushBack({ 304, 0, 304, 224 });
	Background.PushBack({ 608, 0, 304, 224 });
	Background.PushBack({ 912, 0, 304, 224 });
	Background.PushBack({ 1216, 0, 304, 224 });
	Background.PushBack({ 1520, 0, 304, 224 });
	Background.PushBack({ 1824, 0, 304, 224 });
	Background.PushBack({ 2128, 0, 304, 224 });
	Background.PushBack({ 2432, 0, 304, 224 });
	Background.PushBack({ 2736, 0, 304, 224 });
	Background.PushBack({ 3040, 0, 304, 224 });
	Background.PushBack({ 3344, 0, 304, 224 });
	Background.PushBack({ 3648, 0, 304, 224 });
	Background.PushBack({ 3952, 0, 304, 224 });
	Background.PushBack({ 4256, 0, 304, 224 });
	Background.PushBack({ 4560, 0, 304, 224 });
	Background.PushBack({ 4864, 0, 304, 224 });
	Background.PushBack({ 5168, 0, 304, 224 });
	Background.PushBack({ 5472, 0, 304, 224 });
	Background.PushBack({ 5776, 0, 304, 224 });
	Background.PushBack({ 0, 224, 304, 224 });
	Background.PushBack({ 304, 224, 304, 224 });
	Background.PushBack({ 608, 224, 304, 224 });
	Background.PushBack({ 912, 224, 304, 224 });
	Background.PushBack({ 1216, 224, 304, 224 });
	Background.PushBack({ 1520, 224, 304, 224 });
	Background.PushBack({ 1824, 224, 304, 224 });
	Background.PushBack({ 2128, 224, 304, 224 });
	Background.PushBack({ 2432, 224, 304, 224 });
	Background.PushBack({ 2736, 224, 304, 224 });
	Background.PushBack({ 3040, 224, 304, 224 });
	Background.PushBack({ 3344, 224, 304, 224 });
	Background.PushBack({ 3648, 224, 304, 224 });
	Background.PushBack({ 3952, 224, 304, 224 });
	Background.PushBack({ 4256, 224, 304, 224 });
	Background.PushBack({ 4560, 224, 304, 224 });
	Background.PushBack({ 4864, 224, 304, 224 });
	Background.PushBack({ 5168, 224, 304, 224 });
	Background.PushBack({ 5472, 224, 304, 224 });
	Background.PushBack({ 5776, 224, 304, 224 });
	Background.PushBack({ 0, 448, 304, 224 });
	Background.PushBack({ 304, 448, 304, 224 });
	Background.PushBack({ 608, 448, 304, 224 });
	Background.PushBack({ 912, 448, 304, 224 });
	Background.PushBack({ 1216, 448, 304, 224 });
	Background.PushBack({ 1520, 448, 304, 224 });
	Background.PushBack({ 1824, 448, 304, 224 });
	Background.PushBack({ 2128, 448, 304, 224 });
	Background.PushBack({ 2432, 448, 304, 224 });
	Background.PushBack({ 2736, 448, 304, 224 });
	Background.PushBack({ 3040, 448, 304, 224 });
	Background.PushBack({ 3344, 448, 304, 224 });
	Background.PushBack({ 3648, 448, 304, 224 });
	Background.PushBack({ 3952, 448, 304, 224 });
	Background.PushBack({ 4256, 448, 304, 224 });
	Background.PushBack({ 4560, 448, 304, 224 });
	Background.PushBack({ 4864, 448, 304, 224 });
	Background.PushBack({ 5168, 448, 304, 224 });
	Background.PushBack({ 5472, 448, 304, 224 });
	Background.PushBack({ 5776, 448, 304, 224 });
	Background.PushBack({ 0, 672, 304, 224 });
	Background.PushBack({ 304, 672, 304, 224 });
	Background.PushBack({ 608, 672, 304, 224 });
	Background.PushBack({ 912, 672, 304, 224 });
	Background.PushBack({ 1216, 672, 304, 224 });
	Background.PushBack({ 1520, 672, 304, 224 });
	Background.PushBack({ 1824, 672, 304, 224 });
	Background.PushBack({ 2128, 672, 304, 224 });
	Background.PushBack({ 2432, 672, 304, 224 });
	Background.PushBack({ 2736, 672, 304, 224 });
	Background.PushBack({ 3040, 672, 304, 224 });
	Background.PushBack({ 3344, 672, 304, 224 });
	Background.PushBack({ 3648, 672, 304, 224 });
	Background.PushBack({ 3952, 672, 304, 224 });
	Background.PushBack({ 4256, 672, 304, 224 });
	Background.PushBack({ 4560, 672, 304, 224 });
	Background.PushBack({ 4864, 672, 304, 224 });
	Background.PushBack({ 5168, 672, 304, 224 });
	Background.PushBack({ 5472, 672, 304, 224 });
	Background.PushBack({ 5776, 672, 304, 224 });
	Background.PushBack({ 0, 896, 304, 224 });
	Background.PushBack({ 304, 896, 304, 224 });
	Background.PushBack({ 608, 896, 304, 224 });
	Background.PushBack({ 912, 896, 304, 224 });
	Background.PushBack({ 1216, 896, 304, 224 });
	Background.PushBack({ 1520, 896, 304, 224 });
	Background.PushBack({ 1824, 896, 304, 224 });
	Background.PushBack({ 2128, 896, 304, 224 });
	Background.PushBack({ 2432, 896, 304, 224 });
	Background.PushBack({ 2736, 896, 304, 224 });
	Background.PushBack({ 3040, 896, 304, 224 });
	Background.PushBack({ 3344, 896, 304, 224 });
	Background.PushBack({ 3648, 896, 304, 224 });
	Background.PushBack({ 3952, 896, 304, 224 });
	Background.PushBack({ 4256, 896, 304, 224 });
	Background.PushBack({ 4560, 896, 304, 224 });
	Background.PushBack({ 4864, 896, 304, 224 });
	Background.PushBack({ 5168, 896, 304, 224 });
	Background.PushBack({ 5472, 896, 304, 224 });
	Background.PushBack({ 5776, 896, 304, 224 });
	Background.PushBack({ 0, 1120, 304, 224 });
	Background.PushBack({ 304, 1120, 304, 224 });
	Background.PushBack({ 608, 1120, 304, 224 });
	Background.PushBack({ 912, 1120, 304, 224 });
	Background.PushBack({ 1216, 1120, 304, 224 });
	Background.PushBack({ 1520, 1120, 304, 224 });
	Background.PushBack({ 1824, 1120, 304, 224 });
	Background.PushBack({ 2128, 1120, 304, 224 });
	Background.PushBack({ 2432, 1120, 304, 224 });
	Background.PushBack({ 2736, 1120, 304, 224 });
	Background.PushBack({ 3040, 1120, 304, 224 });
	Background.PushBack({ 3344, 1120, 304, 224 });
	Background.PushBack({ 3648, 1120, 304, 224 });
	Background.PushBack({ 3952, 1120, 304, 224 });
	Background.PushBack({ 4256, 1120, 304, 224 });
	Background.PushBack({ 4560, 1120, 304, 224 });
	Background.PushBack({ 4864, 1120, 304, 224 });
	Background.PushBack({ 5168, 1120, 304, 224 });
	Background.PushBack({ 5472, 1120, 304, 224 });
	Background.PushBack({ 5776, 1120, 304, 224 });
	Background.PushBack({ 0, 1344, 304, 224 });
	Background.PushBack({ 304, 1344, 304, 224 });
	Background.PushBack({ 608, 1344, 304, 224 });
	Background.PushBack({ 912, 1344, 304, 224 });
	Background.PushBack({ 1216, 1344, 304, 224 });
	Background.PushBack({ 1520, 1344, 304, 224 });
	Background.PushBack({ 1824, 1344, 304, 224 });
	Background.PushBack({ 2128, 1344, 304, 224 });
	Background.PushBack({ 2432, 1344, 304, 224 });
	Background.PushBack({ 2736, 1344, 304, 224 });
	Background.PushBack({ 3040, 1344, 304, 224 });
	Background.PushBack({ 3344, 1344, 304, 224 });
	Background.PushBack({ 3648, 1344, 304, 224 });
	Background.PushBack({ 3952, 1344, 304, 224 });
	Background.PushBack({ 4256, 1344, 304, 224 });
	Background.PushBack({ 4560, 1344, 304, 224 });
	Background.PushBack({ 4864, 1344, 304, 224 });
	Background.PushBack({ 5168, 1344, 304, 224 });
	Background.PushBack({ 5472, 1344, 304, 224 });
	Background.PushBack({ 5776, 1344, 304, 224 });
	Background.PushBack({ 0, 1568, 304, 224 });
	Background.PushBack({ 304, 1568, 304, 224 });
	Background.PushBack({ 608, 1568, 304, 224 });
	Background.PushBack({ 912, 1568, 304, 224 });
	Background.PushBack({ 1216, 1568, 304, 224 });
	Background.PushBack({ 1520, 1568, 304, 224 });
	Background.PushBack({ 1824, 1568, 304, 224 });
	Background.PushBack({ 2128, 1568, 304, 224 });
	Background.PushBack({ 2432, 1568, 304, 224 });
	Background.PushBack({ 2736, 1568, 304, 224 });
	Background.PushBack({ 3040, 1568, 304, 224 });
	Background.PushBack({ 3344, 1568, 304, 224 });
	Background.PushBack({ 3648, 1568, 304, 224 });
	Background.PushBack({ 3952, 1568, 304, 224 });
	Background.PushBack({ 4256, 1568, 304, 224 });
	Background.PushBack({ 4560, 1568, 304, 224 });
	Background.PushBack({ 4864, 1568, 304, 224 });
	Background.PushBack({ 5168, 1568, 304, 224 });
	Background.PushBack({ 5472, 1568, 304, 224 });
	Background.PushBack({ 5776, 1568, 304, 224 });
	Background.PushBack({ 0, 1792, 304, 224 });
	Background.PushBack({ 304, 1792, 304, 224 });
	Background.PushBack({ 608, 1792, 304, 224 });
	Background.PushBack({ 912, 1792, 304, 224 });
	Background.PushBack({ 1216, 1792, 304, 224 });
	Background.PushBack({ 1520, 1792, 304, 224 });
	Background.PushBack({ 1824, 1792, 304, 224 });
	Background.PushBack({ 2128, 1792, 304, 224 });
	Background.PushBack({ 2432, 1792, 304, 224 });
	Background.PushBack({ 2736, 1792, 304, 224 });
	Background.PushBack({ 3040, 1792, 304, 224 });
	Background.PushBack({ 3344, 1792, 304, 224 });
	Background.PushBack({ 3648, 1792, 304, 224 });
	Background.PushBack({ 3952, 1792, 304, 224 });
	Background.PushBack({ 4256, 1792, 304, 224 });
	Background.PushBack({ 4560, 1792, 304, 224 });
	Background.PushBack({ 4864, 1792, 304, 224 });
	Background.PushBack({ 5168, 1792, 304, 224 });
	Background.PushBack({ 5472, 1792, 304, 224 });
	Background.PushBack({ 5776, 1792, 304, 224 });
	Background.speed = 0.1;

	}

ModuleSNKComplete::~ModuleSNKComplete() {}

bool  ModuleSNKComplete::Start() {
	App->audio->LoadMusic("Music/start.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	graphics = App->textures->Load("Sprites/SNKComplete.png");
	Background.current_frame = 0;
	return true;
}

update_status  ModuleSNKComplete::Update() {

	App->render->Blit(graphics, 0, 0, &(Background.GetCurrentFrame()), 0.0f);


	if (App->input->keyboardstate[SDL_SCANCODE_SPACE] == KEY_PUSHED) {
		App->audio->StopMusic();
		App->fade->FadeToBlack(App->SNKComplete, App->scenewelcome, 2);
	}
	return UPDATE_CONTINUE;
}

bool  ModuleSNKComplete::CleanUp()
{
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->textures->Unload(graphics);
	return true;
}