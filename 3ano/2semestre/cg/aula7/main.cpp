

#include<stdio.h>
#include<stdlib.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <chrono>
#include <ctime> 
#include <string.h>

#include <IL/il.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif



// VBO
GLuint buffers[1];
float * vertexB;
int arraySize = 0; 
int width = 0, height = 0;
int n_strips = 0, n_vertex_per_strip = 0;

float camX = 00, camY = 30, camZ = 40;
int startX, startY, tracking = 0;

int alpha = 0, beta = 45, r = 50;


unsigned char * imageData;

int now, n_trees = 100;


float h(int x, int z)
{
	if(imageData != NULL)
		return imageData[(x + (width/2)) * width + (z + (height/2))] * 0.1176470f;

	return 0.0f;
}


float hf(float px, float pz)
{

	auto x1 = (int) floor(px); 
	auto x2 = x1 + 1;
	auto z1 = (int) floor(pz); 
	auto z2 = z1 + 1;
	auto fz= pz-z1;   // 0 <= fz<= 1
	auto fx= px-x1;   // 0 <= fx<= 1
	auto h_x1_z  = h(x1,z1) * (1-fz) + h(x1,z2) * fz;
	auto h_x2_z  = h(x2,z1) * (1-fz) + h(x2,z2) * fz ;
	// The height at (px,pz)(blue dot)is computed using linear interpolation between the heights for (x1,pz)e (x2,pz) (green dots)
	auto height_xz= h_x1_z * (1 -fx) + h_x2_z * fx;

	return height_xz;
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the correct perspective
	gluPerspective(45,ratio,1,1000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void drawTerrain() {

	glPolygonMode(GL_FRONT, GL_FILL);

	glColor3f(0.074f, 0.427f, 0.08f);	

    glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	for(int i = 0; i < n_strips; i++)
		glDrawArrays(GL_TRIANGLE_STRIP, i * n_vertex_per_strip, n_vertex_per_strip);

}



void renderScene(void) {

	float pos[4] = {-1.0, 1.0, 1.0, 0.0};

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(camX, camY, camZ, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	int x, z;
	srand(now);

	
	for(int i = 0; i < n_trees; i++)
	{	
		x = (rand() % width) - width/2;
		z = (rand() % height) - height/2;
		if(abs(x) < 15 && abs(z) < 15){
			x += x < 0 ? -15 : 15;
			z += z < 0 ? -15 : 15;
		}
		glColor3f(0.34f, 0.21f, 0.02f);

		glPushMatrix();
		glTranslatef(x,hf(x,z),z);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(1.0f, 4.0f, 6, 6);
		glPopMatrix();

		glColor3f(0.21f, 0.34f, 0.02f);

		glPushMatrix();
		glTranslatef(x,2.0f + hf(x,z),z);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(3.0f, 10.0f, 6, 6);
		glPopMatrix();
	}

	

	drawTerrain();

	// just so that it renders something before the terrain is built
	// to erase when the terrain is ready

	//glColor3f(1.0f, 1.0f, 1.0f);
	//glutWireTeapot(1.0f);	

// End of frame
	glutSwapBuffers();
}



void processKeys(unsigned char key, int xx, int yy) {

// put code to process regular keys in here
}



void processMouseButtons(int button, int state, int xx, int yy) {
	
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
		else
			tracking = 0;
	}
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha += (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {
			
			r -= yy - startY;
			if (r < 3)
				r = 3.0;
		}
		tracking = 0;
	}
}


void processMouseMotion(int xx, int yy) {

	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {


		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux * 							     sin(betaAux * 3.14 / 180.0);
}


void init() {

	unsigned int t;
	
// 	Load the height map "terreno.jpg"

	ilGenImages(1,&t);
	ilBindImage(t);

	ilLoadImage((ILstring) "terreno.jpg");

	ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);

	height =  ilGetInteger(IL_IMAGE_HEIGHT);
	width = ilGetInteger(IL_IMAGE_WIDTH);

	n_strips = height - 1;
	n_vertex_per_strip = width * 2;

	imageData = ilGetData();

// 	Build the vertex arrays

	arraySize = n_strips * n_vertex_per_strip * 3 * sizeof(float);
	vertexB = (float *) malloc(arraySize);


	float translW = width / 2;
	float translH = height / 2;

	for(int i = 0; i < height - 1; i++)
		for(int j = 0; j < width; j++)
		{
			vertexB[i * 3 * n_vertex_per_strip + (j * 6)]     = (float) j - translW;
			vertexB[i * 3 * n_vertex_per_strip + (j * 6) + 1] = imageData[i * width + j] * 0.1176470f; 
			vertexB[i * 3 * n_vertex_per_strip + (j * 6) + 2] = (float) i - translH;

			vertexB[i * 3 * n_vertex_per_strip + (j * 6) + 3] = (float) j - translW;
			vertexB[i * 3 * n_vertex_per_strip + (j * 6) + 4] = imageData[(i + 1) * width + j] * 0.1176470f; 
			vertexB[i * 3 * n_vertex_per_strip + (j * 6) + 5] = (float) (i + 1) - translH;
		}

// VBO
	glEnableClientState(GL_VERTEX_ARRAY);
	glGenBuffers(1, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexB, GL_STATIC_DRAW);
	//free(vertexB);

// 	OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}


int main(int argc, char **argv) {


	now = std::time(0);

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("CG@DI-UM");

// Required callback registry 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);

	ilInit();
	glewInit();

	
	init();	

// enter GLUT's main cycle
	glutMainLoop();
	
	return 0;
}

