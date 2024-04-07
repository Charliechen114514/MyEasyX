#pragma once
#include "Color.h"

typedef struct __Font {
	int		_text_leng;
	int		_text_width;
	const wchar_t*_font;
}Font;

Font*	createFont(int text_len, int text_wid, char* font);
CCBool	eraseFont(Font* f);

typedef struct __Text
{
	wchar_t*	stringbuf;
	Color*		textColor;
	Font*		textFont;
}Text;

Text*	createText(const char* text);
void	resetText(Text* text, const char* raw_text);
void	resetTextColor(Text* text, const Color* color);
void	setFont(Text* text, const Font* font);
void	draw_Text(const Text* t, int pos_x, int pos_y);
CCBool	eraseText(Text* text);
