#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

ModuleTextures::ModuleTextures() : Module()
{
	for (int i = 0; i < MAX_TEXTURES; i++) {
		textures[i] = nullptr;
	}
}

// Destructor
ModuleTextures::~ModuleTextures()
{}

// Called before render is available
bool ModuleTextures::Init()
{
	LOG("Init Image library");
	bool ret = true;

	// load support for the PNG image format
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if((init & flags) != flags)
	{
		LOG("Could not initialize Image lib.\n\n\n\n IMG_Init: %s", IMG_GetError());
		ret = false;
	}
	("Could initilialze\n\n\n");
	return ret;
}

// Called before q	uitting
bool ModuleTextures::CleanUp()
{
	LOG("Freeing textures and Image library");

	for (int i = MAX_TEXTURES - 1; i >= 0; i--) {
		if (textures[i] != nullptr) SDL_DestroyTexture(textures[i]);
	}

	IMG_Quit();
	return true;
}

// Load new texture from file path
SDL_Texture* const ModuleTextures::Load(const char* path)
{
	SDL_Surface *test=NULL;
	test = IMG_Load(path);
	if (test == NULL) {
		LOG("Image not correct\n\n\n\n\n");
		LOG(IMG_GetError());
		return false;
	}
	LOG("Image correct\n\n\n\n\n");
	SDL_Texture* testtext;
	testtext=SDL_CreateTextureFromSurface(App->render->renderer, test);
	if (testtext == NULL) {
		LOG("Texture not correct\n\n\n\n\n");
		LOG(IMG_GetError());
		return false;
	}
	SDL_FreeSurface(test);
	int j = 0;
	for (int i = 0; i < MAX_TEXTURES; i++) {
		if (textures[i] == nullptr) {
			textures[i] = testtext;
			return testtext;
		}
	}
	return nullptr;
}
