#include <stdlib.h>
#include <GL/glut.h>

void resize(GLsizei w, GLsizei h);
void display(void);
void barco();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA
	glutCreateWindow("Barco");   /// cria a janela
	//glutInitWindowSize(800, 800);  // tamanho da janela
	glutReshapeFunc(&resize);
	glutFullScreen();
	//glutInitWindowPosition(10, 300); // posicao inicial da janela
	glutDisplayFunc(display);
	glutMainLoop();

	return EXIT_SUCCESS;
}

void resize(GLsizei w, GLsizei h) {

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

							 // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h) {
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else {
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0f, 0.58f, 0.0f, 1.0f);  // cor do fundo 

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	barco();
	glFlush(); // executa o desenho
}

void barco() {
	glBegin(GL_QUADS); //sol
	glColor3f(255, 255, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 450);
	glColor3f(1.0f, 0.58f, 0.0f);
	glVertex2f(280, 450);
	glVertex2f(280, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.2f, 0.2f);
	glVertex2f(15, 20);
	glVertex2f(5, 60);
	glVertex2f(125, 60);
	glVertex2f(100, 20);
	glEnd();

	glBegin(GL_QUADS); // Chaminé
	glColor3f(0.35f, 0.2f, 0.2f);
	glVertex2f(20, 60);
	glVertex2f(20, 105);
	glVertex2f(35, 105);
	glVertex2f(35, 60);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.2f, 0.2f);
	glVertex2f(35, 60);
	glVertex2f(35, 70);
	glVertex2f(65, 70);
	glVertex2f(75, 60);
	glEnd();

	glBegin(GL_QUADS); // Pier
	glColor3f(0.35f, 0.3f, 0.1f);
	glVertex2f(180, 0);
	glVertex2f(180, 34);
	glVertex2f(301, 34);
	glVertex2f(301, 0);
	glEnd();

	glBegin(GL_QUADS); // Grama
	glColor3f(0.58f, 0.86f, 0.44f);
	glVertex2f(300, 0);
	glColor3f(0.19f, 0.31f, 0.19f);
	glVertex2f(300, 30);
	glColor3f(0.19f, 0.31f, 0.19f);
	glVertex2f(500, 30);
	glColor3f(0.58f, 0.86f, 0.44f);
	glVertex2f(500, 0);
	glEnd();

	glBegin(GL_QUADS); // Tronco
	glColor3f(0.35f, 0.3f, 0.1f);
	glVertex2f(350, 27);
	glVertex2f(350, 50);
	glVertex2f(357, 50);
	glVertex2f(357, 27);
	glEnd();

	glBegin(GL_TRIANGLES); // Árvore 1
	glColor3f(0.19f, 0.31f, 0.19f);
	glVertex2f(340, 50);
	glVertex2f(366, 50);
	glVertex2f(353, 105);
	glEnd();

	glBegin(GL_TRIANGLES); // Árvore 2
	glColor3f(0.19f, 0.31f, 0.19f);
	glVertex2f(340, 60);
	glVertex2f(366, 60);
	glVertex2f(353, 110);
	glEnd();

	glBegin(GL_TRIANGLES); // Árvore 3
	glColor3f(0.19f, 0.31f, 0.19f);
	glVertex2f(340, 70);
	glVertex2f(366, 70);
	glVertex2f(353, 120);
	glEnd();

	glBegin(GL_QUADS); // Água
	glColor3f(0.44f, 0.58f, 86.0f);
	glVertex2f(0, 0);
	glColor3f(1.0f, 0.81f, 0.0f);
	glVertex2f(0, 20);
	glColor3f(0.44f, 0.58f, 86.0f);
	glVertex2f(300, 20);
	glVertex2f(300, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 1
	glVertex2f(185, 0);
	glVertex2f(185, 46);
	glVertex2f(191, 46);
	glVertex2f(191, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 2
	glVertex2f(205, 0);
	glVertex2f(205, 46);
	glVertex2f(211, 46);
	glVertex2f(211, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 3
	glVertex2f(225, 0);
	glVertex2f(225, 46);
	glVertex2f(231, 46);
	glVertex2f(231, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 4
	glVertex2f(245, 0);
	glVertex2f(245, 46);
	glVertex2f(251, 46);
	glVertex2f(251, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 5
	glVertex2f(265, 0);
	glVertex2f(265, 46);
	glVertex2f(271, 46);
	glVertex2f(271, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f); // Cerca 6
	glVertex2f(285, 0);
	glVertex2f(285, 46);
	glVertex2f(291, 46);
	glVertex2f(291, 0);
	glEnd();
}