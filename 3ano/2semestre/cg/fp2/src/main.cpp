#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <cstdio>

float tx = 0.0f, ty = 0.0f, tz = 0.0f;
float rangle = 0.0f;
float sy = 1.0f;

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
	gluLookAt(5.0,5.0,5.0, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);



// put drawing instructions here

	glBegin(GL_LINES);
		// X axis in red

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);

		// Y axis in green

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 2.0f, 0.0f);

		// Z axis in blue

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);

	glEnd();

	// put the geometric transformations here

	glTranslatef(tx,ty,tz);

	glRotatef(rangle,0.0f,1.0f,0.0f);

	glScalef(1.0f,sy,1.0f);

	glBegin(GL_TRIANGLES);

		glColor3f(1.0f,1.0f,1.0f);
		
		//bottom face
		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, 0.0f,  1.0f);
		glVertex3f( 1.0f, 0.0f,  1.0f);

		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f( 1.0f, 0.0f,  1.0f);
		glVertex3f( 1.0f, 0.0f, -1.0f);

		// yellow face

		glColor3f(1.0f,1.0f,0.0f);

		glVertex3f( 0.0f, 2.0f,  0.0f);
		glVertex3f(-1.0f, 0.0f,  1.0f);
		glVertex3f( 1.0f, 0.0f,  1.0f);

		// purple face

		glColor3f(1.0f,0.0f,1.0f);

		glVertex3f( 0.0f, 2.0f,  0.0f);
		glVertex3f( 1.0f, 0.0f,  1.0f);
		glVertex3f( 1.0f, 0.0f, -1.0f);

		// idk face

		glColor3f(0.0f,1.0f,1.0f);

		glVertex3f( 0.0f, 2.0f,  0.0f);
		glVertex3f( 1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, 0.0f, -1.0f);


		// idk1 face

		glColor3f(0.5f,1.0f,0.5f);

		glVertex3f( 0.0f, 2.0f,  0.0f);
		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, 0.0f,  1.0f);


	glEnd();



	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events

void translateH_func(unsigned char key, int x, int y){

	switch(key){
		case 'w': tz = tz - 0.1f; break;
		case 's': tz = tz + 0.1f; break;
		case 'a': tx = tx - 0.1f; break;
		case 'd': tx = tx + 0.1f; break;
	}

	

	glutPostRedisplay();
}

void rotate_translateV_func(int key_code, int x, int y){

	switch(key_code){
		case GLUT_KEY_RIGHT: rangle = rangle + 5.0f; break;
		case GLUT_KEY_LEFT:  rangle = rangle - 5.0f; break;
		case GLUT_KEY_UP:    ty = ty + 0.1f; break;
		case GLUT_KEY_DOWN:  ty = ty - 0.1f; break;
	}

	glutPostRedisplay();
}

void scale_func(int button, int state, int x, int y){

	if(button == GLUT_LEFT && state == GLUT_DOWN)
		sy = ((0.5f * glutGet( GLUT_WINDOW_HEIGHT )) / y) - 0.25f;

	glutPostRedisplay();
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
	glutKeyboardFunc(translateH_func);
	glutSpecialFunc(rotate_translateV_func);
	glutMouseFunc(scale_func);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // drawn only triangles facing the camera
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
