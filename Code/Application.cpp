#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "Modulebackground.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleUkyoPlayer1.h"
#include "ModuleUkyoPlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneCongrats.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleFonts.h"
#include "ModuleUI.h"
#include "ModuleController.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = controller = new ModuleController();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = scenewelcome = new ModuleSceneWelcome();
	modules[i++] = background = new ModuleBackground();
	modules[i++] = sceneearthquake = new ModuleSceneEarthquake();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = ukyoplayer1 = new ModuleUkyoPlayer1();
	modules[i++] = ukyoplayer2 = new ModuleUkyoPlayer2();
	modules[i++] = scenecongrats = new ModuleSceneCongrats();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = UI = new ModuleUI();
	modules[i++] = fade = new ModuleFadeToBlack();


}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	player2->Disable();
	player->Disable();
	ukyoplayer2->Disable();
	ukyoplayer1->Disable();
	sceneearthquake->Disable();
	background->Disable();
	scenecongrats->Disable();
	collision->Disable();
	particles->Disable();
	UI->Disable();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		if (modules[i]->IsEnabled() == true) ret = modules[i]->CleanUp();

	return ret;
}