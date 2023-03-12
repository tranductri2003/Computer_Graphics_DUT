//#include <GL/glut.h>
//#include <stdio.h>
//#include <math.h>
//
//#define delta 0.001
//#define PI 3.14159265358979323846
//
//double x(double t) 
//{
//	//x = t + sin(2.0*t)
//	return t + sin(2.0*t);
//} 
//
//double y(double t)
//{
//	//y = t + sin(3.0*t)
//	return  t + sin(3.0*t);
//}
//
//void drawCurve() 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	double rgb[3] = {0.2, 0.7, 0.6};
//	glBegin(GL_POINTS);
//	for (double t = -7.0; t <= 7.0; t += delta)
//	{
//		printf("x = %lf\n", x(t));
//		printf("y = %lf\n", y(t));
//		glColor3f(rgb[0], rgb[1], rgb[2]);
//		glVertex3f(x(t), y(t), 0.0);
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
//	glOrtho(-7.0, 7.0, -7.0, 7.0, -1.0, 1.0);
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
