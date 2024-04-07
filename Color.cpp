#include "Color.h"


static CCBool check_color_validity(short index)
{
	return 0 <= index && index <= 255;
}

CCBool isValidColor(const Color* color)
{
	if (!color)
		return False;

	return
		check_color_validity(color->r) &&
		check_color_validity(color->g) &&
		check_color_validity(color->b);
}

Color* createColor(short r, short g, short b)
{
	Color* new_color = NULL;
	SAFE_MALLOC(new_color, Color);
	new_color->r = r;
	new_color->g = g;
	new_color->b = b;
	return new_color;
}

Color* clone_color(const Color* color) 
{
	Color* new_color = NULL;
	SAFE_MALLOC(new_color, Color);
	COPY_PROPERTY(new_color, color, r);
	COPY_PROPERTY(new_color, color, g);
	COPY_PROPERTY(new_color, color, b);
	return new_color;
}

CCBool eraseColor(Color* color)
{
	SAFE_FREE(color);
	return True;
}

void setColorBlack(Color* color) {
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void setColorWhite(Color* color) {
	color->r = 255;
	color->g = 255;
	color->b = 255;
}

DWORD toRGB(const Color* color) {
	return RGB(color->r, color->g, color->b);
}



