#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 50

#include "Module.h"
#include "SDL/include/SDL_rect.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL_LEFT,
	COLLIDER_WALL_RIGHT,
	COLLIDER_PLAYER,
	COLLIDER_ENEMY,
	COLLIDER_TO_ACTION,
	COLLIDER_PLAYER_SHOT,
	COLLIDER_LIANA,
	COLLIDER_AGUA,
	COLLIDER_LAVA,
	COLLIDER_HIELO,
	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int, int);

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate() override;
	update_status Update() override;
	bool CleanUp() override;

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	void DebugDraw();

private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug = false;
};

#endif // __ModuleCollision_H__