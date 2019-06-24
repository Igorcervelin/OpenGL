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
float tx1 = -140.0;
float tx2 = -140.0;
float tx3 = -140.0;
float tx4 = -140.0;

// Número de passos movidos por Loop de animação da galinha
float xt = 0;
float yt = 0;

// Velocidades
float vel1 = 0.7;
float vel2 = -0.9;
float vel3 = 1.2;
float vel4 = -1.5;

// Área dos carros
float carro1f, carro1b;
float carro2f, carro2b;
float carro3f, carro3b;
float carro4f, carro4b;

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

	if (tx1 >= 1600) {
		tx1 = -140;
	}

	if (tx2 <= -140) {
		tx2 = 1600;
	}

	if (tx3 >= 1600) {
		tx3 = -140;
	}

	if (tx4 <= -140) {
		tx4 = 1600;
	}

	if (yt >= 845) {
		yt = 0;
		xt = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);

}

void touch() {

	if (yt >= 84 && yt <= 202) {
		if (xt <= carro1f && xt >= carro1b + 20) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 264 && yt <= 380) {
		if (xt <= carro2f && xt >= carro2b + 20) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 448 && yt <= 570) {
		if (xt <= carro3f+80 && xt >= carro3b) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 636 && yt <= 756) {
		if (xt <= carro4f+80 && xt >= carro4b) {
			xt = 0;
			yt = 0;
		}
	}
}

