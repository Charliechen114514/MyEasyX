#pragma once
#include "Color.h"
#include "Text.h"
typedef struct __ButtonInfo
{
	int left_x;
	int left_y;
	int width;
	int height;
}ButtonInfo;

typedef struct __Button
{
	ButtonInfo* infos;
	Color*		buttonLineColor;
	Color*		buttonAreaColor;
	Text*		btn_caption;
}Button;

Button* createButton(const ButtonInfo* info, const Color* line_color, const Color* area_color);
void	drawButton(const Button* btn);
void	setText(Button* btn, const char* raw_text);
CCBool	checkIsInButton(const Button* btn, int pos_x, int pos_y);
CCBool	eraseButton(Button* btn);
