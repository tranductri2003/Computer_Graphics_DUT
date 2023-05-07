#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define delta 0.001
#define PI 3.14159265358979323846

double x(double* vertex0, double r, int i) 
{
	//x = vertex0[0] *cos(i* 0.4 * PI) – vertex0[1] *sin(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)sin(i * 0.4 * PI) + vertex0[0](1 - cos(i * 0.4 * PI))
	return (vertex0[0] * cos(i * 0.4 * PI) - vertex0[1] * sin(vertex0[1] * 0.4 * PI) + (vertex0[1] + r) * sin(i * 0.4 * PI) + vertex0[0] * (1 - cos(i * 0.4 * PI)));
} 

double y(double* vertex0, double r, int i)
{
	//y = vertex0[0] * sin(i* 0.4 * PI) + vertex0[1] *cos(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)(1-cos(i * 0.4 * PI)) + vertex0[0]*sin(i * 0.4 * PI)
	return vertex0[0] * sin(i * 0.4 * PI) + vertex0[1] * cos(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)*(1 - cos(i * 0.4 * PI)) + vertex0[0] * sin(i * 0.4 * PI);
}

void drawCircle(double* center, double radius, double* rgb) 
{    
	double delta_v = 0.01;
	
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glBegin(GL_POLYGON);
	
    for(double v = 0.0; v < 2.0*PI; v += delta_v)
    {
        double x = center[0] + radius*sin(v);
        double y = center[1] + radius*cos(v);
    	glVertex3f(x, y, 0.0);
    }
    glEnd();
	
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
	
    for(double v = 0.0; v < 2.0*PI; v += delta_v)
    {
        double x = center[0] + radius*sin(v);
        double y = center[1] + radius*cos(v);
    	glVertex3f(x, y, 0.0);
    }
    glEnd();
	
			
} 

void drawFlower() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	double r = 0.3;
	
	double vertex[5][2];
	vertex[0][0] = 0.0;
	vertex[0][1] = 0.0;
	double rgb1[3] = {1.0, 0.5, 0.2};
	drawCircle(vertex[0], r, rgb1);
	for (int i = 1; i < 5; i++)
	{
		vertex[i][0] = x(vertex[0], r, i);
		vertex[i][1] = y(vertex[0], r, i);
		drawCircle(vertex[i], r, rgb1);
	}
	
	double rgb2[3] = {1.0, 1.0, 0.0};
	double center[2] = {vertex[0][0], vertex[0][1] + r};
	drawCircle(center, 0.8 * r, rgb2);
	
	glFlush();
}

void init(void) 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
} 

int main(int argc, char**argv) 
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Draw Flower - 102210096 - TranDucTri");
	
	init();
	glutDisplayFunc(drawFlower);
	glutMainLoop();
	return 0;
}
