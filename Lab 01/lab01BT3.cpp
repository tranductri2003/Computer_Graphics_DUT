//#include "GL/glut.h"
//#include <stdio.h>
//#include <math.h> 
//
//#define PI 3.14159265358979323846
//
//double length(double* vertex1, double* vertex2)
//{
//	return sqrt((vertex1[0] - vertex2[0]) * (vertex1[0] - vertex2[0]) + (vertex1[1] - vertex2[1]) * (vertex1[1] - vertex2[1]));
//}
//
//double distance(double* point, double* vertex1, double* vertex2)
//{
//	double a = (vertex2[1] - vertex1[1])/(vertex2[0] - vertex1[0]);
//	double b = -1;
//	double c = vertex1[1] - vertex1[0]*a;
//
//	return (fabs(a*point[0] + b*point[1] + c)) / (sqrt(a*a + b*b));
//}
//
//void drawTriangle(double* vertex1, double* vertex2, double* vertex3, double* rgb) 
//{
//	double c120 = vertex1[0] - vertex2[0];
//	double c121 = vertex1[1] - vertex2[1];
//	double c122 = vertex1[2] - vertex2[2];
//	double c130 = vertex1[0] - vertex3[0];
//	double c131 = vertex1[1] - vertex3[1];
//	double c132 = vertex1[2] - vertex3[2];
//	if (c120 / c130 != c121 / c131 || c120 / c130 != c122 / c132 || c121 / c131 != c122 / c132) {
//		glColor3f(rgb[0], rgb[1], rgb[2]);
//		glBegin(GL_POLYGON);
//		
//		glVertex3f(vertex1[0], vertex1[1], vertex1[2]);
//		glVertex3f(vertex2[0], vertex2[1], vertex2[2]);
//		glVertex3f(vertex3[0], vertex3[1], vertex3[2]);
//		
//		glEnd();
//	}
//	else {
//		printf("Message: This is not a triangle.\n");
//	}
//}
//
//void drawCircle(double* center, double radius, double* rgb) 
//{    
//	double delta_v = 0.01;
//	glColor3f(rgb[0], rgb[1], rgb[2]);
//    glBegin(GL_POINTS);
//
//    for(double v = 0.0; v < 2.0*PI; v += delta_v)
//    {
//        double x = center[0] + radius*sin(v);
//        double y = center[1] + radius*cos(v);
//    	glVertex3f(x, y, 0.0);
//    }
//    glEnd();
//} 
//
//void drawInscribedCircleOfTriangle(void) 
//{
//	double tvertex1[3] = {0.3, 0.3, 0.0};
//	double tvertex2[3] = {0.8, 0.8, 0.0};
//	double tvertex3[3] = {0.35, 0.8, 0.0};
//	double trgb[3] = {0.2, 0.5, 1.0};
//	drawTriangle(tvertex1, tvertex2, tvertex3, trgb);
//	
//	double c12 = length(tvertex1, tvertex2);
//	double c13 = length(tvertex1, tvertex3);
//	double c23 = length(tvertex2, tvertex3);
//	double c123 = c12 +c13 + c23;
//
//	double center[2] = {(c12*tvertex3[0] + c23*tvertex1[0] + c13*tvertex2[0])/c123, (c12*tvertex3[1] + c23*tvertex1[1] + c13*tvertex2[1])/c123};
//	double crgb[3] = {1.0, 1.0, 0.0};
//	double radius = distance(center, tvertex1, tvertex2);
//	drawCircle(center, radius, crgb);
//	
//	glFlush();
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
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
//	glutInitWindowSize(500, 500);
//	
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Draw Inscribed Circle Of Triangle");
//	
//	init();
//	
//	glutDisplayFunc(drawInscribedCircleOfTriangle);
//	
//	glutMainLoop();
//	return 0;
//}
