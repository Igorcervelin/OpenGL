#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 1500

// Declaração de funções
void watermelon();
void display(void);
void tela(GLsizei w, GLsizei h);

// Main
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Watermelon");
	glutReshapeFunc(tela);
	glutFullScreen();
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}


// Desenha o ambiente
void watermelon() {

	// Casca
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 535.0f, raioY = 434.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY - 130);
	}
	glEnd();

	// Polpa
	circ_pnt = 500;
	ang, raioX = 500.0f, raioY = 400.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(0.9, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY - 130);
	}
	glEnd();

	// Sementes
	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 55, sin(ang) * raioY - 50);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 320, sin(ang) * raioY - 90);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 350, sin(ang) * raioY - 130);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 300, sin(ang) * raioY - 20);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 200, sin(ang) * raioY - 70);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 190, sin(ang) * raioY - 85);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 110, sin(ang) * raioY - 10);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 180, sin(ang) * raioY + 40);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 30, sin(ang) * raioY - 130);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 350, sin(ang) * raioY + 140);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 10, sin(ang) * raioY - 95);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 55, sin(ang) * raioY - 1);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 55, sin(ang) * raioY - 125);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 195, sin(ang) * raioY - 10);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 125, sin(ang) * raioY - 100);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 125, sin(ang) * raioY - 50);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 95, sin(ang) * raioY - 230);
	}

	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 255, sin(ang) * raioY - 50);
	}

	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 115, sin(ang) * raioY - 50);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 255, sin(ang) * raioY - 110);
	}
	glEnd();

	circ_pnt = 500;
	ang, raioX = 5.0f, raioY = 10.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 155, sin(ang) * raioY - 150);
	}
	glEnd();

}


void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0.35f, 0.35f, 1.0f, 1.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	watermelon();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}