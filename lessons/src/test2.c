#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;

float lastx, lasty;

//positions of the cubes
float positionz = 5.0;
float positionx = 5.0;

// cube postions
double rotate_y=0; 
double rotate_x=0;

//draw the cube
void cube (void) {
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(-positionx * 10, 0, -positionz * 10); //translate the cube
    glutSolidCube(2); //draw the cube
    glPopMatrix();
}

void enable (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
}

void camera (void) {
    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();  
    camera();
    enable();
    cube(); //call the cube drawing function
    glutSwapBuffers(); //swap the buffers
    angle++; //increase the angle
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y) {
    switch(key) {
        case 'w':
            rotate_x += 5;
            break;
        case 'a':
    		rotate_y -= 5;
            break;
        case 's':
		    rotate_x -= 5;
            break;
        case 'd':
            rotate_y += 5;
            break;
        case 27:
            exit(0);
            break;
    }
}

void pressKey(int key, int xx, int yy) {
    float xrotrad, yrotrad;

    switch (key) {
        case GLUT_KEY_UP:
            yrotrad = (yrot / 180 * 3.141592654f);
            xrotrad = (xrot / 180 * 3.141592654f); 
            
            xpos += (float)sin(yrotrad);
            zpos -= (float)cos(yrotrad);
            ypos -= (float)sin(xrotrad);

            break;
        case GLUT_KEY_LEFT:
            yrotrad = (yrot / 180 * 3.141592654f);
            
            xpos -= (float)cos(yrotrad) * 0.2;
            zpos -= (float)sin(yrotrad) * 0.2;

            break;
        case GLUT_KEY_DOWN:
            yrotrad = (yrot / 180 * 3.141592654f);
            xrotrad = (xrot / 180 * 3.141592654f); 
            
            xpos -= (float)sin(yrotrad);
            zpos += (float)cos(yrotrad);
            ypos += (float)sin(xrotrad);

            break;
         case GLUT_KEY_RIGHT:
            yrotrad = (yrot / 180 * 3.141592654f);
            
            xpos += (float)cos(yrotrad) * 0.2;
            zpos += (float)sin(yrotrad) * 0.2;

            break;
    }
} 

void mouseMovement(int x, int y) {
    int diffx=x-lastx; //check the difference between the current x and the last x position
    int diffy=y-lasty; //check the difference between the current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A basic OpenGL Window"); 
    glutDisplayFunc (display); 
    glutIdleFunc (display); 
    glutReshapeFunc (reshape);

    glutPassiveMotionFunc(mouseMovement); //check for mouse movement

    glutKeyboardFunc (keyboard); 
    glutMainLoop (); 
    return 0;
}