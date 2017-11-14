
#include<GLFW\glfw3.h>
//#include<GL\GLU.h>
#include <stdlib.h>
#include <stdio.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>
typedef struct Vertex
{
	GLfloat x, y, z; //position
	GLfloat r, g, b, a; //color and alpha channels
};

class GLPremitives
{
public:
	GLPremitives();
	~GLPremitives();
	void drawLineSegment(Vertex v1, Vertex v2, GLfloat width); 
	void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width,GLfloat L_Width);
	void drawPoint(Vertex v1, GLfloat size);
	void drawTriangle(Vertex v1, Vertex v2, Vertex v3);
};
