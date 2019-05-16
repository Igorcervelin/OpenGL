#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 1000

void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(janela_altura, janela_largura);
	glutCreateWindow("Coelho");
	glutReshapeFunc(tela);
	//glutFullScreen();
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:

	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);


	// ************** INÍCIO DA ARTE **********************

	//céu
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.6, 0.0);
	glVertex2f(500, -250);
	glVertex2f(-500, -250);
	glVertex2f(-500, 500);
	glColor3f(0.9, 0.9, 0.0);
	glVertex2f(500, 500);
	glEnd();

	//Grama
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.5, 0.1);
	glVertex2f(-500, -500);
	glVertex2f(500, -500);
	glColor3f(0.3, 1.0, 0.3);
	glVertex2f(500, -250);
	glVertex2f(-500, -250);
	glEnd();

	//Mandibula
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex2f(-71, 3);
	glVertex2f(68, 0);
	glVertex2f(10, -60);
	glVertex2f(-30, -60);
	glEnd();

	//Mandibula CONTORNO
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-71, 3);
	glVertex2f(70.3, 2.0);
	glVertex2f(10, -60);
	glVertex2f(-30, -60);
	glVertex2f(-69, 2);
	glEnd();

	//Cabeça
	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 70.0f, raioY = 120.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	//Cabeça CONTORNO
	circ_pnt = 500;
	ang, raioX = 70.0f, raioY = 120.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	// olho Esquerdo
	ang, raioX = 20.0f, raioY = 7.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY + 40);
	}
	glEnd();

	// olho Esquerdo CONTORNO
	ang, raioX = 20.0f, raioY = 7.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY + 40);
	}
	glEnd();

	// Iris Esquerda
	ang, raioX = 10.0f, raioY = 6.5f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 35, sin(ang) * raioY + 40);
	}
	glEnd();

	// Pupila Esquerda
	ang, raioX = 3.0f, raioY = 3.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 41, sin(ang) * raioY + 43);
	}
	glEnd();

	// olho Direito
	ang, raioX = 22.0f, raioY = 7.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 20, sin(ang) * raioY + 40);
	}
	glEnd();

	// olho Direito CONTORNO
	ang, raioX = 22.0f, raioY = 7.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 20, sin(ang) * raioY + 40);
	}
	glEnd();

	// Iris Direita
	ang, raioX = 10.0f, raioY = 6.5f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 25, sin(ang) * raioY + 40);
	}
	glEnd();

	// Pupila direita
	ang, raioX = 3.0f, raioY = 3.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 19, sin(ang) * raioY + 43);
	}
	glEnd();


	// Orelha Esquerda
	ang, raioX = 17.0f, raioY = 65.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 30, sin(ang) * raioY + 130);
	}
	glEnd();

	ang, raioX = 10.0f, raioY = 65.0f;
	glColor3f(1.0, 0.8, 0.8);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 30, sin(ang) * raioY + 115);
	}
	glEnd();

	// Orelha Direita
	ang, raioX = 17.0f, raioY = 65.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY + 130);
	}
	glEnd();

	ang, raioX = 10.0f, raioY = 65.0f;
	glColor3f(1.0, 0.8, 0.8);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY + 115);
	}
	glEnd();

	// Orelha Esquerda CONTORNO
	ang, raioX = 17.0f, raioY = 65.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt / 1.59); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY + 130);
	}
	glEnd();

	// Orelha Direita CONTORNO
	ang, raioX = 17.0f, raioY = 65.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt / 1.9); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 30, sin(ang) * raioY + 130);
	}
	glEnd();

	// Boca
	ang, raioX = 32.0f, raioY = 5.7f;
	glColor3f(0.9, 0.80, 0.9);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 12, sin(ang) * raioY - 20);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-39, -20);
	glVertex2f(15, -20);
	glEnd();

	// Nariz
	glBegin(GL_TRIANGLES);
	glColor3f(0.55, 0.55, 0.55);
	glVertex2f(-20, 10);
	glVertex2f(-15, 0);
	glVertex2f(-10, 10);
	glEnd();

	// BIGODE
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.00);
	glVertex2f(-80, 15);
	glVertex2f(-25, 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.00);
	glVertex2f(-80, 5);
	glVertex2f(-25, 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.00);
	glVertex2f(-80, -5);
	glVertex2f(-25, 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(80, 15);
	glVertex2f(5, 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.00);
	glVertex2f(80, 5);
	glVertex2f(5, 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.00);
	glVertex2f(80, -5);
	glVertex2f(5, 5);
	glEnd();

	// Corpo
	ang, raioX = 85.0f, raioY = 140.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 10, sin(ang) * raioY - 208);
	}
	glEnd();

	// Corpo contorno
	ang, raioX = 85.0f, raioY = 140.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 10, sin(ang) * raioY - 208);
	}
	glEnd();

	// Barriga
	ang, raioX = 60.0f, raioY = 105.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 10, sin(ang) * raioY - 208);
	}
	glEnd();

	//pescoço
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.4);
	glVertex2f(-30, -61);
	glVertex2f(10, -61);
	glVertex2f(15, -75);
	glVertex2f(-35, -75);
	glEnd();

	//pescoço contorno
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-30, -61);
	glVertex2f(10, -61);
	glVertex2f(15, -75);
	glVertex2f(-35, -75);
	glEnd();

	//Braço esquerdo
	ang, raioX = 20.0f, raioY = 40.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 75, sin(ang) * raioY - 140);
	}
	glEnd();

	//Braço esquerdo CONTORNO
	ang, raioX = 20.0f, raioY = 40.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 75, sin(ang) * raioY - 140);
	}
	glEnd();

	//Braço direito
	ang, raioX = 20.0f, raioY = 40.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 65, sin(ang) * raioY - 140);
	}
	glEnd();

	//Braço direito CONTORNO
	ang, raioX = 20.0f, raioY = 40.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 65, sin(ang) * raioY - 140);
	}
	glEnd();

	// Pé direito
	ang, raioX = 50.0f, raioY = 25.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 80, sin(ang) * raioY - 330);
	}
	glEnd();

	// Pé direito contorno
	ang, raioX = 50.0f, raioY = 25.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 80, sin(ang) * raioY - 330);
	}
	glEnd();

	// Pé esquerdo
	ang, raioX = 50.0f, raioY = 25.0f;
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 100, sin(ang) * raioY - 330);
	}
	glEnd();

	// Pé esquerdo contorno
	ang, raioX = 50.0f, raioY = 25.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 100, sin(ang) * raioY - 330);
	}
	glEnd();

	//OVO 1
	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0.0, 0.0);
	glVertex2f(-350, -210);
	glColor3f(0.6, 0.0, 0.0);
	glVertex2f(-300, -290);
	glColor3f(0.6, 0.0, 0.0);
	glVertex2f(-250, -210);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-350, -210);
	glColor3f(0.0, 0.3, 0.3);
	glVertex2f(-300, -290);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-250, -210);
	glEnd();

	ang, raioX = 40.0f, raioY = 65.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(0.6, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 300, sin(ang) * raioY - 330);
	}
	glEnd();

	ang, raioX = 40.0f, raioY = 65.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 300, sin(ang) * raioY - 330);
	}
	glEnd();

	//OVO 2
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(350, -210);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(300, -290);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(250, -210);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(350, -210);
	glColor3f(0.0, 0.3, 0.3);
	glVertex2f(300, -290);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(250, -210);
	glEnd();

	ang, raioX = 40.0f, raioY = 65.0f;
	glColor3f(0.0, 0.0, 0.6);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 300, sin(ang) * raioY - 330);
	}
	glEnd();

	ang, raioX = 40.0f, raioY = 65.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 300, sin(ang) * raioY - 330);
	}
	glEnd();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}