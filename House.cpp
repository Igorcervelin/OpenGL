#include <stdlib.h>
#include <GL/glut.h>

void resize(GLsizei w, GLsizei h);
void display(void);
void casa();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA
	glutInitWindowSize(400, 400);  // tamanho da janela
	glutInitWindowPosition(10, 300); // posicao inicial da janela

	glutCreateWindow("Casa");   /// cria a janela
	glutReshapeFunc(&resize);
	glutDisplayFunc(display);
	glutMainLoop();

	return EXIT_SUCCESS;
}

void resize(GLsizei w, GLsizei h){

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h){
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}else{
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 255.0f, 1.0f);  // cor do fundo 

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	casa();
	glFlush(); // Executa o desenho
}

void casa() {
	glBegin(GL_TRIANGLES);
	glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(80, 150);
	glVertex2f(200, 150);
	glVertex2f(140, 180);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(255.0f, 255.0f, 0.0f);
	glVertex2f(80, 20);
	glVertex2f(200, 20);
	glVertex2f(200, 150);
	glVertex2f(80, 150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 255, 0);
	glVertex2f(0, 0);
	glColor3f(0, 153, 0);
	glVertex2f(0, 20);
	glColor3f(0, 225, 0);
	glVertex2f(500, 20);
	glColor3f(0, 153, 0);
	glVertex2f(500, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.35f, 0.3f, 0.1f);
	glVertex2f(80, 20);
	glVertex2f(111, 20);
	glVertex2f(111, 60);
	glVertex2f(80, 60);
	glEnd();

	glLineWidth(4.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(225.0f, 225.0f, 225.0f);
	glVertex2f(120, 90);
	glVertex2f(120, 115);
	glColor3f(0.0f, 0.0f, 225.0f);
	glVertex2f(145, 115);
	glVertex2f(145, 90);
	glEnd();

	glLineWidth(4.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(98, 36);
	glVertex2f(98, 39);
	glVertex2f(101, 39);
	glVertex2f(101, 36);
	glEnd();
}
