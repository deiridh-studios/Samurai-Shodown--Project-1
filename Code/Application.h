#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 22

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class Module;
class ModuleAudio;
class ModuleSceneEarthquake;
class ModuleSceneCongrats;
class ModuleSceneWelcome;
class ModuleSNKMenu;
class ModuleCharacterSelection;
class ModuleParticles;
class ModuleCollision;
class ModuleFonts;
class ModuleUI;
class ModuleController;
class ModuleSNKComplete;
class ModuleSlowdown;
class ModuleReferee;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleBackground* background;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleAudio* audio;
	ModuleSceneEarthquake* sceneearthquake;
	ModuleSceneCongrats* scenecongrats;
	ModuleSceneWelcome* scenewelcome;
	ModuleSNKMenu* SNKMenu;
	ModuleCharacterSelection* characterselection;
	ModuleCollision* collision;
	ModuleParticles* particles;
	ModuleFonts* fonts;
	ModuleUI* UI;
	ModuleSNKComplete * SNKComplete;
	ModuleController* controller;
	ModuleSlowdown* slowdown;
	ModuleReferee* referee;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__