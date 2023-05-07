#include "GL/glut.h"

void drawRectangle(double* vertex1, double* vertex2, double* vertex3, double* vertex4, double* rgb) 
{
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glBegin(GL_POLYGON);
	
	glVertex3f(vertex1[0], vertex1[1], vertex1[2]);
	glVertex3f(vertex2[0], vertex2[1], vertex2[2]);
	glVertex3f(vertex3[0], vertex3[1], vertex3[2]);
	glVertex3f(vertex4[0], vertex4[1], vertex4[2]);
	
	glEnd();
	glFlush();
}

void drawTriangle(double* vertex1, double* vertex2, double* vertex3, double* rgb) 
{
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glBegin(GL_POLYGON);
	
	glVertex3f(vertex1[0], vertex1[1], vertex1[2]);
	glVertex3f(vertex2[0], vertex2[1], vertex2[2]);
	glVertex3f(vertex3[0], vertex3[1], vertex3[2]);
	
	glEnd();
	glFlush();
}

void drawHouse(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	double r1vertex1[3] = {0.3, 0.2, 0.0};
	double r1vertex2[3] = {0.3, 0.6, 0.0};
	double r1vertex3[3] = {0.7, 0.6, 0.0};
	double r1vertex4[3] = {0.7, 0.2, 0.0};
	double r1rgb[3] = {0.2,0.3,0.4};
	drawRectangle(r1vertex1, r1vertex2, r1vertex3, r1vertex4, r1rgb);
	
	double tvertex1[3] = {0.25, 0.6, 0.0};
	double tvertex2[3] = {0.5, 0.8, 0.0};
	double tvertex3[3] = {0.75, 0.6, 0.0};
	double trgb[3] = {1.0, 0.0, 0.0};
	drawTriangle(tvertex1, tvertex2, tvertex3, trgb);
	
	double r2vertex1[3] = {0.45, 0.2, 0.0};
	double r2vertex2[3] = {0.45, 0.4, 0.0};
	double r2vertex3[3] = {0.55, 0.4, 0.0};
	double r2vertex4[3] = {0.55, 0.2, 0.0};
	double r2rgb[3] = {0.55, 0.4, 0.1};
	drawRectangle(r2vertex1, r2vertex2, r2vertex3, r2vertex4, r2rgb);
	
	double r3vertex1[3] = {0.32, 0.42, 0.0};
	double r3vertex2[3] = {0.32, 0.52, 0.0};
	double r3vertex3[3] = {0.42, 0.52, 0.0};
	double r3vertex4[3] = {0.42, 0.42, 0.0};
	double r3rgb[3] = {0.55, 0.4, 0.1};
	drawRectangle(r3vertex1, r3vertex2, r3vertex3, r3vertex4, r3rgb);
	
	double r4vertex1[3] = {0.68, 0.42, 0.0};
	double r4vertex2[3] = {0.68, 0.52, 0.0};
	double r4vertex3[3] = {0.58, 0.52, 0.0};
	double r4vertex4[3] = {0.58, 0.42, 0.0};
	double r4rgb[3] = {0.55, 0.4, 0.1};
	drawRectangle(r4vertex1, r4vertex2, r4vertex3, r4vertex4, r4rgb);
	
	glFlush();
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);	
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
		
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(250, 250);
	
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Draw The House");
	
	init();
	glutDisplayFunc(drawHouse);
	
	glutMainLoop();
	return 0;
}
