#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("sprites/Haohfix1(tornado apart).png");

	// Tornado particle

	////////Tornado animation

	tornado.anim.PushBack({ 204, 773, 86, 90 });
	tornado.anim.PushBack({ 346, 773, 86, 90 });
	tornado.anim.PushBack({ 485, 773, 86, 90 });
	tornado.anim.PushBack({ 633, 773, 86, 90 });
	tornado.anim.PushBack({ 770, 773, 86, 90 });
	tornado.anim.PushBack({ 897, 773, 86, 90 });
	tornado.anim.PushBack({ 1050, 773, 86, 90 });
	tornado.anim.PushBack({ 1185, 773, 86, 90 });
	tornado.anim.PushBack({ 1329, 773, 86, 90 });
	tornado.anim.PushBack({ 1469, 773, 86, 90 });
	tornado.anim.PushBack({ 1619, 773, 86, 90 });
	tornado.anim.PushBack({ 1769, 773, 86, 90 });
	tornado.anim.PushBack({ 44, 874, 71, 203 });
	tornado.anim.PushBack({ 188, 874, 71, 203 });
	tornado.anim.PushBack({ 338, 874, 71, 203 });
	tornado.anim.PushBack({ 484, 874, 71, 203 });
	tornado.anim.PushBack({ 616, 874, 71, 203 });
	tornado.anim.PushBack({ 765, 874, 71, 203 });
	tornado.anim.PushBack({ 907, 874, 71, 203 });
	tornado.anim.PushBack({ 1061, 874, 71, 203 });
	tornado.anim.PushBack({ 1344, 874, 71, 203 });
	tornado.anim.PushBack({ 1489, 874, 71, 203 });
	tornado.anim.PushBack({ 1625, 874, 71, 203 });
	tornado.anim.PushBack({ 46, 1083, 46, 213});
	tornado.anim.PushBack({ 196, 1083, 46, 213 });
	tornado.anim.PushBack({ 337, 1083, 46, 213 });
	tornado.anim.PushBack({ 468, 1083, 46, 213 });
	tornado.anim.PushBack({ 562, 1083, 46, 213 });
	tornado.anim.PushBack({ 706, 1083, 46, 213 });
	tornado.anim.speed = 0.2f;
	tornado.speed.x = 5;
	tornado.life = 3000;

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if ((int)SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = (int)SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if (((int)SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.GetFinished()==0)
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

