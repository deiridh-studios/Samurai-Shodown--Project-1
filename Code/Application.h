#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 18

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModulePlayer;
class ModulePlayer2;
class ModuleUkyoPlayer1;
class ModuleUkyoPlayer2;
class ModuleFadeToBlack;
class Module;
class ModuleAudio;
class ModuleSceneEarthquake;
class ModuleSceneCongrats;
class ModuleSceneWelcome;
class ModuleParticles;
class ModuleCollision;
class ModuleFonts;
class ModuleUI;

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
	ModuleUkyoPlayer1* ukyoplayer1;
	ModuleUkyoPlayer2* ukyoplayer2;
	ModuleFadeToBlack* fade;
	ModuleAudio* audio;
	ModuleSceneEarthquake* sceneearthquake;
	ModuleSceneCongrats* scenecongrats;
	ModuleSceneWelcome* scenewelcome;
	ModuleCollision* collision;
	ModuleParticles* particles;
	ModuleFonts* fonts;
	ModuleUI* UI;

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