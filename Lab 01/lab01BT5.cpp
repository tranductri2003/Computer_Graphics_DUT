//#include <GL/glut.h>
//#include <stdio.h>
//#include <math.h>
//
//#define delta 0.001
//#define PI 3.14159265358979323846
//
//double max(double x, double y)
//{
//	return (x > y) ? x : y;
//}
//
//void DDA(double* vertex1, double* vertex2, double* rgb) 
//{
//	double dx = vertex2[0] - vertex1[0], dy = vertex2[1] - vertex1[1];
//	double step = max(fabs(dx), fabs(dy));
//	double x_inc = dx/step, y_inc = dy/step;
//	glBegin(GL_POINTS);
//	glColor3f(rgb[0], rgb[1], rgb[2]);
//	glVertex3f(vertex1[0], vertex1[1], 0.0);
//	double k = 1.0;
//	double x = vertex1[0], y = vertex1[1];
//	while (k <= step) 
//	{
//		k += 1.0;
//		x += x_inc;
//		y += y_inc;
//		printf("Point: %lf %lf %lf\n", x, y, 0.0);
//		glVertex3f(x, y, 0.0);
//	}
//	glEnd();
//}
//
//double x(double* vertex0, double r, int i) 
//{
//	//x = vertex0[0] *cos(i* 0.4 * PI) – vertex0[1] *sin(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)sin(i * 0.4 * PI) + vertex0[0](1 - cos(i * 0.4 * PI))
//	return (vertex0[0] * cos(i * 0.4 * PI) - vertex0[1] * sin(vertex0[1] * 0.4 * PI) + (vertex0[1] + r) * sin(i * 0.4 * PI) + vertex0[0] * (1 - cos(i * 0.4 * PI)));
//} 
//
//double y(double* vertex0, double r, int i)
//{
//	//y = vertex0[0] * sin(i* 0.4 * PI) + vertex0[1] *cos(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)(1-cos(i * 0.4 * PI)) + vertex0[0]*sin(i * 0.4 * PI)
//	return vertex0[0] * sin(i * 0.4 * PI) + vertex0[1] * cos(vertex0[1] * 0.4 * PI) + (vertex0[1] +r)*(1 - cos(i * 0.4 * PI)) + vertex0[0] * sin(i * 0.4 * PI);
//}
//
//void drawStar() 
//{
//	
//	double r = 200;
//	
//	double vertex[5][2];
//	vertex[0][0] = 0.0;
//	vertex[0][1] = 0.0;
//	for (int i = 1; i < 5; i++)
//	{
//		vertex[i][0] = x(vertex[0], r, i);
//		vertex[i][1] = y(vertex[0], r, i);
//	}
//	
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	double rgb[3] = {0.0, 0.0, 0.0};
//	
//	DDA(vertex[0], vertex[2], rgb);
//	DDA(vertex[1], vertex[3], rgb);
//	DDA(vertex[2], vertex[4], rgb);
//	DDA(vertex[0], vertex[3], rgb);
//	DDA(vertex[1], vertex[4], rgb);
//	
//	glFlush();
//}
//
//void init(void) 
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-500, 500, -500, 500, -1.0, 1.0);
//} 
//
//int main(int argc, char**argv) 
//{
//	glutInit(&argc, argv);
//	
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("Draw Star");
//	
//	init();
//	glutDisplayFunc(drawStar);
//	glutMainLoop();
//	return 0;
//}
