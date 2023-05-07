//#include "GL/glut.h"
//
//void drawTriangle(void) 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3f(0.25, 0.25, 0.0);
//	glVertex3f(0.75, 0.5, 0.0);
//	glVertex3f(0.25, 0.75, 0.0);
//	glEnd();
//	glFlush();
//}
//
//void init(void) 
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) 
//{
//	glutInit(&argc, argv);
//	
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	
//	glutInitWindowSize(250, 250);
//	
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Draw Triangle - Tran Duc Tri - 102210096");
//	
//	init();
//	glutDisplayFunc(drawTriangle);
//	glutMainLoop();
//	return 0;
//}
