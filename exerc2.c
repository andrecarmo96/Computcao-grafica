//Andre Luis Burei do Carmo, andre_carmo_19@hotmail.com
#include <GL/glut.h>
#include <GL/gl.h>

float angulo = 0.0f;

void casa() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(-90, -90);
	glVertex2i(-90, 60);
	glVertex2i(110, 60);
	glVertex2i(110, -90);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(-90, 60);
	glVertex2i(10, 150);
	glVertex2i(110, 60);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(-30, -90);
	glVertex2i(-30, 30);
	glVertex2i(30, 30);
	glVertex2i(30, -90);

	glVertex2i(35, -30);
	glVertex2i(35, 30);
	glVertex2i(105, 30);
	glVertex2i(105, -30);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(68, -30);
	glVertex2i(68, 30);
	glVertex2i(72, 30);
	glVertex2i(72, -30);

	glVertex2i(35, -2);
	glVertex2i(35, 02);
	glVertex2i(105, 02);
	glVertex2i(105, -2);

	glEnd();
}

//Callback do desenho
void desenha()
{
	//Define a cor de fundo da Janela
	glClearColor(0, 0, 0, 0);

	//Limpa a Tela
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	//Volta ao padrão
	glLoadIdentity();

	glPushMatrix(); 
	
	glRotatef(angulo, 0, 0, 1); 

	casa();


	glPopMatrix(); 
	glutSwapBuffers();
};


void tamanho_tela(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); 

								 
	gluPerspective(0, (double)w / (double)h, 1.0, 200.0);                
}


void teclado(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		//ESC
		exit(0);
	}
}
void funcao_especial(int key, int x, int y){
	if (key == GLUT_KEY_LEFT) {
		angulo += 2.0f;
		if (angulo > 360) {
			angulo = -360;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		angulo -= 2.0f;
		if (angulo < -360){
			angulo = 360;
		}
	}
}

void glutTimer(int value){
	glutPostRedisplay();
	glutTimerFunc(75, glutTimer, 1);
}


void inicializa(){

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-200, 200, -200, 200);
	glMatrixMode(GL_MODELVIEW);
	glutTimerFunc(75, glutTimer, 1);
}

int main()
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutInitWindowSize(500, 500);


	glutInitWindowPosition(0, 0);

	glutCreateWindow("Traballho Casa");


	glutDisplayFunc(desenha);

	glutKeyboardFunc(teclado);


	glutReshapeFunc(tamanho_tela);


	glutSpecialFunc(funcao_especial);

	inicializa();
	glutMainLoop();
	return 0;
}
