#ifndef __StateMachine_H__
#define __StateMachine_H__

#include "Globals.h"
#include "ModulePlayer.h"
#include "Module.h"

void Preupdate(int& jumptimer, int& punchtimer, int& kicktimer, int& tornado_timer, int& hitted_timer, int& inputsouts, iPoint position, bool flip, state actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS], Module* player);
//void ExecuteState(int& jump_timer, int& punch_timer, int& kick_timer, int& tornado_timer, int& hitted_timer, state actual, bool flip, int speed, int& mult, bool stopright, bool stopleft, Animation& current_animation, Collider& body, Collider& body2, Collider& body3, Collider *attack, iPoint& position, Module* Player);
void CheckState(int& jump_timer, int& punch_timer, int& kick_timer, int &tornado_timer, int &inputsouts, state& actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS]);
void CheckSpecialAttacks(inputin inputstate[60]);
#endif