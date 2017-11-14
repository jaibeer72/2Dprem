#include"GLpremitives.h"
#include <math.h>

const int WINDOWS_WIDTH = 640 * 2;
const int WINDOWS_HEIGHT = 480;

using namespace std; 
GLPremitives Prem;

GLFWwindow* OpenGL_INITILIZE() {
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, "Chapter 2: Primitive drawings", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	return window;
}

void OpenGL_BasicAA() {

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGL_ViewPort(int width, int height) {
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void drawLineDemo() {
	GLPremitives classey;
	//draw a simple grid
	//Prem.drawGrid(5.0f, 1.0f, 0.1f,2.0f);
	//define the vertices and colors of the line segments
	Vertex v1 = { -5.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.7f };
	Vertex v2 = { 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.7f };
	Vertex v3 = { 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.7f };
	Vertex v4 = { 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.7f };
	//draw the line segments
	Prem.drawLineSegment(v1, v2, 10.0f);
	Prem.drawLineSegment(v3, v4, 10.0f);
}
void drawTriangleDemo() {
	//Triangle Demo
	Vertex v1 = { 0.0f, 0.8f, 0.0f, 1.0f, 0.0f, 0.0f, 0.6f };
	Vertex v2 = { -1.0f, -0.8f, 0.0f, 0.0f, 1.0f, 0.0f, 0.6f };
	Vertex v3 = { 1.0f, -0.8f, 0.0f, 0.0f, 0.0f, 1.0f, 0.6f };
	Prem.drawTriangle(v1, v2, v3);
}

//void drawPointsDemo(int width, int height) {
//	GLfloat size = 5.0f;
//	for (GLfloat x = 0.0f; x <= 1.0f; x += 0.2f, size += 5)
//	{
//		GLPremitives::Vertex v1 = { x, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
//		drawPoint(v1, size);
//	}
//}

typedef struct Data
{
	GLfloat x, y, z; 
};

void draw2DscatterPlot(const Data *data, int num_points) {
	Vertex v1 = { -10.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	Vertex v2 = { 10.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	Prem.drawLineSegment(v1, v2, 2.0f);
	v1.x = 0.0f;
	v2.x = 0.0f;
	v1.y = -1.0f;
	v2.y = 1.0f;
	Prem.drawLineSegment(v1, v2, 2.0f);
	for (int i = 0; i<num_points; i++) {
		GLfloat x = data[i].x;
		GLfloat y = data[i].y;
		Vertex v = { x, y, 0.0f, 1.0f, 1.0f, 1.0f, 0.5f };
		Prem.drawPoint(v, 8.0f);
	}
}
void draw2DLineSegments(const Data *data, int num_points) {
	for (int i = 0; i<num_points - 1; i++) {
		GLfloat x1 = data[i].x;
		GLfloat y1 = data[i].y;
		GLfloat x2 = data[i + 1].x;
		GLfloat y2 = data[i + 1].y;
		Vertex v1 = { x1, y1, 0.0f, 0.0f, 1.0f, 1.0f, 0.5f };
		Vertex v2 = { x2, y2, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f };
		Prem.drawLineSegment(v1, v2, 4.0f);
	}
}
void linePlotDemo(float phase_shift) {
	Prem.drawGrid(5.0f, 1.0f, 0.1f,0.1f);
	GLfloat range = 10.0f;
	const int num_points = 200;
	Data *data = (Data*)malloc(sizeof(Data)*num_points);
	for (int i = 0; i<num_points; i++) {
		data[i].x = ((GLfloat)i / num_points)*range - range / 2.0f;
		data[i].y = 0.8f*cosf(data[i].x*3.14f + phase_shift);
	}
	draw2DscatterPlot(data, num_points);
	draw2DLineSegments(data, num_points);
	free(data);
}
int main(void)
{
	GLFWwindow* window;
	window=OpenGL_INITILIZE();
	OpenGL_BasicAA();
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		float phase_shift=0.0f;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = (float)width / (float)height;
		OpenGL_ViewPort(width,height);
		//Orthographic Projection
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Upadate Code here
		phase_shift += 0.02f;
		linePlotDemo(phase_shift);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}