#pragma once
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef bool
typedef unsigned char CCBool;
#else
typedef bool CCBool;
#endif


#define True	(1)
#define False	(0)

#define PrintStdErr(MSG)	do{fprintf(stderr, MSG);}while(0)

#define SAFE_MALLOC(pointer, type) do{\
	type* __CC_Pointer = (type*)malloc(sizeof(type));\
	if(!__CC_Pointer){\
		PrintStdErr("Error in mallocing space! Process Crashed!\n");\
		exit(-1);\
	} \
	pointer = __CC_Pointer; \
}while(0);

#define SAFE_MALLOC_BYTE(pointer, size) do{\
	char* __CC_Pointer = (char*)malloc(sizeof(char) * (size));\
	if(!__CC_Pointer){\
		PrintStdErr("Error in mallocing space! Process Crashed!\n");\
		exit(-1);\
	} \
	pointer = __CC_Pointer; \
}while(0)

#define SAFE_MALLOC_N_TYPE(pointer, num, type) do{\
	type* __CC_Pointer = (type*)malloc(sizeof(type) * (num));\
	if(!__CC_Pointer){\
		PrintStdErr("Error in mallocing space! Process Crashed!\n");\
		exit(-1);\
	} \
	pointer = __CC_Pointer; \
}while(0)

#define SAFE_FREE(pointer) do{\
	free(pointer); \
	pointer = NULL; \
}while(0)

#define COPY_PROPERTY(copiee, copier, _property) copiee->_property = copier->_property

char* copy_heap_str(const char* text);

