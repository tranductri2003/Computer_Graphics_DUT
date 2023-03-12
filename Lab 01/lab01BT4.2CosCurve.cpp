//#include <GL/glut.h>
//#include <stdio.h>
//#include <math.h>
//
//#define delta 0.001
//#define PI 3.14159265358979323846
//
//double func(double x) 
//{
//	return cos(x);
//} 
//
//void drawCurve() 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	double rgb[3] = {1.0, 0.5, 0.2};
//	glBegin(GL_POINTS);
//	for (double x = -1.0; x <= 1.0; x += delta)
//	{
//		printf("rgb: %lf %lf %lf \n", rgb[0], rgb[1], rgb[2]);
//		glColor3f(rgb[0], rgb[1], rgb[2]);
//		glVertex3f(x, func(x), 0.0);
//		rgb[0] -= delta;
//		rgb[1] -= delta / 5;
//		rgb[2] -= delta / 10;
//	}
//	glEnd();
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
//	glutInitWindowSize(600, 400);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("Draw Curve");
//	
//	init();
//	glutDisplayFunc(drawCurve);
//	glutMainLoop();
//	return 0;
//}
