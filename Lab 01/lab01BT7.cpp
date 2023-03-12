//#include <GL/glut.h>
//#include <stdio.h>
//#include <math.h>
//
//#define delta 0.001
//#define PI 3.14159265358979323846
//
//
//double x(double x_center, double r, double radian) 
//{
//	return r * cos(radian) + x_center;
//} 
//
//double y(double y_center, double r, double radian)
//{
//	return r * sin(radian) + y_center;
//}
//
//void drawTriangle(double* vertex1, double* vertex2, double* vertex3, double* rgb) 
//{
//	glColor3f(rgb[0], rgb[1], rgb[2]);
//	glBegin(GL_POLYGON);
//	
//	glVertex3f(vertex1[0], vertex1[1], vertex1[2]);
//	glVertex3f(vertex2[0], vertex2[1], vertex2[2]);
//	glVertex3f(vertex3[0], vertex3[1], vertex3[2]);
//	
//	glEnd();
//	glFlush();
//}
//
//void drawRectangle(double* vertex1, double* vertex2, double* vertex3, double* vertex4, double* rgb) 
//{
//	glColor3f(rgb[0], rgb[1], rgb[2]);
//	glBegin(GL_POLYGON);
//	
//	glVertex3f(vertex1[0], vertex1[1], vertex1[2]);
//	glVertex3f(vertex2[0], vertex2[1], vertex2[2]);
//	glVertex3f(vertex3[0], vertex3[1], vertex3[2]);
//	glVertex3f(vertex4[0], vertex4[1], vertex4[2]);
//	
//	glEnd();
//}
//
//void drawStar(double* center, double r) {
//	double starVertex[5][2];
//	double radian = 0.5 * PI;
//	
//	for (int i = 0; i < 5; i++)
//	{
//		starVertex[i][0] = x(center[0], r, radian);
//		starVertex[i][1] = y(center[1], r, radian);
//		radian += 0.4 * PI;
//	}
//	
//	double starRGB[3] = {1.0, 1.0, 0};
//	
//	for (int i = 2; i < 5; i++) 
//	{
//		drawTriangle(center, starVertex[i], starVertex[i - 2], starRGB);
//	}
//	drawTriangle(center, starVertex[1], starVertex[4], starRGB);
//	drawTriangle(center, starVertex[0], starVertex[3], starRGB);
//}
//
//void drawFlag(double* center, double r)
//{
//	double flagVertex[4][2] = {{center[0] - 2.5 * r, center[1] - 5.0 * r / 3.0},
//							   {center[0] - 2.5 * r, center[1] + 5.0 * r / 3.0},
//							   {center[0] + 2.5 * r, center[1] + 5.0 * r / 3.0},
//							   {center[0] + 2.5 * r, center[1] - 5.0 * r / 3.0}};
//	double flagRGB[3] = {0.8549019608, 0.1450980392, 0.1137254902};
//	
//	drawRectangle(flagVertex[0], flagVertex[1], flagVertex[2], flagVertex[3], flagRGB);
//}
//
//void drawVietnamNationalFlag() 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	double r = 0.3;
//	double center[2] = {0.0, 0.0};
//	
//	drawFlag(center, r);
//	drawStar(center, r);
//	
//	glFlush();
//}
//
//void init(void) 
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
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
//	glutCreateWindow("Draw Vietnam National Flag");
//	
//	init();
//	glutDisplayFunc(drawVietnamNationalFlag);
//	glutMainLoop();
//	return 0;
//}
