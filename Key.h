#pragma once

#include<Dxlib.h>
#define KeyKindMax 256

void KeyInit();
void KeyUpdate();
bool KeyDown(int KEY_INPUT);
bool KeyClick(int KEY_INPUT);
int KeyPressFrame(int KEY_INPUT);