#include "Globals.h"
#include "Application.h"
#include "ModuleSceneOne.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include"ModuleCollision.h"
#include "SDL/include/SDL.h"

ModuleSceneOne::ModuleSceneOne() :Module() {
	// Water1 animation
	back.PushBack({ 0, 0, 640, 416 });
	back.PushBack({ 640, 0, 640, 416 });
	back.PushBack({ 1280, 0, 640, 416 });
	back.PushBack({ 1920, 0, 640, 416 });
	back.PushBack({ 0, 416, 640, 416 });
	back.PushBack({ 640, 416, 640, 416 });
	back.PushBack({ 1280, 416, 640, 416 });
	back.PushBack({ 1920, 416, 640, 416 });
	back.speed = 0.08f;

}

ModuleSceneOne::~ModuleSceneOne() {}

bool ModuleSceneOne::Start() {
	scrollleft = 0;
	scrollright = 0;
	fade = false;
	App->audio->LoadMusic("Music/BackgroundUkyo.ogg");
	App->audio->PlayMusic(App->audio->musics[0]);
	Ukyo = App->audio->LoadChunk("Audio_FX/Ukyo.wav");
	App->audio->PlayChunk(Ukyo);
	graphics = App->textures->Load("Sprites/UkyoBackground.png");
	cameraleftcol = App->collision->AddCollider({ App->render->camera.x,App->render->camera.y,1,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT, App->sceneone);
	camerarightcol = App->collision->AddCollider({ App->render->camera.x,App->render->camera.y,1,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT, App->sceneone);
	App->player->Enable();
	App->collision->Enable();
	return true;
}

update_status ModuleSceneOne::Update() {
	App->render->Blit(graphics, -170, -170, &(back.GetCurrentFrame()), 0.9f, true, false, App->render->zoom);  //Background

	cameraleft.x = (-App->render->camera.x) / SCREEN_SIZE;
	cameraleft.y = 0;
	cameraright.x = ((-App->render->camera.x) / SCREEN_SIZE) + (App->render->camera.w / SCREEN_SIZE) - 1;
	cameraright.y = 0;
	cameraleftcol->SetPos(cameraleft.x, cameraleft.y);
	camerarightcol->SetPos(cameraright.x, cameraright.y);
	return UPDATE_CONTINUE;
}
bool ModuleSceneOne::CleanUp()
{
	App->audio->StopChunk();
	App->audio->UnLoadChunk(Ukyo);
	App->audio->UnLoadMusic(App->audio->musics[0]);
	App->player->Disable();
	App->collision->Disable();
	App->textures->Unload(graphics);
	return true;
}
void ModuleSceneOne::OnCollision(Collider* wall, Collider* enemy) {

}