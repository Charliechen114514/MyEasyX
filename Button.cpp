#include "Button.h"
#include "graphics.h"
#include "Color.h"



static ButtonInfo* clone_btn_info(const ButtonInfo* b) 
{
	if (!b)
		return NULL;
	ButtonInfo* info = NULL;
	SAFE_MALLOC(info, ButtonInfo);
	COPY_PROPERTY(info, b, left_x);
	COPY_PROPERTY(info, b, left_y);
	COPY_PROPERTY(info, b, width);
	COPY_PROPERTY(info, b, height);
	return info;
}


Button* createButton(const ButtonInfo* info, const Color* line_color, const Color* area_color)
{
	if (!info || !line_color || !area_color)
		return NULL;

	Button* button = NULL;
	SAFE_MALLOC(button, Button);
	ButtonInfo* btn_info = clone_btn_info(info);
	Color* lineColor = clone_color(line_color);
	Color* areaColor = clone_color(area_color);
	if (!btn_info || !lineColor || !areaColor)
		return NULL;

	button->infos = btn_info;
	button->buttonAreaColor = areaColor;
	button->buttonLineColor = lineColor;
	button->btn_caption = NULL;
	return button;
}

CCBool	eraseButton(Button* btn)
{
	SAFE_FREE(btn->infos);
	SAFE_FREE(btn->buttonLineColor);
	SAFE_FREE(btn->buttonAreaColor);
	SAFE_FREE(btn->btn_caption);
	SAFE_FREE(btn);
	return True;
}

void	setText(Button* btn, const char* raw_text)
{
	if (!btn->btn_caption)
	{
		btn->btn_caption = createText(raw_text);
	}
	else
	{
		resetText(btn->btn_caption, raw_text);
	}
}

void	drawButton(const Button* btn)
{
	ButtonInfo* info = btn->infos;
	setlinecolor(toRGB(btn->buttonLineColor));
	rectangle(info->left_x, info->left_y, info->left_x + info->width, info->left_y + info->height);
	setfillcolor(toRGB(btn->buttonAreaColor));
	fillrectangle(info->left_x, info->left_y, info->left_x + info->width, info->left_y + info->height);
	if(btn->btn_caption)
	{
		draw_Text(btn->btn_caption, info->left_x + 10, info->left_y + 10);
	}
	return;
}


CCBool checkIsInButton(const Button* btn, int pos_x, int pos_y)
{
	ButtonInfo* info = btn->infos;
	return pos_x >= info->left_x && pos_x <= info->width + info->left_x &&
		pos_y >= info->left_y && pos_y <= info->height + info->left_y;
}
