#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <ctime> 

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;

int n_cowboys_and_indians = 10;
float cowboys_and_indians_angle = (2.0f * M_PI) / n_cowboys_and_indians;
float cowboys_and_indians_offset = 0.0f;

int now;

int n_trees = 1500;

void updateValues(){

	cowboys_and_indians_offset += 0.01f;
	if(cowboys_and_indians_offset >= 2.0f * M_PI)
		cowboys_and_indians_offset -= 2.0f * M_PI;

	glutPostRedisplay();
}


void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {
	

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();
	// End of frame
	
	
	// put code to draw scene in here
	
	for(int i = 0; i < n_cowboys_and_indians; i++)
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glPushMatrix();
		glRotatef((i * cowboys_and_indians_angle + cowboys_and_indians_offset) * 360.0 / (2 * M_PI), 0.0f, 1.0f, 0.0f);
		glTranslatef(4,0.5f, 0);
		glutSolidTeapot(1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(7,0.0f, 0);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		glutSolidTeapot(1.0f);
		glPopMatrix();
	}

	glColor3f(1.0f, 5.0f, 0.0f);
	glutSolidTorus(0.2f, 0.5f, 10, 10);
	
	int x, z;
	srand(now);

	for(int i = 0; i < n_trees; i++)
	{	
		x = (rand() % 200) - 100;
		z = (rand() % 200) - 100;
		if(abs(x) < 15 && abs(z) < 15){
			x += x < 0 ? -15 : 15;
			z += z < 0 ? -15 : 15;
		}
		glColor3f(0.34f, 0.21f, 0.02f);

		glPushMatrix();
		glTranslatef(x,0,z);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(1.0f, 4.0f, 6, 6);
		glPopMatrix();

		glColor3f(0.21f, 0.34f, 0.02f);

		glPushMatrix();
		glTranslatef(x,2.0f,z);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(3.0f, 10.0f, 6, 6);
		glPopMatrix();
	}
	
	// rand(void); // return sa number between0 and RAND_MAX
	
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

}


void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;

	case GLUT_KEY_PAGE_DOWN: radius -= 10.0f;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 10.0f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();

}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin");
}


int main(int argc, char **argv) {

	now = std::time(0);

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(updateValues);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
