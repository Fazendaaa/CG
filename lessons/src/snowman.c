#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f, z=5.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

// wich figure
int figure = 0; // 0 == cube, 1 == teapot, 2 == cone

// figure postions
double cube_rotate_y=0, cube_rotate_x=0;
double tea_rotate_y=0, tea_rotate_x=0;
double cone_rotate_y=0, cone_rotate_x=0;

void enable(void) {
    glEnable(GL_DEPTH_TEST); //enable the depth testing
    glEnable(GL_LIGHTING); //enable the lighting
    glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glShadeModel(GL_SMOOTH); //set the shader to smooth shader
}

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawCube() {
	// Rotate when user changes rotate_x and rotate_y
	if(0 == figure) {
		glRotatef(cube_rotate_x, 1.0, 0.0, 0.0);
		glRotatef(cube_rotate_y, 0.0, 1.0, 0.0);
	}

	glPushMatrix();
    glutSolidCube((GLdouble) 2); //draw the cube
	//glutSolidCone((GLdouble) 2,(GLdouble) 5,(GLint) 180,(GLint) 180);
    glPopMatrix();
}

void drawTeapot() {
	// Rotate when user changes rotate_x and rotate_y
	if(1 == figure) {
		glRotatef(tea_rotate_x, 1.0, 0.0, 0.0);
		glRotatef(tea_rotate_y, 0.0, 1.0, 0.0);
	}

	glPushMatrix();
	glutSolidTeapot((GLdouble) 2); //draw the teapot
    glPopMatrix();
}

void drawCone() {
	// Rotate when user changes rotate_x and rotate_y
	if(2 == figure) {
		glRotatef(cone_rotate_x, 1.0, 0.0, 0.0);
		glRotatef(cone_rotate_y, 0.0, 1.0, 0.0);
	}

	glPushMatrix();
	glutSolidCone((GLdouble) 2,(GLdouble) 5,(GLint) 180,(GLint) 180);//draw the cone
    glPopMatrix();
}

void computePos(float deltaMove) {
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void renderScene(void) {
	enable();
	if (deltaMove)
		computePos(deltaMove);

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt( x,    1.0f,  z,
			   x+lx, 1.0f,  z+lz,
			   0.0f, 1.0f,  0.0f);

	// Draw cube
	glTranslatef(10.0, 0, 10.0);
	drawCube();
	glTranslatef(5.0, 0, 5.0);
	drawTeapot();
	glTranslatef(5.0, 0, 5.0);
	drawCone();
    glutSwapBuffers();
} 

void processNormalKeys(unsigned char key, int xx, int yy) { 
	switch(key) {
		//	ESC
		case 27:
			exit(0);
			break;
		case 'd':
			switch(figure) {
				case 0:
					cube_rotate_y += 5;
					break;
				case 1:
					tea_rotate_y += 5;
					break;
				case 2:
					cone_rotate_y += 5;
					break;
			}
			break;
	}

	// ESC
	if (key == 27)
		exit(0);
	//  Right arrow - increase rotation by 5 degree
	if (key == 'd')
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == 'a')
		rotate_y -= 5;

	else if (key == 'w')
		rotate_x += 5;

	else if (key == 's')
		rotate_x -= 5;

	//  Request display update
	glutPostRedisplay();
} 

void pressKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_UP:
			deltaMove = 0.5f;
			break;
		case GLUT_KEY_DOWN:
			deltaMove = -0.5f;
			break;
	}
} 

void releaseKey(int key, int x, int y) { 	
	switch (key) {
		case GLUT_KEY_UP:
			deltaMove = 0;
			break;
		case GLUT_KEY_DOWN:
			deltaMove = 0;
			break;
		case GLUT_KEY_F1 :
			figure = 0;
			break;
		case GLUT_KEY_F2 :
			figure = 1;
			break;
		case GLUT_KEY_F3 :
			figure = 2;
			break;
	}
} 

void mouseMove(int x, int y) { 	
	// this will only be true when the left button is down
	if (xOrigin >= 0) {
		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

int main(int argc, char **argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	//glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
