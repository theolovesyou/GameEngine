#include <gl\glew.h>
#include <cassert>
#include "MyGLWindow.h"

void MyGLWindow::initializeGL()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);

	// 갯수, 생성한 버퍼 ID를 저장할 공간
	glGenBuffers(1, &vertexBufferID);

	// glGenBuffers로 생성한 버퍼에 타겟을 할당
	// GL_ARRAY_BUFFER는 정점에 대한 데이터를 생성
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	float verts[] =
	{
		+0.0f, +0.1f,
		-0.1f, -0.1f,
		+0.1f, -0.1f,
	};

	// 실제 버퍼에 데이터를 넣는다. send those verts to graphic card
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
}

void MyGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	// vertex가 x, y 2차원이므로 2번째 파라미터는 2.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	// 0에서 시작해서 3개 그림
	glDrawArrays(GL_TRIANGLES, 0, 3);
}