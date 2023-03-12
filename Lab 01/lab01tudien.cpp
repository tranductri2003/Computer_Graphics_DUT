//#include<gl/glut.h>
//#include<stdio.h>
//
//void drawTetrahedron(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//  	glBegin(GL_LINE_LOOP);
//  	
//  	//A
//  	glColor3f(1, 1, 1); 
//	glVertex3f(0.2, 0.2, 0);
//	
//	//B
//	glColor3f(1, 0, 0); 
//	glVertex3f(0.2, 0.8, 0);
//	
//	//C
//	glColor3f(0, 1, 0); 
//	glVertex3f(0.5, 0.3, 0.2);
//	
//	//D
//	glColor3f(0, 0, 1); 
//	glVertex3f(0.6, 0.5, 0.4);
//	
//  	glEnd();
//  	
//  	glBegin(GL_LINES);
//  	
//  	//AC
//  	//A
//  	glColor3f(1, 1, 1); 
//	glVertex3f(0.2, 0.2, 0);
//	//C
//	glColor3f(0, 1, 0); 
//	glVertex3f(0.5, 0.3, 0.2);
//	
//	
//	//BD
//	//B
//	glColor3f(1, 0, 0); 
//	glVertex3f(0.2, 0.8, 0);
//	//D
//	glColor3f(0, 0, 1); 
//	glVertex3f(0.6, 0.5, 0.4);
//	
//  	glEnd();
//
//  	glFlush();
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
//
//int main(int argc, char **argv)
//{
//   	glutInit(&argc, argv);
//		
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	
//	glutInitWindowSize(500, 500);
//	
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Draw Tetrahedron");
//   
//   	init();
//   	glutDisplayFunc(drawTetrahedron);
//   	glutMainLoop();
//   	return 0;
//}
