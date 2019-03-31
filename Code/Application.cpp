#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "Modulebackground.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneEarthquake.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneCongrats.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = textures = new ModuleTextures();
	modules[2] = input = new ModuleInput();
	modules[3] = render = new ModuleRender();
	modules[4] = audio = new ModuleAudio();
	modules[5] = scenewelcome = new ModuleSceneWelcome();
	modules[6] = background = new ModuleBackground();
	modules[7] = sceneearthquake = new ModuleSceneEarthquake();
	modules[8] = player = new ModulePlayer();
	modules[9] = scenecongrats = new ModuleSceneCongrats();
	modules[10] = fade = new ModuleFadeToBlack();

}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	player->Disable();
	sceneearthquake->Disable();
	background->Disable();
	scenecongrats->Disable();

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