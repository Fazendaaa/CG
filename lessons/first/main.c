#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/*  ---------------------------- GLOBAL VARIABLES --------------------------  */


/*  --------------------------------- HEADERS ------------------------------  */


/*  ----------------------------------- MAIN -------------------------------  */


/*  ----------------------------- IMPLEMENTATIONS --------------------------  */

float pos_x = 0.0f, pos_y =0.0f;

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

void drawTri( void ) {
	glTranslatef( pos_x, pos_y, 0 );

	glBegin(GL_TRIANGLES);
		glVertex3f( -0.5f, -0.5f, 0.0f );
		glVertex3f(  0.5f,  0.0f, 0.0f );
		glVertex3f(  0.0f,  0.5f, 0.0f );
	glEnd();

	pos_x += -0.01f;
	pos_y +=  0.01f;
}

void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 0.0f, 10.0f,	/*	Eye postion	*/
				0.0f, 0.0f,  0.0f,	/*	Look at the origin	*/
				0.0f, 1.0f,  0.0f); /*	Positive Y up vector	*/

	glPushMatrix( );
	drawTri( );
	glPopMatrix( );

	glutSwapBuffers( );
}


void keyboard(unsigned char key, int xx, int yy) {
	if (key == 27)
		exit( 0 );
}

void mouse(int button, int state, int x, int y) {
	// Se o bot�o utilizado for o direito, a fun��o exit(0) ser� executada.
	if (button == GLUT_RIGHT_BUTTON)
		exit(0);
	/*
	if (button == GLUT_LEFT_BUTTON)	{
		pos_x = x;
		pos_y = y;
	}
	*/
}

int main(int argc, char **argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
/*  ---------------------------------- EOF ---------------------------------  */
