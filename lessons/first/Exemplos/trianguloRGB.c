#include<GL/glut.h>

void Draw(void) {
	// Define a cor de fundo da cena
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Aplica a cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	// Define os v�rtices de um tri�ngulo
	glBegin(GL_TRIANGLES);
		glVertex2f(20.0f, -30.0f);
		glVertex2f(180.0f, -30.0f);
		glVertex2f(100.0f, 30.0f);
	glEnd();

	// Envia os dados para serem desenhados
	glFlush();
}

// Fun��o respons�vel por tratar eventos de mouse
void Mouse(int button, int state, int x, int y) {
	// Se o bot�o utilizado for o direito, a fun��o exit(0) ser� executada.
	if (button == GLUT_RIGHT_BUTTON)
	{
		exit(0);
	}
}

// Fun��o respons�vel por tratar eventos de teclado
void Keyboard(unsigned char key, int x, int y) {
	// Se a tecla cujo c�digo ASCII � 27 (ESC) for pressionada
	// a fun��o glutReshapeWindow ser� chamada
	if (key == 27)
	{
		exit( 0 );
	}
}


int main(int argc, char **argv) {
	// Inicializa a gut
	glutInit(&argc, argv);

	// Define o modo de inicializa��o do display
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Define o centro da tela como posi��o inicial da janela
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 640) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 480) / 2);

	// Define o tamanho da janela
	glutInitWindowSize(640, 480);

	// Define o nome da Janela e a cria
	glutCreateWindow("Exemplo OpenGL");

	// Define qual a fun��o callback de desenho
	glutDisplayFunc(Draw);

	// Define a fun��o callback respons�vel por tratar eventos de teclado
	glutKeyboardFunc(Keyboard);
	
	// Define a fun��o callback respons�vel por tratar eventos de mouse
	glutMouseFunc(Mouse);

	// Define os pontos de corte das coordenadas de tela/rasteriza��o nas coordenadas globais
	gluOrtho2D(0, 200, -40, 40);

	// gluOrtho2D(0, 200, 40, -40); descomente este trecho e comente o trecho acima para 
	// inveter o eixo y

	// Loop da glut
	glutMainLoop();
}