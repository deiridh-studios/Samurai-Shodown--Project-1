#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "Modulebackground.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneCongrats.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleFonts.h"
#include "ModuleUI.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = fonts = new ModuleFonts();
	modules[5] = audio = new ModuleAudio();
	modules[6] = scenewelcome = new ModuleSceneWelcome();
	modules[7] = background = new ModuleBackground();
	modules[8] = sceneearthquake = new ModuleSceneEarthquake();
	modules[9] = player = new ModulePlayer();
	modules[10] = player2 = new ModulePlayer2();
	modules[11] = scenecongrats = new ModuleSceneCongrats();
	modules[12] = particles = new ModuleParticles();
	modules[13] = collision = new ModuleCollision();
	modules[14] = UI = new ModuleUI();
	modules[15] = fade = new ModuleFadeToBlack();
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