#include "MainWindow.h"
#include "Button.h"
// Global for the project

MainWindow mainWindow;
int main()
{
	InitMainWindow(640, 480);
	setUpMainWindow();

	while (!mainWindow.shellShutDown)
	{
		ExMessage m = getmessage(EM_MOUSE);//��ȡ�����Ϣ
		processMouseMessage(m);
	}

	cleanMainWindow();
}
