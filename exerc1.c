//Andre Luis Burei do Carmo, andre_carmo_19@hotmail.com

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

float X = 0.0f;
float Y = 0.0f;

float ax = 0;
float ay = 5;
float bx = -5;
float by = -5;
float cx = 5;
float cy = -5;

 void desenha() {
	glClearColor(0, 0, 0, 0);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3ub(255, 255, 255);
	
	glTranslatef(X, Y, 0);
	X = 0.0f;
	Y = 0.0f;
	
	glBegin(GL_TRIANGLES);
       glVertex2f(ax, ay);
	   glVertex2f(bx, by);
	   glVertex2f(cx, cy);
	 glEnd();
	
		 glFlush();
	 glutPostRedisplay();
	
 };

 void teclado(unsigned char key, int x, int y){
	if (key == 'a') {
		  X = 0.5f;
		
	}
	else if (key == 's') {
		 Y -= 0.5f;
		
	}
	else if (key == 'd') {
		 X += 0.5f;
		
	}
	else if (key == 'w') {
		Y += 0.5f;
		
	}
	else if (key == 27) {
		//ESC
		exit(0);
		
	}
}
 void glutTimer(int value){
	glutPostRedisplay();
	glutTimerFunc(25, glutTimer, 1);
}

 void inicializa(){
	 glMatrixMode(GL_PROJECTION);
	 gluOrtho2D(-50, 50, -50, 50);
	 glMatrixMode(GL_MODELVIEW);
	
		 glutTimerFunc(1, glutTimer, 1);
}
int main(int argc, char **argv){
		 glutInit(&argc, argv);
	
		 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
		 glutInitWindowSize(600, 600);
	
		 glutCreateWindow("Trabalho Triangulo");
	
		 glutDisplayFunc(desenha);
	
		 glutKeyboardFunc(teclado);
	
		inicializa();
		glutMainLoop();
	return 0;
}
