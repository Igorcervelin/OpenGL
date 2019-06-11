#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define windowH 900
#define windowW 1600
#define PI 3.141592

struct Vertices {
	int x;
	int y;
};

GLfloat circ_pnt = 200;
GLfloat ang, circle;

struct Vertices v1;
struct Vertices v2 = { v2.x = 50, v2.y = 150 };

// Color
float c1 = 0.9;
float c2 = 0.5;
float c3 = 0.0;

float valora;
float valorb;
float valorc;

bool touch = false;

void display(void);
void screen(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);
void mouseMovement(int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Circle Events");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutReshapeFunc(screen);
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutPassiveMotionFunc(mouseMovement);
	glutMainLoop();

	return(0);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 27) {
		glutDestroyWindow(0);
		exit(0);
	}

}

void mouseMovement(int x, int y) {
	v1.x = x - (windowW / 2);
	v1.y = y - (windowH / 2);

	float a = v1.x - v2.x;
	float b = v1.y - v2.y;
	float c = sqrt((a*a) + (b * b));

	if (c < (circle * 2)) {
		touch = true;
	}
	else {
		touch = false;
	}
}

void draw() {
	glLoadIdentity();

	glPushMatrix();
	glTranslatef((windowW) / 2, (windowH) / 2, 0);
	glScalef(1, -1, 1);
	glPushMatrix();
	glTranslatef(v2.x, v2.y, 0);

	// Circulo estático
	glBegin(GL_POLYGON);
	glColor3f(c1, c2, c3);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * circle, sin(ang) * circle);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(v1.x, v1.y, 0);
	circle = 50;

	// Círculo dinâmico
	glBegin(GL_POLYGON);
	glColor3f(c3, c2, c1);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * circle, sin(ang) * circle);
	}
	glEnd();
	glPopMatrix();

	if (touch == true) {
		c1 = 1.0;
		c2 = 1.0;
		c3 = 0.0;
	} else {
		c1 = 0.9;
		c2 = 0.5;
		c3 = 0.1;
	}

	glutPostRedisplay();
	glPopMatrix();
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, windowW, windowH);
	draw();

	glutSwapBuffers();
}

void screen(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, windowW, 0, windowH);
	glMatrixMode(GL_MODELVIEW);

}