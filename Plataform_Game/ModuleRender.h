#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "Globals.h"


struct SDL_Renderer;
struct SDL_Texture;


class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status PreUpdate();
	bool CleanUp();

	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f, bool use_camera = true, bool flip = false, bool zoom = false);
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* tex;
	SDL_Rect camera;
	SDL_Rect cameraleft;
	SDL_Rect cameraright;
	bool zoom;
	float zooming;


};

#endif //__ModuleRenderer_H__