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
	
	// openGl이 GPU에 공간을 만들고 거기에 데이터를 넣는다.

	// 갯수, 생성한 버퍼 ID를 저장할 공간
	glGenBuffers(1, &vertexBufferID);

	// glGenBuffers로 생성한 버퍼에 타겟을 할당. GL_ARRAY_BUFFER는 정점에 대한 데이터를 생성
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	
	// 실제 버퍼에 데이터를 넣는다. send those verts to graphic card
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void MyGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	// vertex가 x, y 2차원이므로 2번째 파라미터는 2.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	Vector2D shipPosition(0.5f, 0.5f);
	Vector2D translatedVerts[NUM_VERTS];	
	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		translatedVerts[i] = verts[i] + shipPosition;
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	// 0에서 시작해서 3개 그림
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWindow::myUpdate()
{
	//cout << "frame!" << endl;
}