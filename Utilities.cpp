#include "Utilities.h"

char* copy_heap_str(const char* text)
{
	int str_len = strlen(text) + 1;
	char* new_str = NULL;
	SAFE_MALLOC_BYTE(new_str, str_len);
	memcpy(new_str, text, str_len);
	return new_str;
}
