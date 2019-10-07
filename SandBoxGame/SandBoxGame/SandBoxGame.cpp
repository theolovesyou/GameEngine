#include <qt\qapplication.h>
#include <QtGui\qwidget.h>
#include "MyGLWindow.h"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	MyGLWindow myGlWindow;
	myGlWindow.show();

	return application.exec();
}