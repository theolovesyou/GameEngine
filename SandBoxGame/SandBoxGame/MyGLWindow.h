#ifndef SANDBOX_MY_GL_WINDOW_H
#define SANDBOX_MY_GL_WINDOW_H
#include <QtOpenGL\qglwidget>

class MyGLWindow : public QGLWidget
{
	GLuint vertexBufferID;

protected:
	void initializeGL();
	void paintGL();
};

#endif