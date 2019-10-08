#include <gl\glew.h>
#include "MyGLWindow.h"
#include <cassert>
#include <iostream>
#include <Math\Vector2D.h>

using Math::Vector2D;
//using std::cout;
//using std::endl;

static Vector2D verts[] =
{
	Vector2D(+0.0f, +0.1f),
	Vector2D(-0.1f, -0.1f),
	Vector2D(+0.1f, -0.1f),
};

static const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);

void MyGLWindow::initializeGL()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);
	
	// openGl�� GPU�� ������ ����� �ű⿡ �����͸� �ִ´�.

	// ����, ������ ���� ID�� ������ ����
	glGenBuffers(1, &vertexBufferID);

	// glGenBuffers�� ������ ���ۿ� Ÿ���� �Ҵ�. GL_ARRAY_BUFFER�� ������ ���� �����͸� ����
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	
	// ���� ���ۿ� �����͸� �ִ´�. send those verts to graphic card
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void MyGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	// vertex�� x, y 2�����̹Ƿ� 2��° �Ķ���ʹ� 2.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	Vector2D shipPosition(0.5f, 0.5f);
	Vector2D translatedVerts[NUM_VERTS];	
	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		translatedVerts[i] = verts[i] + shipPosition;
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	// 0���� �����ؼ� 3�� �׸�
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWindow::myUpdate()
{
	//cout << "frame!" << endl;
}