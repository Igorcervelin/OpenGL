#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 1500

// Coordenadas variáveis para X e Y
float tx = 0.0;
float ty = 0.0;

// Número de passos movidos por Loop de animação
float xStep = 4;
float yStep = 4;

// Variável flag para saber a direção do peixe
float x = 0;

// Variável de rotação
float rot = 180.0;

// Define o nível de R, G e B
float r = 1.0;
float g = 0.65;
float b = 0.0;

// Declaração de funções
void anima(int valor);
void peixe();
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);

// Main
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Peixe");
	glutReshapeFunc(tela);
	glutFullScreen();
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(150, anima, 10);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}

// Função de animação
void anima(int valor) {

	if ((tx) > (300)) {
		xStep = -xStep;
		x = 1;
	}

	if ((tx) < (-270)) {
		xStep = -xStep;
		x = 0;
	}

	if ((ty) > (10) || (ty) < (-30)) {
		yStep = -yStep;
	}

	ty += yStep;
	tx += xStep;

	glutPostRedisplay();
	glutTimerFunc(95, anima, 1);
}


// Desenha o ambiente
void ambiente() {

	// Aquario
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 535.0f, raioY = 434.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY - 130);
	}
	glEnd();

	// Água
	circ_pnt = 500;
	ang, raioX = 500.0f, raioY = 400.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(0.25, 0.77, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY - 130);
	}
	glEnd();
}

// Desenha o peixe
void peixe() {

	glTranslated(tx, ty, 0);
	glRotatef(rot, 0.0, 0.0, 1.0);

	if (x == 1) { // Quando o peixe bater no aquário ele muda de direção
		glRotatef(180.0, 0.0, 1.0, 0.0);
	}

	// Barbatana
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(50, 61);
	glVertex2f(40, 1);
	glVertex2f(50, -61);
	glVertex2f(0, 1);
	glEnd();

	// Rabo
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glVertex2f(120, 60);
	glVertex2f(90, 0);
	glVertex2f(120, -60);
	glVertex2f(30, 0);
	glEnd();

	// Corpo
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 65.0f, raioY = 35.0f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 30, sin(ang) * raioY + 7);
	}
	glEnd();

	// olho Esquerdo
	ang, raioX = 10.0f, raioY = 3.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 18, sin(ang) * raioY + 18);
	}
	glEnd();

	// olho Esquerdo CONTORNO
	ang, raioX = 10.0f, raioY = 3.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 18, sin(ang) * raioY + 18);
	}
	glEnd();

	// Iris Esquerda
	ang, raioX = 5.0f, raioY = 3.25f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 15.5, sin(ang) * raioY + 18);
	}
	glEnd();

	// Pupila Esquerda
	ang, raioX = 1.5f, raioY = 1.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 18.5, sin(ang) * raioY + 19.5);
	}
	glEnd();

	// olho Direito
	ang, raioX = 11.0f, raioY = 3.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 8, sin(ang) * raioY + 18);
	}
	glEnd();

	// olho Direito CONTORNO
	ang, raioX = 11.0f, raioY = 3.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 8, sin(ang) * raioY + 18);
	}
	glEnd();

	// Iris Direita
	ang, raioX = 5.0f, raioY = 3.25f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 10.5, sin(ang) * raioY + 18);
	}
	glEnd();

	// Pupila direita
	ang, raioX = 1.5f, raioY = 1.5f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 7.5, sin(ang) * raioY + 19.5);
	}
	glEnd();

	// Boca
	ang, raioX = 16.0f, raioY = 2.85f;
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.9, 0.80, 0.9);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 6, sin(ang) * raioY - 5);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-19.5, -5);
	glVertex2f(7.5, -5);
	glEnd();
}

// Função para utilizar o teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'q':
		r = 1.0;
		g = 1.0;
		b = 1.0;
		break;

	case 'w':
		r = 0.0;
		g = 0.0;
		b = 0.0;
		break;

	case 'e':
		r = 0.8;
		g = 0.0;
		b = 0.6;
		break;

	case 'r':
		r = 1.0;
		g = 0.65;
		b = 0.0;
		break;

	case 't':
		for (int i = 0; i < 36; i++) {
			if (i < 18) {
				ty -= 29;
			}
			else {
				ty += 29;
			}
			rot -= 10;
			Sleep(45);
			display();
		}
	}
}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0.35f, 1.0f, 0.35f, 1.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	ambiente();
	peixe();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
