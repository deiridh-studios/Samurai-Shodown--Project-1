#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"

class ModuleUI :public Module {
public:
	ModuleUI();
	~ModuleUI();
	bool Start();
	update_status Update();
	bool CleanUp();
private:
	int font_score;
	char time_text[10];
	uint time;
	uint initialtime;
};
#endif
