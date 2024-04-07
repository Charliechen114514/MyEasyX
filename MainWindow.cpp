#include "MainWindow.h"
#include "graphics.h"
#define MAINWND_BTN(index) mainWindow.buttons[(index)]


void InitMainWindow(int w, int h)
{
	mainWindow.height = h;
	mainWindow.width = w;
	mainWindow.shellShutDown = False;
	initgraph(mainWindow.width, mainWindow.height, EX_NOCLOSE);
}

void inittButtons()
{
	ButtonInfo info;
	info.height = 50;
	info.width = 70;
	info.left_x = 100;
	info.left_y = 100;

	Color color;
	setColorWhite(&color);
	Button* firstButton = createButton(&info, &color, &color);
	mainWindow.buttons[0] = firstButton;
	info.left_y += (20 + info.height);
	Button* secondButton = createButton(&info, &color, &color);
	mainWindow.buttons[1] = secondButton;
	info.left_y += (20 + info.height);
	Button* third_btn = createButton(&info, &color, &color);
	mainWindow.buttons[2] = third_btn;
}

void setButtonsText()
{
	setText(MAINWND_BTN(SEARCH), "≤È—Ø");
	setText(MAINWND_BTN(INSERT), "≤Â»Î");
	setText(MAINWND_BTN(CLOSE), "πÿ±’");
}

void manageBtns()
{
	inittButtons();
	setButtonsText();
}

void setUpMainWindow()
{
	manageBtns();
	for (int i = 0; i < BTN_SIZE; i++)
		drawButton(mainWindow.buttons[i]);
}

void cleanMainWindow()
{
	for (int i = 0; i < BTN_SIZE; i++)
		eraseButton(mainWindow.buttons[i]);
}

void processMouseMessage(const ExMessage m)
{
	switch (m.message)
	{
	case WM_LBUTTONDOWN:
		if (checkIsInButton(mainWindow.buttons[2], m.x, m.y))
		{
			closegraph();
			mainWindow.shellShutDown = True;
		}
	}
}


