#pragma once
#include "Utilities.h"
#include "graphics.h"
typedef struct __Color
{
	short r;
	short g;
	short b;
}Color;


CCBool	isValidColor(const Color* color);
Color*	clone_color(const Color* color);
Color*	createColor(short r, short g, short b);
CCBool	eraseColor(Color* color);
void	setColorWhite(Color* color);
void	setColorBlack(Color* color);
DWORD	toRGB(const Color* color);
