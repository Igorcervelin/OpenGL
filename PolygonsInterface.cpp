#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#define PI 3.14159265359
#define MENU_FILE_NEW 1
#define MENU_FILE_EXIT 2
#define BUTTON_TRIANGLE 3
#define BUTTON_RECTANGLE 4
#define BUTTON_CIRCLE 5
#define BUTTON_CIMA 6
#define BUTTON_BAIXO 7
#define BUTTON_DIREITA 8
#define BUTTON_ESQUERDA 9
#define BUTTON_AUMENTA 10
#define BUTTON_DIMINUI 11
#define BUTTON_HORARIO 12
#define BUTTON_ANTIHORARIO 13
#define BUTTON_CLEAR 14
#define BUTTON_AZUL 15
#define BUTTON_AMARELO 16
#define BUTTON_VERMELHO 17
#define BUTTON_VERDE 18


// Botões
HWND bTriangle;
HWND bRectangle;
HWND bCircle;
HWND bCima;
HWND bBaixo;
HWND bDireita;
HWND bEsquerda;
HWND bAumenta;
HWND bDiminui;
HWND bHorario;
HWND bAntihorario;
HWND bClear;

// Declaração das funções
void addElements(HWND hWnd);
void addMenu(HWND hWnd);
void DrawWorld();
void DrawTriangle();
void DrawRectangle();
void DrawCircle();

