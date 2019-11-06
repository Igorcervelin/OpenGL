#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 1000
#define janela_largura 2000

float tx = 0.0; // Variável para armazenar o valor do step, que será somado nas coordenadas para fazer a animação
float xStep = 1.0; // Número de passos movidos por Loop de animação


// Flags de estado 
int parar = 1; // Iniciar parado
int andar = 0;
int correr = 0;

int vel = 0; // Velocidade da animação para diferenciar corrida de caminhada

// Declaração de funções
void anima(int valor);
void boneco();
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);

// Main
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Boneco");
	glutReshapeFunc(tela);
	glutFullScreen();
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(150, anima, 10);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}

// Função de animação
void anima(int valor){

	// Condições de movimentação
	 if(parar == 1){
		tx = 0;
	} else if(andar == 1){
		vel = 10;
	} else if(correr == 1){
		vel = 2;
	}
	
	// Definir limite do loop de animação
	if((tx >= 20) || (tx < -120)){
		xStep = -xStep;
	}
	
	tx += xStep; // Acrescenta o step na variável de medida
		
	glutPostRedisplay();
	glutTimerFunc(vel, anima, 1);
}

// Desenha o boneco
void boneco() {

	// Cabeça
	GLfloat  circ_pnt = 500;
	GLfloat  ang, raioX = 55.0f, raioY = 56.0f;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 81, sin(ang) * raioY + 190);
	}
	glEnd();
	
	glLineWidth(9.0); // grossura da linha
	
	// Pescoço	
	glBegin(GL_LINES);
	glVertex2f(78, 115);
	glVertex2f(78, 160);
	glEnd();
	
	// Corpo	
	glBegin(GL_LINES);
	glVertex2f(78, 115);
	glVertex2f(78, -100);
	glEnd();
	 
	// Perna direita	
	glBegin(GL_LINES);
	glVertex2f(158 + tx, -200);
	glVertex2f(78, -100);
	glEnd();
	
	// Pé direito	
	glBegin(GL_LINES);
	glVertex2f(158 + tx, -200);
	glVertex2f(155 + (tx * 2), -300 - (tx));
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(155 + (tx * 2), -300 - (tx));
	glVertex2f(185 + (tx * 2), -310 - (tx));
	glEnd();
	
	// Perna esquerda	
	glBegin(GL_LINES);
	glVertex2f(78, -100);
	glVertex2f(-8 - tx, -200);
	glEnd();
	
	// Pé esquerdo	
	glBegin(GL_LINES);
	glVertex2f(-8 - tx, -200);
	glVertex2f(-90 - (tx * 1.5), -250 +(tx));
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(-90 - (tx * 1.5), -250 +(tx));
	glVertex2f(-60 - (tx * 1.5), -260 +(tx));
	glEnd();
	
	// Braço esquerdo
	glBegin(GL_LINES);
	glVertex2f(78, 100);
	glVertex2f(-10 - tx, 10);
	glEnd();
	
	// Mão esquerda
	glBegin(GL_LINES);
	glVertex2f(-10 - tx, 10);
	glVertex2f(40 - tx, -50 - tx);
	glEnd();
	
	// Braço direito
	glBegin(GL_LINES);
	glVertex2f(78, 100);
	glVertex2f(160 + tx, 0);
	glEnd();
	
	// Mão direita
	glBegin(GL_LINES);
	glVertex2f(160 + tx, 0);
	glVertex2f(225 + tx, -20 + (tx * 0.1));
	glEnd();
}

// Função para utilizar o teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'w':
		parar = 0;
		andar = 1;
		correr = 0;
		break;

	case 's':
		parar = 1;
		andar = 0;
		correr = 0;
		break;

	case 'r':
		parar = 0;
		andar = 0;
		correr = 1;
		break;

	}
}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0, 0, 0, 0); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	boneco();
	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