void carro() {

	// Faixa 4

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.1, 0.0);
	glVertex2f(-925 + tx1, 244);
	glVertex2f(-825 + tx1, 244);
	glVertex2f(-825 + tx1, 305);
	glVertex2f(-925 + tx1, 305);
	glEnd();

	carro4f = (-825 + tx1);
	carro4b = (-925 + tx1);

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-915 + tx1, 249);
	glVertex2f(-880 + tx1, 249);
	glVertex2f(-880 + tx1, 300);
	glVertex2f(-915 + tx1, 300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-840 + tx1, 249);
	glVertex2f(-855 + tx1, 249);
	glVertex2f(-855 + tx1, 300);
	glVertex2f(-840 + tx1, 300);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-925 + tx1, 244);
	glVertex2f(-825 + tx1, 244);
	glVertex2f(-825 + tx1, 305);
	glVertex2f(-925 + tx1, 305);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-915 + tx1, 249);
	glVertex2f(-880 + tx1, 249);
	glVertex2f(-880 + tx1, 300);
	glVertex2f(-915 + tx1, 300);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-840 + tx1, 249);
	glVertex2f(-855 + tx1, 249);
	glVertex2f(-855 + tx1, 300);
	glVertex2f(-840 + tx1, 300);
	glEnd();

	glPopMatrix();

	// Faixa 3

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.1, 0.0);
	glVertex2f(-925 + tx3, 57);
	glVertex2f(-825 + tx3, 57);
	glVertex2f(-825 + tx3, 123);
	glVertex2f(-925 + tx3, 123);
	glEnd();

	carro3f = (-825 + tx3);
	carro3b = (-925 + tx3);
	//printf("%.1f - %.1f\n", carro3f, carro3b);


	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-915 + tx3, 62);
	glVertex2f(-880 + tx3, 62);
	glVertex2f(-880 + tx3, 118);
	glVertex2f(-915 + tx3, 118);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-840 + tx3, 62);
	glVertex2f(-855 + tx3, 62);
	glVertex2f(-855 + tx3, 118);
	glVertex2f(-840 + tx3, 118);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-925 + tx3, 57);
	glVertex2f(-825 + tx3, 57);
	glVertex2f(-825 + tx3, 123);
	glVertex2f(-925 + tx3, 123);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-915 + tx3, 62);
	glVertex2f(-880 + tx3, 62);
	glVertex2f(-880 + tx3, 118);
	glVertex2f(-915 + tx3, 118);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-840 + tx3, 62);
	glVertex2f(-855 + tx3, 62);
	glVertex2f(-855 + tx3, 118);
	glVertex2f(-840 + tx3, 118);
	glEnd();

	glPopMatrix();

	// Faixa 2

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.1, 0.0);
	glVertex2f(-925 + tx4, -67);
	glVertex2f(-825 + tx4, -67);
	glVertex2f(-825 + tx4, -128);
	glVertex2f(-925 + tx4, -128);
	glEnd();

	carro2f = (-825 + tx4);
	carro2b = (-925 + tx4);

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-875 + tx4, -72);
	glVertex2f(-840 + tx4, -72);
	glVertex2f(-840 + tx4, -123);
	glVertex2f(-875 + tx4, -123);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-915 + tx4, -72);
	glVertex2f(-900 + tx4, -72);
	glVertex2f(-900 + tx4, -123);
	glVertex2f(-915 + tx4, -123);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-925 + tx4, -67);
	glVertex2f(-825 + tx4, -67);
	glVertex2f(-825 + tx4, -128);
	glVertex2f(-925 + tx4, -128);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-875 + tx4, -72);
	glVertex2f(-840 + tx4, -72);
	glVertex2f(-840 + tx4, -123);
	glVertex2f(-875 + tx4, -123);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-915 + tx4, -72);
	glVertex2f(-900 + tx4, -72);
	glVertex2f(-900 + tx4, -123);
	glVertex2f(-915 + tx4, -123);
	glEnd();

	glPopMatrix();

	// Faixa 1

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.1, 0.0);
	glVertex2f(-925 + tx2, -249);
	glVertex2f(-825 + tx2, -249);
	glVertex2f(-825 + tx2, -310);
	glVertex2f(-925 + tx2, -310);
	glEnd();

	carro1f = (-825 + tx2);
	carro1b = (-925 + tx2);

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-875 + tx2, -254);
	glVertex2f(-840 + tx2, -254);
	glVertex2f(-840 + tx2, -305);
	glVertex2f(-875 + tx2, -305);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1.0);
	glVertex2f(-900 + tx2, -254);
	glVertex2f(-915 + tx2, -254);
	glVertex2f(-915 + tx2, -305);
	glVertex2f(-900 + tx2, -305);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-925 + tx2, -249);
	glVertex2f(-825 + tx2, -249);
	glVertex2f(-825 + tx2, -310);
	glVertex2f(-925 + tx2, -310);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-875 + tx2, -254);
	glVertex2f(-840 + tx2, -254);
	glVertex2f(-840 + tx2, -305);
	glVertex2f(-875 + tx2, -305);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-900 + tx2, -254);
	glVertex2f(-915 + tx2, -254);
	glVertex2f(-915 + tx2, -305);
	glVertex2f(-900 + tx2, -305);
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

	// corpo
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-20 + xt, -445 + yt);
	glVertex2f(-20 + xt, -385 + yt);
	glVertex2f(-80 + xt, -385 + yt);
	glVertex2f(-80 + xt, -445 + yt);
	glEnd();

	// contorno corpo
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-20 + xt, -445 + yt);
	glVertex2f(-20 + xt, -385 + yt);
	glVertex2f(-80 + xt, -385 + yt);
	glVertex2f(-80 + xt, -445 + yt);
	glEnd();

	// olho Esquerdo
	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 10.0f, raioY = 3.5f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 63 + xt, sin(ang) * raioY - 410 + yt);
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
		printf("%.1f\n", yt);
		display();
	}

	if (GetAsyncKeyState(VK_A)) {
		if (xt >= -910) {
			xt -= 4;
			printf("%.1f\n", xt);
			display();
		}

	}

	if (GetAsyncKeyState(VK_S)) {
		if (yt >= -20) {
			printf("%.1f\n", yt);
			yt -= 4;
			display();
		}

	}

	if (GetAsyncKeyState(VK_D)) {
		if (xt <= 610) {
			xt += 4;
			printf("%.1f\n", xt);
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

	touch();
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