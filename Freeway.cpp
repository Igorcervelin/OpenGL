#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 2000

// Coordenadas variáveis para movimentação dos carros
float tx1 = 0.0;
float tx2 = 0.0;
float tx3 = 0.0;
float tx4 = 0.0;

// Número de passos movidos por Loop de animação da galinha
float xt = 0;
float yt = 0;

// Velocidades
float vel1 = 0.7;
float vel2 = 0.9;
float vel3 = 1.2;
float vel4 = 1.5;

// Declaração de funções
void anima(int valor);
void update(int valor); int interval = 1000 / 60;
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard();

// Main
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Freeway");
	glutReshapeFunc(tela);
	glutFullScreen();
	glutTimerFunc(150, anima, 10);
	glutTimerFunc(50, update, 1);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}

void update(int valor) {
	keyboard();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay;
}


// Função de animação
void anima(int valor) {

	tx1 += vel1;
	tx2 += vel2;
	tx3 += vel3;
	tx4 += vel4;

		
	if(tx1 >= 1600){
		tx1= -140;
	}

	if (tx2 >= 1600) {
		tx2 = -140;
	}

	if (tx3 >= 1600) {
		tx3 = -140;
	}

	if (tx4 >= 1600) {
		tx4 = -140;
	}

	if (yt >= 845) {
		yt = 0;
		xt = 0;
	}
	
	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);

}

void carro() {

	// Faixa 1

	glPushMatrix();
	glTranslated(tx4, 0, 0);

		glBegin(GL_QUADS);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, 57);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-825, 57);
		glVertex2f(-825, 123);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, 123);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.6, 0.6, 1.0);
		glVertex2f(-875, 62);
		glVertex2f(-840, 62);
		glVertex2f(-840, 118);
		glVertex2f(-875, 118);
		glEnd();

	glPopMatrix();

	// Faixa 2

	glPushMatrix();
	glTranslated(tx2, 0, 0);

		glBegin(GL_QUADS);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, 244);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-825, 244);
		glVertex2f(-825, 305);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, 305);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.6, 0.6, 1.0);
		glVertex2f(-875, 249);
		glVertex2f(-840, 249);
		glVertex2f(-840, 300);
		glVertex2f(-875, 300);
		glEnd();

	glPopMatrix();

	// Faixa 3

	glPushMatrix();
	glTranslated(tx3, 0, 0);

		glBegin(GL_QUADS);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, -67);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-825, -67);
		glVertex2f(-825, -128);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, -128);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.6, 0.6, 1.0);
		glVertex2f(-875, -72);
		glVertex2f(-840, -72);
		glVertex2f(-840, -123);
		glVertex2f(-875, -123);
		glEnd();

	glPopMatrix();

	// Faixa 4

	glPushMatrix();
	glTranslated(tx1, 0, 0);

		glBegin(GL_QUADS);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, -249);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-825, -249);
		glVertex2f(-825, -310);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(-925, -310);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.6, 0.6, 1.0);
		glVertex2f(-875, -254);
		glVertex2f(-840, -254);
		glVertex2f(-840, -305);
		glVertex2f(-875, -305);
		glEnd();

	glPopMatrix();
}



