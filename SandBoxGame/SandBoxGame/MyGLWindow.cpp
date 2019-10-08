#include <gl\glew.h>
#include <cassert>
#include "MyGLWindow.h"
#include <iostream>

using std::cout;
using std::endl;

static float verts[] =
{
	+0.0f, +0.1f,
	-0.1f, -0.1f,
	+0.1f, -0.1f,
};

void MyGLWindow::initializeGL()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);

	// ����, ������ ���� ID�� ������ ����
	glGenBuffers(1, &vertexBufferID);

	// glGenBuffers�� ������ ���ۿ� Ÿ���� �Ҵ�. GL_ARRAY_BUFFER�� ������ ���� �����͸� ����
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	
	// ���� ���ۿ� �����͸� �ִ´�. send those verts to graphic card
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void MyGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	// vertex�� x, y 2�����̹Ƿ� 2��° �Ķ���ʹ� 2.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	// 0���� �����ؼ� 3�� �׸�
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWindow::myUpdate()
{
	cout << "frame!" << endl;
}