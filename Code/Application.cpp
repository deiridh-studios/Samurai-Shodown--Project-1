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
#include "ModuleSNKMenu.h"
#include "ModuleCharacterSelection.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleFonts.h"
#include "ModuleUI.h"
#include "ModuleSNKComplete.h"
#include "ModuleSlowdown.h"
#include "ModuleReferee.h"
#include "ModuleController.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = controller = new ModuleController();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = scenewelcome = new ModuleSceneWelcome();
	modules[i++] = SNKMenu = new ModuleSNKMenu();
	modules[i++] = characterselection = new ModuleCharacterSelection();
	modules[i++] = background = new ModuleBackground();
	modules[i++] = sceneearthquake = new ModuleSceneEarthquake();
	modules[i++] = referee = new ModuleReferee();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = scenecongrats = new ModuleSceneCongrats();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = SNKComplete = new ModuleSNKComplete();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = UI = new ModuleUI();
	modules[i++] = slowdown = new ModuleSlowdown();

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
	referee->Disable();
	player->Disable();
	sceneearthquake->Disable();
	scenewelcome->Disable();
	SNKComplete->Disable();
	characterselection->Disable();
	background->Disable();
	scenecongrats->Disable();
	collision->Disable();
	particles->Disable();
	slowdown->Disable();

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