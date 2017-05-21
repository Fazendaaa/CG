/*
				Lucas Almeida Carotta, 		8598732
				Nilson Furquim da Silva, 	8937250
				Victor Hugo Heclis, 		8937382
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// angle of rotation for the camera direction
float angle = 0.0f, depth = 0;

// actual vector representing the camera's direction
float lx=0.0f, ly=0.0f, lz=-1.0f;

// XZ position of the camera
float x=5.0f, y=1.0f, z=22.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f, alphaAngle = 0;
float deltaMove = 0;
int xOrigin = -1;
int yOrigin = -1;

// wich figure
int figure = 0; // 0 == cube, 1 == teapot, 2 == cone
double rotate_x = 0, rotate_y = 0, rotate_z = 0;
// figure postions
GLfloat rotate_x_cube = 0.0f, rotate_x_cha = 0.0f, rotate_x_cone = 0.0f;
GLfloat rotate_y_cube = 0.0f, rotate_y_cha = 0.0f, rotate_y_cone = 0.0f;
GLfloat rotate_z_cube = 0.0f, rotate_z_cha = 0.0f, rotate_z_cone = 0.0f;
GLfloat translate_x_cube = 0.0f, translate_y_cube = 0.0f, translate_z_cube = 0.0f;
GLfloat translate_x_cha = 0.0f, translate_y_cha = 0.0f, translate_z_cha = 0.0f;
GLfloat translate_x_cone = 0.0f, translate_y_cone = 0.0f, translate_z_cone = 0.0f;
//	figures rotations -- first: cube / second: teapot / third: cone
float translate_x = 0, translate_y = 0, translate_z = 0;
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

void computePos() {
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
	y += deltaMove * ly * 0.1f;
}

void renderScene(void) {
	if (deltaMove)
		computePos();

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt( x,    y,    z,
			   x+lx, y+ly, z+lz,
			   0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0, 0.0, 7.0);
	glTranslatef(translate_x_cube, translate_y_cube, translate_z_cube);
	glRotatef(rotate_x_cube,1.0f,0.0f,0.0f);
	glRotatef(rotate_y_cube,0.0f,1.0f,0.0f);
	glRotatef(rotate_z_cube,0.0f,0.0f,1.0f);
	glScalef(porportion_cube, porportion_cube, porportion_cube);
	glutSolidCube((GLdouble) 2); //draw the cube
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.0, 0, 5.0);
	glTranslatef(translate_x_cha, translate_y_cha, translate_z_cha);
	glRotatef(rotate_x_cha, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate_y_cha, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate_z_cha, 0.0f, 0.0f, 1.0f);
	glScalef(porportion_cha, porportion_cha, porportion_cha);
	glutSolidTeapot((GLdouble) 2); //draw the teapot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 0, 5.0);
	glTranslatef(translate_x_cone, translate_y_cone, translate_z_cone);
	glRotatef(rotate_x_cone, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate_y_cone, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate_z_cone, 0.0f, 0.0f, 1.0f);
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
			rotate_z = rotate_z_cube;
			translate_x = translate_x_cube;
			translate_y = translate_y_cube;
			translate_z = translate_z_cube;
			break;
		case 1:
			rotate_x = rotate_x_cha;
			rotate_y = rotate_y_cha;
			rotate_z = rotate_z_cha;
			translate_x = translate_x_cha;
			translate_y = translate_y_cha;
			translate_z = translate_z_cha;
			break;
		case 2:
			rotate_x = rotate_x_cone;
			rotate_y = rotate_y_cone;
			rotate_z = rotate_z_cone;
			translate_x = translate_x_cone;
			translate_y = translate_y_cone;
			translate_z = translate_z_cone;
			break;
	}

	switch(key) {
		//	ESC
		case 27:
			exit(0);
			break;
		//  Increase roatiton x axis
		case 'q':
			rotate_x += 5;
			break;
		//  Decrease roatiton x axis
		case 'a':
			rotate_x -= 5;
			break;
		//  Increase roatiton y axis
		case 'w':
			rotate_y += 5;
			break;
		//  Decrease roatiton y axis
		case 's':
			rotate_y -= 5;
			break;
		case 'e':
			rotate_z += 5;
			break;
		//  Decrease roatiton y axis
		case 'd':
			rotate_z -= 5;
			break;
		//	Move right side figure
		case 'r':
			translate_x += 0.5;
			break;
		//	Move left side figure
		case 'f':
			translate_x -= 0.5;
			break;
		//	Move up figure
		case 't':
			translate_y += 0.5;
			break;
		//	Move down figure
		case 'g':
			translate_y -= 0.5;
			break;
		//	Move foward figure
		case 'y':
			translate_z += 0.5;
			break;
		//	Move backward figure
		case 'h':
			translate_z -= 0.5;
			break;						
		//	Increase figure size
		case 'u':
			porportion += 0.2;
			break;
		//	Decrease figure size
		case 'j':
			porportion -= 0.2;
			break;
	}

	switch(figure){
		case 0:
			rotate_x_cube = rotate_x;
			rotate_y_cube = rotate_y;
			rotate_z_cube = rotate_z;
			translate_x_cube = translate_x;
			translate_y_cube = translate_y;
			translate_z_cube = translate_z;
			if(0.2 <= porportion_cube+porportion && 3 >= porportion_cube+porportion)
				porportion_cube += porportion;
			break;
		case 1:
			rotate_x_cha = rotate_x;
			rotate_y_cha = rotate_y;
			rotate_z_cha = rotate_z;
			translate_x_cha = translate_x;
			translate_y_cha = translate_y;
			translate_z_cha = translate_z;
			if(0.2 <= porportion_cha+porportion && 3 >= porportion_cha+porportion)
				porportion_cha += porportion;
			break;
		case 2:
			rotate_x_cone = rotate_x;
			rotate_y_cone = rotate_y;
			rotate_z_cone = rotate_z;
			translate_x_cone = translate_x;
			translate_y_cone = translate_y;
			translate_z_cone = translate_z;
			if(0.2 <= porportion_cone+porportion && 3 >= porportion_cone+porportion)
				porportion_cone += porportion;
			break;
	}

	porportion = 0;
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
		case GLUT_KEY_F1:
			figure = 0;
			porportion = 0;
			break;
		case GLUT_KEY_F2:
			figure = 1;
			porportion = 0;
			break;
		case GLUT_KEY_F3:
			figure = 2;
			porportion = 0;
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
	}
} 

void mouseMove(int x, int y) { 	
	// this will only be true when the left button is down
	if (xOrigin >= 0) {
		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;
		alphaAngle = (y - yOrigin) * 0.001f;
		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
		ly = -sin(depth + alphaAngle);
	}    
}

void mouseButton(int button, int state, int x, int y) {
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			depth += alphaAngle;
			xOrigin = -1;
			yOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
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
