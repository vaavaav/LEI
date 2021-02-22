#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

float size = 1;
float inc  = -0.001; 
float r = 0.0f, g = 0.0f, b =0.0f;
float incC = 0.001f;

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you can�t make a window with zero width).
	if (h == 0)
		h = 1;
	// compute window's aspect ratio
	float ratio = w * 1.0f / h;
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void)
{
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// set camera
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 1.0f, 0.0f);
		
	// put drawing instructions here
	glutWireTeapot(size);
	glColor3f(r, g, b);
	
	// End of frame
	glutSwapBuffers();
}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
}

void resize(){

	if(size <= -1 || size > 1)
		inc *= -1;

	if(r < 0.0f ){
		incC *= -1;
		r += incC;
	}
	else 
		if(r < 1.0f)
			r += incC;
		else 
			if(g < 1.0f)
				g += incC;
			else
				if(b < 1.0f)
					b += incC;
				else if(b == 0){
					g += incC;
				}else
				{
					incC *= -1;
					b += incC;
				}

	
	size += inc;
	
	renderScene();
}


int main(int argc, char** argv)
{
	// put GLUT init here
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG@DI");

	// put callback registry here
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(resize);
	
	// some OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// enter GLUT�s main cycle
	glutMainLoop();
	
	return 1;
}