// Variáveis globais
float raioCirculo = 0.5;
float mov = 0;
float sizeup = 0;
float sizedown = 0;
float flag = 0;
float ang = 0;
float altura = 0;
float base = 0;
float lado1 = 0;
float lado2 = 0;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){

	// Window Class
	WNDCLASS wc = {};
	wc.lpszClassName = "Computacao Grafica - Avalicao A1/02";
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcedure;
	wc.hInstance = hInst;
	RegisterClass(&wc);
  
  
  // Window
	HWND hWnd;
	hWnd = CreateWindow(
    	wc.lpszClassName,
    	"Computacao Grafica - Avalicao A1/02",
    	WS_OVERLAPPEDWINDOW | WS_VISIBLE,
    	0, 0, 800, 600,
    	NULL, NULL, NULL, NULL
  	);
  
  // manipulador Device Context
	HDC hDC;
	hDC = GetDC(hWnd);
  
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | 0;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
  
  // Pixel Format
	int pf;
	pf = ChoosePixelFormat(hDC, &pfd);
	if (pf==0){
		MessageBox(NULL, "ChoosePixelFormat() Failed", "Error", MB_OK);
	}
	if(SetPixelFormat(hDC, pf, &pfd) == FALSE){
		MessageBox(NULL, "SetPixelFormat() Failed", "Error", MB_OK);
	}
	DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
  
	// OpenGL Context
	HGLRC hRC;
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
  
	ShowWindow(hWnd, ncmdshow);
  
	MSG msg = {};
  
	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
  
	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
  
	PAINTSTRUCT ps;
  
	switch (msg){
			
		case WM_PAINT:
			addElements(hWnd);
			DrawWorld();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		
		case WM_SIZE:
			glViewport(0, 0, LOWORD(lp), HIWORD(lp));
			PostMessage(hWnd, WM_PAINT, 0, 0);
			break;
			
		case WM_COMMAND:
			switch(wp)
			{
				case BUTTON_TRIANGLE:
					flag = 1;
					DrawTriangle();
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;

				case BUTTON_RECTANGLE:
					flag = 2;
					DrawRectangle();
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_CIRCLE:
					flag = 3;
					DrawCircle();
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_DIREITA:
					glTranslatef(0.1, 0, 0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_ESQUERDA:
					glTranslatef(-0.1, 0, 0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_CIMA:
					glTranslatef(0.0, 0.1, 0.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
				
				case BUTTON_BAIXO:
					glTranslatef(0.0, -0.1, 0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_AUMENTA:
					sizeup += 0.03;
					sizedown -= 0.03;
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_DIMINUI:
					sizeup -= 0.03;
					sizedown += 0.03;
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_HORARIO:
					glRotatef(3.0, 0.0, 0.0, 1.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_ANTIHORARIO:
					glRotatef(-3.0, 0.0, 0.0, 1.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_AMARELO:
					glColor3f(1.0, 1.0, 0.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_AZUL:
					glColor3f(0.0, 0.0, 1.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_VERMELHO:
					glColor3f(1.0, 0.0, 0.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_VERDE:
					glColor3f(0.0, 1.0, 0.0);
					if(flag == 1){
						DrawTriangle();
					}else if(flag == 2){
						DrawRectangle();
					}else if(flag == 3){
						DrawCircle();
					}
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
				case BUTTON_CLEAR:
					glClear(GL_COLOR_BUFFER_BIT);
					PostMessage(hWnd, WM_PAINT, 0, 0);
					break;
					
			}
			break;

	    case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, msg, wp, lp);
}

void addElements(HWND hWnd){
	
	CreateWindow(
	"Static",
	"Base",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/15,/*eixo y*/ 25,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
    CreateWindow(
	"Static",
	"Altura",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/80,/*eixo y*/ 25,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);

	CreateWindow(
	"Edit",
	"",
	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
	/*eixo x*/15,/*eixo y*/ 50,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	CreateWindow(
	"Edit",
	"",
	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
	/*eixo x*/80,/*eixo y*/ 50,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	bTriangle = CreateWindow(
	"Button",
	"Adicionar Triangulo",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/15,/*eixo y*/ 80,/*tamanho pixel*/ 200, 30,
	hWnd,
	(HMENU)BUTTON_TRIANGLE, NULL, NULL
	);
	
	CreateWindow(
	"Static",
	"Largura",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/15,/*eixo y*/ 140,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	CreateWindow(
	"Static",
	"Altura",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/80,/*eixo y*/ 140,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	CreateWindow(
	"Edit",
	"",
	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
	/*eixo x*/15,/*eixo y*/ 165,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	CreateWindow(
	"Edit",
	"",
	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
	/*eixo x*/80,/*eixo y*/ 165,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	bRectangle = CreateWindow(
	"Button",
	"Adicionar Retangulo",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/15,/*eixo y*/ 205,/*tamanho pixel*/ 200, 30,
	hWnd,
	(HMENU)BUTTON_RECTANGLE, NULL, NULL
	);
	
	CreateWindow(
	"Static",
	"Raio",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/15,/*eixo y*/ 265,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	CreateWindow(
	"Edit",
	"",
	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
	/*eixo x*/15,/*eixo y*/ 290,/*tamanho pixel*/ 45, 20,
	hWnd,
	NULL, NULL, NULL
	);
	
	bCircle = CreateWindow(
	"Button",
	"Adicionar Circulo",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/15,/*eixo y*/ 320,/*tamanho pixel*/ 200, 30,
	hWnd,
	(HMENU)BUTTON_CIRCLE, NULL, NULL
	);
	
	bCima = CreateWindow(
	"Button",
	"^",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/70,/*eixo y*/ 360,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_CIMA, NULL, NULL
	);
	
	bBaixo = CreateWindow(
	"Button",
	"v",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/70,/*eixo y*/ 390,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_BAIXO, NULL, NULL
	);
	
	bDireita = CreateWindow(
	"Button",
	">",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/120,/*eixo y*/ 390,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_DIREITA, NULL, NULL
	);
	
	bEsquerda = CreateWindow(
	"Button",
	"<",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/20,/*eixo y*/ 390,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_ESQUERDA, NULL, NULL
	);
	
	bAumenta = CreateWindow(
	"Button",
	"+",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/20,/*eixo y*/ 430,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_AUMENTA, NULL, NULL
	);
	
	bDiminui = CreateWindow(
	"Button",
	"-",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/80,/*eixo y*/ 430,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_DIMINUI, NULL, NULL
	);
	
	bHorario = CreateWindow(
	"Button",
	"Girar >",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/20,/*eixo y*/ 470,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_HORARIO, NULL, NULL
	);
	
	bAntihorario = CreateWindow(
	"Button",
	"< Girar",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/80,/*eixo y*/ 470,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_ANTIHORARIO, NULL, NULL
	);
	
	CreateWindow(
	"Button",
	"Amarelo",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/15,/*eixo y*/ 510,/*tamanho pixel*/ 60, 30,
	hWnd,
	(HMENU)BUTTON_AMARELO, NULL, NULL
	);
	
	CreateWindow(
	"Button",
	"Azul",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/75,/*eixo y*/ 510,/*tamanho pixel*/ 50, 30,
	hWnd,
	(HMENU)BUTTON_AZUL, NULL, NULL
	);
	
	CreateWindow(
	"Button",
	"Vermelho",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/125,/*eixo y*/ 510,/*tamanho pixel*/ 70, 30,
	hWnd,
	(HMENU)BUTTON_VERMELHO, NULL, NULL
	);
	
	CreateWindow(
	"Button",
	"Verde",
	WS_VISIBLE | WS_CHILD,
	/*eixo x*/195,/*eixo y*/ 510,/*tamanho pixel*/ 60, 30,
	hWnd,
	(HMENU)BUTTON_VERDE, NULL, NULL
	);
	
	bClear = CreateWindow(
	"Button",
	"Limpar tela",
	WS_VISIBLE | WS_CHILD | SS_CENTER, 
	/*eixo x*/265,/*eixo y*/ 25,/*tamanho pixel*/ 95, 25,
	hWnd,
	(HMENU)BUTTON_CLEAR, NULL, NULL
	);

}

void DrawWorld(){
	glViewport(300,0,400,500);
	
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 0);
	
	glEnd();
	glFlush();
}

void DrawRectangle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(300,0,400,500);
	
	glBegin(GL_QUADS);
	glVertex2f(0 + sizedown, 0.3 + sizeup);
	glVertex2f(0.6 + sizeup, 0.3 + sizeup);
	glVertex2f(0.6 + sizeup, -0.3 + sizedown);
	glVertex2f(0 + sizedown, -0.3 + sizedown);
	
	glEnd();
	glFlush();
}

void DrawTriangle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(300,0,400,500);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0.5 + sizeup);
	glVertex2f(0.5 + sizeup, -0.5 + sizedown);
	glVertex2f(-0.5 + sizedown, -0.5 + sizedown);
	
	glEnd();
	glFlush();
}

void DrawCircle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(300,0,400,500);

	GLint vertices = 100;
	GLfloat angulo;
	glBegin(GL_POLYGON);
	for(int i=0; i<vertices; i++){
		angulo = 2*PI*i/vertices;
		glVertex2f(cos(angulo) * (sizeup+0.5), sin(angulo) * (sizeup+0.5));
	}
	glEnd();
	glFlush();
}
