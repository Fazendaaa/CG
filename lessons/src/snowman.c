#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// angle of rotation for the camera direction
float angle = 0.0f;

/*
gluLookAt( x,    1.0f,  z,
		   x+lx, 1.0f,  z+lz,
		   0.0f, 1.0f,  0.0f);
*/
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=5.0f, z=22.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

// wich figure
int figure = 0; // 0 == cube, 1 == teapot, 2 == cone
double rotate_x = 0, rotate_y = 0;
// figure postions
GLfloat rotate_x_cube = 0.0f, rotate_x_cha = 0.0f, rotate_x_cone = 0.0f, rotate_y_cube = 0.0f, rotate_y_cha = 0.0f, rotate_y_cone = 0.0f;
//	figures rotations -- first: cube / second: teapot / third: cone
int translate = 0;
int scale = 0;
float porportion = 0, porportion_cube = 1, porportion_cha = 1, porportion_cone = 1;

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

void movementFigure() {
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
}

void computePos(float deltaMove) {
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void renderScene(void) {
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

	glPushMatrix();
	glTranslatef(0.0, 0.0, 7.0);
	glRotatef(rotate_x_cube,1.0f,0.0f,0.0f );
	glRotatef(rotate_y_cube,0.0f,1.0f,0.0f);
	glScalef(porportion_cube, porportion_cube, porportion_cube);
	glutSolidCube((GLdouble) 2); //draw the cube
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.0, 0, 5.0);
	glRotatef(rotate_x_cha, 1.0f, 0.0f, 0.0f );
	glRotatef(rotate_y_cha, 0.0f, 1.0f, 0.0f);
	glScalef(porportion_cha, porportion_cha, porportion_cha);
	glutSolidTeapot((GLdouble) 2); //draw the teapot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 0, 5.0);
	glRotatef(rotate_x_cone, 1.0f, 0.0f, 0.0f );
	glRotatef(rotate_y_cone, 0.0f, 1.0f, 0.0f);
	glScalef(porportion_cone, porportion_cone, porportion_cone);
	glutSolidCone((GLdouble) 2,(GLdouble) 5,(GLint) 180,(GLint) 180);//draw the cone
	glPopMatrix();

    glutSwapBuffers();
} 

void processNormalKeys(unsigned char key, int xx, int yy) { 
	switch(figure){
		case 0:
			rotate_x = rotate_x_cube;
			rotate_y = rotate_y_cube;
			break;
		case 1:
			rotate_x = rotate_x_cha;
			rotate_y = rotate_y_cha;
			break;
		case 2:
			rotate_x = rotate_x_cone;
			rotate_y = rotate_y_cone;
			break;
	}

	switch(key) {
		//	ESC
		case 27:
			exit(0);
			break;
		//  Up arrow - increase rotation by 5 degree
		case 'w':
			rotate_x += 5;
			scale = 0;
			break;
		//  Left arrow - decrease rotation by 5 degree
		case 'a':
			rotate_y -= 5;
			scale = 0;
			break;
		//  Down arrow - decrease rotation by 5 degree
		case 's':
			rotate_x -= 5;
			scale = 0;
			break;
		//  Right arrow - increase rotation by 5 degree
		case 'd':
			rotate_y += 5;
			scale = 0;
			break;
		case 'e':
			scale = !scale;
			porportion = 0;
			break;
		case 'r':
			porportion += 0.2;
			break;
		case 'f':
			porportion -= 0.2;
			break;
	}

	switch(figure){
		case 0:
			rotate_x_cube = rotate_x;
			rotate_y_cube = rotate_y;
			if(scale)
				if(0.2 <= porportion_cube && 3 >= porportion_cube) {
					porportion_cube += porportion;
					printf("%f", porportion_cube);
				}
			break;
		case 1:
			rotate_x_cha = rotate_x;
			rotate_y_cha = rotate_y;
			if(scale)
				porportion_cha += porportion;
			break;
		case 2:
			rotate_x_cone = rotate_x;
			rotate_y_cone = rotate_y;
			if(scale)
				porportion_cone += porportion;
			break;
	}

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
		case GLUT_KEY_F1:
			figure = 0;
			scale = 0;
			porportion = 0;
			break;
		case GLUT_KEY_F2:
			figure = 1;
			scale = 0;
			porportion = 0;
			break;
		case GLUT_KEY_F3:
			figure = 2;
			scale = 0;
			porportion = 0;
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
	glutInitWindowSize(1320,920);
	glutCreateWindow("T2");
	enable();

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

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
