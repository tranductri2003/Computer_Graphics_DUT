#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);    
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -5.0, 5.0);
}
void printmatrix(GLdouble thematrix[16])
{
   int i, j;
   for (i=0; i<4; ++i)
   {
      for (j=0; j<4; ++j)
      {
         cout << fixed << setprecision(4) << setw(7) << thematrix[j*4+i] << " ";
      }
      cout << endl;
   }
}
 
void printCurrentModelViewMatrix(){
  GLdouble matrixd[16];
  glGetDoublev(GL_MODELVIEW_MATRIX, matrixd);
  printmatrix(matrixd);
}

void function0(){
	glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
   glLoadIdentity();                // Reset the model-view matrix
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
 	printCurrentModelViewMatrix();	
   glFlush();   // Render now
}
void function1(){
	glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
   glLoadIdentity();                // Reset the model-view matrix
   glColor3f(1.0,1.0,0.0);
   glTranslatef(5.0,0.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
 	printCurrentModelViewMatrix();
   glFlush();   // Render now
}
void function2(){

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glRotatef(30.0,0.0,1.0,0.0);//angle,x,y,z
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
 	printCurrentModelViewMatrix();
   glFlush();   // Render now
}
void function3(){
	glClear(GL_COLOR_BUFFER_BIT);   
   glMatrixMode(GL_MODELVIEW);      
   glLoadIdentity();                
   glColor3f(1.0,1.0,0.0);
   glTranslatef(0.0,-2.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
   	printCurrentModelViewMatrix();
   	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(1.0,1.0,0.0);
   glRotatef(180.0,1.0,0.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
   printCurrentModelViewMatrix();
   
   	glClear(GL_COLOR_BUFFER_BIT);    
       
   
   glColor3f(1.0,1.0,0.0);
   glTranslatef(0.0,-2.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
   	printCurrentModelViewMatrix();
    glFlush();  
   
}
void function4(){
	double m[]={-3.0,-2.0,0.0}, n[]={1.0,2.0,0.0};
	double c[]={n[0]-m[0],n[1]-m[1],n[2]-m[2]};
	double d=sqrt(c[1]*c[1]+c[2]*c[2]);
	double l=sqrt(c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
	glClear(GL_COLOR_BUFFER_BIT);   
   glMatrixMode(GL_MODELVIEW);      
   glLoadIdentity();                
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
   	glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(-3.0,-2.0,0.0);
   		glVertex3f(1.0,2.0,0.0);
   	glEnd();
   	glColor3f(0.0,1.0,1.0);
   glTranslatef(-m[0],-m[1],-m[2]);
   double kx=acos(c[2]/d)*180/3.1416;
   double ky=acos(d/l)*180/3.1416;
   glRotatef(kx,1.0,0.0,0.0);
   glRotatef(-ky,0.0,1.0,0.0);
   glRotatef(180.0,0.0,0.0,1.0);
   glRotatef(ky,0.0,1.0,0.0);
   glRotatef(-kx,1.0,0.0,0.0);
   glTranslatef(m[0],m[1],m[2]);
   glBegin(GL_LINES);
   		glVertex3f(-3.0,-2.0,0.0);
   		glVertex3f(1.0,2.0,0.0);
   	glEnd();
   	printCurrentModelViewMatrix();
   	glFlush();
}
void function5(){
	double m[]={-3.0,-2.0,0.0}, n[]={1.0,2.0,0.0};
	double c[]={n[0]-m[0],n[1]-m[1],n[2]-m[2]};
	double d=sqrt(c[1]*c[1]+c[2]*c[2]);
	double l=sqrt(c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
	glClear(GL_COLOR_BUFFER_BIT);   
   glMatrixMode(GL_MODELVIEW);     
   glLoadIdentity();                
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(1.0,2.0,0.0);
   		glVertex3f(7.0,14.0,0.0);
   	glEnd();
   	glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
   		glVertex3f(-3.0,-2.0,0.0);
   		glVertex3f(1.0,2.0,0.0);
   	glEnd();
   	glColor3f(0.0,1.0,1.0);
   glTranslatef(-m[0],-m[1],-m[2]);
   double kx=acos(c[2]/d)*180/3.1416;
   double ky=acos(d/l)*180/3.1416;
   glRotatef(kx,1.0,0.0,0.0);
   glRotatef(-ky,0.0,1.0,0.0);
   glRotatef(30.0,0.0,0.0,1.0);
   glRotatef(ky,0.0,1.0,0.0);
   glRotatef(-kx,1.0,0.0,0.0);
   glTranslatef(m[0],m[1],m[2]);
   glTranslatef(m[0],m[1],m[2]);
   glBegin(GL_LINES);
   		glVertex3f(-3.0,-2.0,0.0);
   		glVertex3f(1.0,2.0,0.0);
   	glEnd();
   	printCurrentModelViewMatrix();
   	glFlush();
}
void display() {
   function0();
   char fb;
   cout<<"Nhap phim: ";
   cin>>fb;
   while(fb!='0'){
   glPopMatrix();                      
   if(fb=='t' || fb=='T'){
   	function1();
   }
   if(fb=='r' || fb=='R'){
   	function2();
   }
   if(fb=='p' || fb=='P'){
   	function3();
   }
   if(fb=='f' || fb=='F'){
   	function4();
   }
   if(fb=='h' || fb=='H'){
   	function5();
   }
   cout<<"Nhap phim: ";
   cin>>fb;
   }
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)
{ 
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
} 
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Model Transform");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   //glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}//main
