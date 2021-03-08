#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

int nowX, nowY;
float zoom = 5.0f;
int zoom_dir = 0;
float spin = 0.0f;
bool isSpinning = false, isZooming = false;

void mouse(int buton, int state, int x, int y)
{
    switch (buton) {
    case GLUT_LEFT_BUTTON:
        isSpinning = state == GLUT_DOWN;
		nowX = x;
        break;
	case 3: 
		isZooming = state == GLUT_DOWN;
		zoom_dir = -1;
		break;
	case 4: 
		isZooming = state == GLUT_DOWN;
		zoom_dir = 1;
		break;
    }
}


void spinDisplay(int x, int y) //here it's the problematic function
{	
	
    if (isSpinning)
    {
        spin += (x - nowX) * 0.01;
        if (spin > 2 * M_PI)
        {
            spin = spin - 2 * M_PI;
        }
		nowX = x;
    }
	if (isZooming)
    {
        zoom += 0.1 * zoom_dir;
        if (zoom < 0)
        {
			zoom = 0;
        }
    }

	if(isSpinning || isZooming)
		glutPostRedisplay();
}

void drawCylinder(float r, float h, int slices)
{

	// x = p * cos (phi)
	// y = r
	// z = p * sin (phi)

	float phi = 0.0f, inc_phi = (2 * M_PI) / slices;
	float succ_phi = inc_phi;

    glBegin(GL_TRIANGLES);

		glColor3f(0.0f,0.0f,0.0f);
		
		for(; phi < (2 * M_PI); phi += inc_phi, succ_phi += inc_phi)
		{
			// top circle triangle
			glVertex3f(0, h/2 , 0);
			glVertex3f(r * cos(succ_phi), h/2, r * sin(succ_phi));
			glVertex3f(r * cos(phi), h/2, r * sin(phi));

			// bottom 
			glVertex3f(0, -h/2 , 0);
			glVertex3f(r * cos(phi), -h/2, r * sin(phi));
			glVertex3f(r * cos(succ_phi), -h/2, r * sin(succ_phi));

			// slice
			glVertex3f(r * cos(phi), h/2, r * sin(phi));
			glVertex3f(r * cos(succ_phi), h/2, r * sin(succ_phi));
			glVertex3f(r * cos(phi), -h/2, r * sin(phi));

			glVertex3f(r * cos(succ_phi), h/2, r * sin(succ_phi));
			glVertex3f(r * cos(succ_phi), -h/2, r * sin(succ_phi));
			glVertex3f(r * cos(phi), -h/2, r * sin(phi));
		}

	glEnd();


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
	gluLookAt(zoom*cos(spin),5.0,zoom*sin(spin), 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here

// put drawing instructions here
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	drawCylinder(1.0f,1.0f,8);

	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events






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
	glutMotionFunc(spinDisplay);
	
// put here the registration of the keyboard callbacks
	glutMouseFunc(mouse);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
