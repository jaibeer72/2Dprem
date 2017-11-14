#include "GLpremitives.h"
 
GLPremitives::GLPremitives()
{
	Vertex v = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f };
	return;
}

GLPremitives::~GLPremitives()
{
	return;
}

void GLPremitives::drawLineSegment(Vertex v1, Vertex v2, GLfloat width)
{
	glLineWidth(width);
	glBegin(GL_LINES);
	glColor4f(v1.r, v1.g, v1.b, v1.a);
	glVertex3f(v1.x, v1.y, v1.z);
	glColor4f(v2.r, v2.g, v2.b, v2.a);
	glVertex3f(v2.x, v2.y, v2.z);
	glEnd();
}

void GLPremitives::drawGrid(GLfloat width, GLfloat height, GLfloat grid_width,GLfloat L_Width)
{
	//horizontal lines
	for (float i = -height; i<height; i += grid_width) {
		Vertex v1 = { -width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		Vertex v2 = { width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		drawLineSegment(v1, v2,L_Width);
	}
	//vertical lines
	for (float i = -width; i<width; i += grid_width) {
		Vertex v1 = { i, -height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		Vertex v2 = { i, height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		drawLineSegment(v1, v2,L_Width);
	}
}

void GLPremitives::drawPoint(Vertex v1, GLfloat size)
{
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor4f(v1.r, v1.g, v1.b, v1.a);
	glVertex3f(v1.x, v1.y, v1.z);
	glEnd();
}

void GLPremitives::drawTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	glBegin(GL_TRIANGLES);
	glColor4f(v1.r, v1.g, v1.b, v1.a);
	glVertex3f(v1.x, v1.y, v1.z);
	glColor4f(v2.r, v2.g, v2.b, v2.a);
	glVertex3f(v2.x, v2.y, v2.z);
	glColor4f(v3.r, v3.g, v3.b, v3.a);
	glVertex3f(v3.x, v3.y, v3.z);
	glEnd();
}


