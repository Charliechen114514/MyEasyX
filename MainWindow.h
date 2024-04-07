#pragma once
#define BTN_SIZE	3
#include "Button.h"
#include <graphics.h>
typedef struct __MainWindow
{
	int			width;
	int			height;
	Button*		buttons[BTN_SIZE];
	CCBool		shellShutDown;
}MainWindow;

enum ButtonsIndex {
	SEARCH = 0,
	INSERT,
	CLOSE
};

extern MainWindow mainWindow;

void InitMainWindow(int w, int h);
void setUpMainWindow();
void processMouseMessage(const ExMessage m);
void cleanMainWindow();