// Desenha o ambiente
void ambiente() {

	int x = 0;

	// Trilha principal
	for (int i = 0; i <= 19; i++) {
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-925 + x, 5);
		glVertex2f(-1000 + x, 5);
		glVertex2f(-1000 + x, -10);
		glVertex2f(-925 + x, -10);
		glEnd();

		x += 100;
	}

	x = 0;

	// Faixa top
	for (int i = 0; i <= 19; i++) { 
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, 180);
		glVertex2f(-1000 + x, 180);
		glVertex2f(-1000 + x, 187);
		glVertex2f(-925 + x, 187);
		glEnd();

		x += 100;
	}

	x = 0;

	// Faixa bot
	for (int i = 0; i <= 19; i++) { 
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, -185);
		glVertex2f(-1000 + x, -185);
		glVertex2f(-1000 + x, -192);
		glVertex2f(-925 + x, -192);
		glEnd();

		x += 100;
	}

	// Calçada top
	glBegin(GL_QUADS);
	glColor3f(0.45, 0.3, 0.2);
	glVertex2f(1000, 362);
	glVertex2f(1000, 450);
	glVertex2f(-1000, 450);
	glVertex2f(-1000, 362);
	glEnd();

	// Calçada bot
	glBegin(GL_QUADS);
	glColor3f(0.45, 0.3, 0.2);
	glVertex2f(1000, -500);
	glVertex2f(1000, -367);
	glVertex2f(-1000, -367);
	glVertex2f(-1000, -500);
	glEnd();

}

// Desenha a galinha
void galinha() {

	// Corpo
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 27.0f, raioY = 35.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 50 + xt, sin(ang) * raioY - 420 + yt);
	}
	glEnd();

	// Corpo contorno
	circ_pnt = 500;
	ang, raioX = 27.0f, raioY = 35.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX -50 + xt, sin(ang) * raioY - 420 + yt);
	}
	glEnd();

	// olho Esquerdo
	ang, raioX = 10.0f, raioY = 3.5f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 63 + xt, sin(ang) * raioY -410 + yt);
	}
	glEnd();

	// olho Esquerdo CONTORNO
	ang, raioX = 10.0f, raioY = 3.5f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 63 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// Iris Esquerda
	ang, raioX = 5.0f, raioY = 3.25f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 62 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// Pupila Esquerda
	ang, raioX = 1.5f, raioY = 1.5f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 65 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// olho Direito
	ang, raioX = 11.0f, raioY = 3.5f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// olho Direito CONTORNO
	ang, raioX = 11.0f, raioY = 3.5f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// Iris Direita
	ang, raioX = 5.0f, raioY = 3.25f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// Pupila direita
	ang, raioX = 1.5f, raioY = 1.5f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 43 + xt, sin(ang) * raioY - 410 + yt);
	}
	glEnd();

	// Bico
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.65, 0.0);
	glVertex2f(-55 + xt, -440 + yt);
	glVertex2f(-75 + xt, -430 + yt);
	glVertex2f(-55 + xt, -420 + yt);
	glEnd();

	// Bico contorno
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-55 + xt, -440 + yt);
	glVertex2f(-75 + xt, -430 + yt);
	glVertex2f(-55 + xt, -420 + yt);
	glVertex2f(-55 + xt, -440 + yt);
	glEnd();

	// Crista 1
	ang, raioX = 12.0f, raioY = 15.0f;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 43 + xt, sin(ang) * raioY - 375 + yt);
	}
	glEnd();

	// Crista 1 contorno
	ang, raioX = 12.0f, raioY = 15.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 43 + xt, sin(ang) * raioY - 375 + yt);
	}
	glEnd();

	// Crista 2
	ang, raioX = 10.0f, raioY = 18.0f;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 55 + xt, sin(ang) * raioY - 370 + yt);
	}
	glEnd();

	// Crista 2 contorno
	ang, raioX = 10.0f, raioY = 18.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 55 + xt, sin(ang) * raioY - 370 + yt);
	}
	glEnd();

}

// Função para utilizar o teclado
void keyboard() {
	
	if (GetAsyncKeyState(VK_W)) {
		yt += 4;
		display();
	}

	if (GetAsyncKeyState(VK_A)) {
		if(xt >= -910) {
			xt -= 4;
			display();
		}

	}

	if (GetAsyncKeyState(VK_S)) {
		if (yt >= -20) {
			yt -= 4;
			display();
		}

	}

	if (GetAsyncKeyState(VK_D)) {
		if (xt <= 610) {
			xt += 4;
			display();
		}

	}		

}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0.75f, 0.75f, 0.75f, 1.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	ambiente();
	carro();
	galinha();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}