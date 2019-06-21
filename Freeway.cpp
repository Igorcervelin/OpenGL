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

// Coordenadas variáveis para X e Y
float tx = 0.0;
float ty = 0.0;

// Número de passos movidos por Loop de animação
float xt = 0;
float yt = 0;

// Variável flag para saber a direção do peixe
float p = 0;

// Variável de rotação
float rot = 180.0;

// Define o nível de R, G e B
float r = 1.0;
float g = 0.65;
float b = 0.0;

// Declaração de funções
void anima(int valor);
void galinha();
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

// Função de animação
void anima(int valor) {

}

void update(int valor) {
	keyboard();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay;
}


// Desenha o ambiente
void ambiente() {

	int x = 0;

	// Trilha principal
	for (int i = 0; i <= 19; i++) {
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-925 + x, 45);
		glVertex2f(-1000 + x, 45);
		glVertex2f(-1000 + x, 32);
		glVertex2f(-925 + x, 32);
		glEnd();

		x += 100;
	}

	x = 0;

	// Faixa top
	for (int i = 0; i <= 19; i++) { 
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, 220);
		glVertex2f(-1000 + x, 220);
		glVertex2f(-1000 + x, 227);
		glVertex2f(-925 + x, 227);
		glEnd();

		x += 100;
	}

	x = 0;

	// Faixa bot
	for (int i = 0; i <= 19; i++) { 
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, -220+32);
		glVertex2f(-1000 + x, -220+32);
		glVertex2f(-1000 + x, -227+32);
		glVertex2f(-925 + x, -227+32);
		glEnd();

		x += 100;
	}

	// Calçada top
	glBegin(GL_QUADS);
	glColor3f(0.45, 0.3, 0.2);
	glVertex2f(1000, 400);
	glVertex2f(1000, 600);
	glVertex2f(-1000, 600);
	glVertex2f(-1000, 400);
	glEnd();

	// Calçada bot
	glBegin(GL_QUADS);
	glColor3f(0.45, 0.3, 0.2);
	glVertex2f(1000, -500);
	glVertex2f(1000, -400);
	glVertex2f(-1000, -400);
	glVertex2f(-1000, -500);
	glEnd();

}

// Desenha a galinha
void galinha() {

	//glTranslated(tx, ty, 0);
	//glRotatef(rot, 0.0, 0.0, 1.0);

	if (p == 1) { // Quando o peixe bater no aquário ele muda de direção
		glRotatef(180.0, 0.0, 1.0, 0.0);
	}

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
	glColor3f(r, g, b);
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
		yt += 6;
		display();
	}

	if (GetAsyncKeyState(VK_A)) {
		xt -= 6;
		display();
	}

	if (GetAsyncKeyState(VK_S)) {
		yt -= 6;
		display();
	}

	if (GetAsyncKeyState(VK_D)) {
		xt += 6;
		display();
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
	galinha();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}