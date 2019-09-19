#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH * SCREEN_SIZE;
	camera.h = SCREEN_HEIGHT * SCREEN_SIZE;
	zooming = 1.0F;
	zoom = false;

}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	LOG("Render created succesfully|\n\n");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool use_camera, bool flip, bool zoom)
{

	bool ret = true;
	SDL_Rect rect;
	if (use_camera)
	{
		rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;// *zooming;
		rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE *zooming;
		//if(rect.x==43)rect.x = -8;
	}
	else
	{
		rect.x = x * SCREEN_SIZE;
		rect.y = y * SCREEN_SIZE;
	}

	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}
	if (use_camera) {
		rect.w *= zooming;
		rect.h *= zooming;
		if (zooming < 1.0F) {
			/*if (maintainx == true)rect.x *= zooming;
			if (camera.x > 36) rect.x += 467 * (1 - zooming);
			else if (camera.x < 0)*///rect.x += 233 * (1 - zooming);
			rect.y += 233 * (1 - zooming);
		}
	}
	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;
	if (flip == false) {
		if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}
	else {
		if (SDL_RenderCopyEx(renderer, texture, section, &rect, NULL, NULL, SDL_FLIP_HORIZONTAL) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}
	//	if(zoom==false&&zooming<1.0F)SDL_Delay(100);
	return ret;
}
bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);// *zooming);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE*zooming);
		rec.w *= SCREEN_SIZE * zooming;
		rec.h *= SCREEN_SIZE * zooming;
		if (zooming < 1.0F) {
			/*if(camera.x<-300) rec.x += 467 * (1 - zooming);
			else if(camera.x<0)*/// rec.x += 233 * (1 - zooming);
			rec.y += 233 * (1 - zooming);
		}


	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}