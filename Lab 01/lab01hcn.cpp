//#include "GL/glut.h"
//
//void display(void) 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glColor3f(0.0, 1.0, 1.0);
//	glBegin(GL_POLYGON); // Bat dau ve da giac
//	glVertex3f(0.25, 0.25, 0.0);
//	glVertex3f(0.75, 0.25, 0.0);
//	glVertex3f(0.75, 0.75, 0.0);
//	glVertex3f(0.25, 0.75, 0.0);
//	glEnd();	// Ket thuc ve da giac
//	glFlush();	// Thuc hien qua trinh day ra buffer
//}

//void init(void) {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}

//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	
//	//Khoi tao che do ve single buffer va he mau RGB
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	
//	//Khoi tao window kich thuoc 250 x 250
//	glutInitWindowSize(250, 250);
//	
//	//Khoi tao Window tai vi tri (100, 100) tren screen
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Draw retangle"); //Ten Window la 'Draw rectangle'
//	
//	//Khoi tao mot so co che do hoa
//	init();
//	glutDisplayFunc(display); //Thiet lap ham ve display
//	glutMainLoop(); //Bat dau chu trinh lap the hien ve
//	return 0;
//}
