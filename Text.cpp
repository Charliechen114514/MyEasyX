#include <string.h>
#include "Text.h"
#include "easyX.h"
static Font default_font = { 20, 0, _T("宋体") };
Font* createFont(int text_len, int text_wid, wchar_t* font)
{
	Font* f = NULL;
	SAFE_MALLOC(f, Font);
	f->_font = font;
	f->_text_leng = text_len;
	f->_text_width = text_wid;

	return f;
}

Font* clone_font(const Font* f)
{
	Font* new_f = NULL;
	SAFE_MALLOC(new_f, Font);
	COPY_PROPERTY(new_f, f, _text_leng);
	COPY_PROPERTY(new_f, f, _text_width);
	COPY_PROPERTY(new_f, f, _font);
	return new_f;
}

CCBool	eraseFont(Font* f)
{
	SAFE_FREE(f);
	return True;
}

Text* createText(const char* raw_text)
{
	Text* text = NULL;
	SAFE_MALLOC(text, Text);
	size_t str_len = strlen(raw_text) + 1;
	int num = MultiByteToWideChar(0, 0, raw_text, -1, NULL, 0);
	wchar_t* wide = NULL;
	SAFE_MALLOC_N_TYPE(wide, num, wchar_t);
	MultiByteToWideChar(0, 0, raw_text, -1, wide, num);
	text->stringbuf = wide;
	Color* color;
	SAFE_MALLOC(color, Color);
	setColorWhite(color);
	text->textColor = color;
	Font* font = NULL;
	font = clone_font(&default_font);
	text->textFont = font;
	return text;
}

void resetTextColor(Text* text, const Color* color)
{
	COPY_PROPERTY(text->textColor, color, r);
	COPY_PROPERTY(text->textColor, color, g);
	COPY_PROPERTY(text->textColor, color, b);
}

void resetText(Text* text, const char* raw_text) 
{
	SAFE_FREE(text->stringbuf);
	int num = MultiByteToWideChar(0, 0, raw_text, -1, NULL, 0);
	wchar_t* wide = NULL;
	SAFE_MALLOC_N_TYPE(wide, num, wchar_t);
	MultiByteToWideChar(0, 0, raw_text, -1, wide, num);
	text->stringbuf = wide;
}


void	setFont(Text* text, const Font* font)
{
	COPY_PROPERTY(text->textFont, font, _text_leng);
	COPY_PROPERTY(text->textFont, font, _text_width);
	COPY_PROPERTY(text->textFont, font, _font);
}

void draw_Text(const Text* t, int pos_x, int pos_y)
{
	settextstyle(t->textFont->_text_leng, 0, t->textFont->_font);
	settextcolor(toRGB(t->textColor));
	outtextxy(pos_x,pos_y, t->stringbuf); //设置显示位置
}

CCBool eraseText(Text* text)
{
	SAFE_FREE(text->stringbuf);
	SAFE_FREE(text->textColor);
	SAFE_FREE(text);
	return True;
}
