#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
 
typedef float Matrix44 [4][4];
typedef float Matrix41 [4][1];
typedef float Matrix14 [4];
Matrix44 Matrix;
Matrix41 Matrixkq;
Matrix14 MatrixKQ;
float point [4] ={0,0,0,0};

void inputpoint(float x,float y,float z){
	point[0]=x;
	point[1]=y;
	point[2]=z;
	point[3]=1;
}
//khoi tao ma tran don vi
void matrixSetIdentity(Matrix44 m){
	int i,j;
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			m[i][j]=(i==j);
		}
	}
}
//Phep nhan 2 ma tran 4*4 a,b 
void matrixMul(Matrix44 a, Matrix44 b)
{
    int i, j;
    Matrix44 tmp;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tmp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            Matrix[i][j] = tmp[i][j];
        }
    }
}
//Phep nhan 2 ma tran xac dinh diem (44*41)
void matrixMul(Matrix44 a)
{
    int i, j;
    Matrix41 tmp;
    for (i = 0; i < 4; i++)
    {
        
            tmp[i][0] = a[i][0] * point[0] + a[i][1] * point[1]+ a[i][2] * point[2] + a[i][3] * point[3];
        
    }
    for (i = 0; i < 4; i++)
    {
 
            Matrixkq[i][0] = tmp[i][0];

    }
}
//Phep nhan 2 ma tran xac dinh diem (14*44)
void matrixMul1(Matrix44 a){
	int i,j;
	Matrix14 tmp;
	for(int i=0;i<4;i++){
		tmp[i]=0;
		for(int j=0;j<4;j++){
			tmp[i]+=point[j]*a[j][i];	
		}
	}
	for(int i=0;i<4;i++)
	{
		MatrixKQ[i]=tmp[i];
	}
}
//In ma tran bieu dien
void printMatrix(Matrix44 b){
	for(int i=0;i<4;i++){
		cout<<endl<<setw(5)<<"|"<<setw(10);
		for(int j=0;j<4;j++){
			cout<<setw(10);
			cout<<setprecision(4)<<b[i][j];
			if(j==3) cout<<setw(3)<<"|";
		}
	}
	cout<<endl<<endl;
}
//In toa do cua diem
void printpoint(Matrix41 a){
	
	cout<<"(";
	for(int i=0;i<3;i++){
		cout<<setprecision(4)<<a[i][0];
		if(i<2) cout<<";";
	}
	cout<<")";
	cout<<endl<<endl;
}
//In toa do cua diem
void printpoint(Matrix14 a){
	
	cout<<"(";
	for(int i=0;i<3;i++){
		cout<<setprecision(4)<<a[i];
		if(i<2) cout<<";";
	}
	cout<<")";
	cout<<endl<<endl;
}
//Bien doi tinh tien
void Translate(float x,float y, float z)
{
	Matrix44 m;
	matrixSetIdentity(m);
	
	m[0][3]=x;
	m[1][3]=y;
	m[2][3]=z;
	matrixMul(m,Matrix);
	cout<<"Ma tran tinh tien: "<<endl;
	printMatrix(Matrix);
}


float mulvecnon(float *a,float *b){
	return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}
void camerachange(float* eye,float *look, float *up,float *right){
	Matrix44 m={{right[0],up[0],look[0],0},{right[1],up[1],look[1],0},
	{right[2],up[2],look[2],0},{-mulvecnon(eye,right),-mulvecnon(eye,up),-mulvecnon(eye,look),1}};
	matrixMul(m,Matrix);
	cout<<"Ma tran bien doi: "<<endl;
	printMatrix(Matrix);
}
void display(){
	matrixSetIdentity(Matrix);
	float eye[3],look[3],up[3],right[3];
	cout<<"Nhap diem dat camera: ";
	cin>>eye[0]>>eye[1]>>eye[2];
	cout<<"Nhap diem nhin vao: ";
	cin>>look[0]>>look[1]>>look[2];
	cout<<"Nhap diem huong vao: ";
	cin>>up[0]>>up[1]>>up[2];
	
	//nhan co huong
	right[0]=up[1]*look[2]-up[2]*look[1];
	right[1]=up[2]*look[0]-up[0]*look[2];
	right[2]=up[0]*look[1]-up[1]*look[0];
	
	
	camerachange(eye,look,up,right);
	matrixMul1(Matrix);
	cout<<"Diem sau khi doi goc nhin la: ";
	printpoint(MatrixKQ);
}
int main(){
	
	float x,y,z;
	cout<<"Nhap toa do diem: "<<endl<<"=>";
	cin>>x>>y>>z;
	inputpoint(x,y,z);
	display();
	return 0;
}
