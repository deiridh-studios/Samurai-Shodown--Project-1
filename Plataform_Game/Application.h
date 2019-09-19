#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "Globals.h"

#define NUM_MODULES 10

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleSceneOne;
class ModulePlayer;
class Module;
class ModuleAudio;
class ModuleCollision;
class ModuleController;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneOne* sceneone;
	ModulePlayer* player;
	ModuleAudio* audio;
	ModuleCollision* collision;
	ModuleController* controller;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif