#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define VK_Q 0x51
#define VK_A 0x41
#define VK_P 0x50
#define VK_L 0x4C
#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 1500

// Variáveis de movimentação X e Y
float tx = 0;
float ty = 0;

// Coordenadas variáveis para X e Y
float lty = 40.0;
float lby = -60.0;
float rty = 40.0;
float rby = -60.0;

// Número de passos movidos por Loop de animação
float xStep = 1;
float yStep = 1;
float baseyStep = 17;

// Declaração de funções
void anima(int valor);
void keyboard();
void update(int valor); int interval = 1000 / 60;
void display(void);
void tela(GLsizei w, GLsizei h);

// Main
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Pong game");
	glutReshapeFunc(tela);
	glutFullScreen();
	glutTimerFunc(1, anima, 10);
	glutTimerFunc(50, update, 1);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}
// Função de animação
void anima(int valor) {

	// Definir limite superior e inferior
	if((ty) < -492){
		yStep = -yStep;
	}

	if ((ty) > 397) {
		yStep = -yStep;
	}

	// Se a bolinha sair do campo, volta para o meio
	if ((tx) > (900)) {
		tx = 0;
	}

	if ((tx) < (-800)) {
		tx = 0;
	}

	// Caso bater na raquete, a bolinha volta
	if ((tx) == (625)) {
		if (ty < rty && ty > rby) {
			xStep = -xStep;
		}
	}

	if (tx == -600) {
		if (ty < lty && ty > lby) {
			xStep = -xStep;
		}
	}


	tx += xStep;
	ty += yStep;

	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);
}

void update(int valor) {
	keyboard();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay;
}

void bolinha() {

	glTranslated(tx, ty, 0);

	// Bolinha
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 15.0f, raioY = 15.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();	
}

void pong() {
	
	// Linha do meio
	glBegin(GL_QUADS);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(2, 500);
	glVertex2f(2, -493);
	glVertex2f(-2, -493);
	glVertex2f(-2, 500);
	glEnd();

	// Linha de cima
	glBegin(GL_QUADS);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(800, 400);
	glVertex2f(800, 398);
	glVertex2f(-800, 398);
	glVertex2f(-800, 400);
	glEnd();

	// Linha de baixo
	glBegin(GL_QUADS);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(1000, -495);
	glVertex2f(1000, -493);
	glVertex2f(-1000, -493);
	glVertex2f(-1000, -495);
	glEnd();

	// Base direita
	glBegin(GL_QUADS);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(625, rty);
	glVertex2f(625, rby);
	glVertex2f(650, rby);
	glVertex2f(650, rty);
	glEnd();

	// Base esquerda
	glBegin(GL_QUADS);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(-600, lty);
	glVertex2f(-600, lby);
	glVertex2f(-625, lby);
	glVertex2f(-625, lty);
	glEnd();
}

// Função para utilizar o teclado
void keyboard() {

	if (GetAsyncKeyState(VK_Q)) {
		if (lty < 398) {
			lty += baseyStep;
			lby += baseyStep;
			display();
		}
	}

	if (GetAsyncKeyState(VK_A)) {
		if (lby > -493) {
			lty -= baseyStep;
			lby -= baseyStep;
			display();
		}
	}

	if (GetAsyncKeyState(VK_P)) {
		if (rty < 398) {
			rty += baseyStep;
			rby += baseyStep;
			display();
		}
	}

	if (GetAsyncKeyState(VK_L)) {
		if (rby > -493) {
			rty -= baseyStep;
			rby -= baseyStep;
			display();
		}
	}
}

void display() {
	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0, 0.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);
	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 1.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	pong();
	bolinha();
	glFlush();
}

void tela(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}



