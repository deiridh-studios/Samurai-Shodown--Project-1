#ifndef __StateMachine_H__
#define __StateMachine_H__

#include "Globals.h"
#include "ModulePlayer.h"
#include "Module.h"

void Preupdate(int& jumptimer, int& punchtimer, int& kicktimer, int& specialattack_timer, int& hitted_timer, int& inputsouts, iPoint position, bool flip, state actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS], Module* player, Animation& current);
Animation* ExecuteState(bool &sword, bool pow,bool &notfinished,int& jump_timer, int& punch_timer, int& kick_timer, int& specialattack_timer, int& hitted_timer, state actual, bool flip, int speed, int& mult, bool stopright, bool stopleft, bool& aftercouch,Collider& body, Collider& body2, Collider& body3, Collider **attack, iPoint& position, Module* Player, Animation& current);
void CheckState(bool &notfinished,int& jump_timer, int& punch_timer, int& kick_timer, int &specialattack_timer, int &inputsouts, state& actual, inputin inputstate[60], inputout inputstateout[INPUTSOUTS]);
void CheckSpecialAttacks(inputin inputstate[60], bool inair[60]);
#endif