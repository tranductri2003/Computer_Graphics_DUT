#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#define PI 3.1415926535897932384626433832795
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

void xien()
{
	float l,alpha;
	cout<<"Nhap he so rut ngan: ";
	cin>>l;
	cout<<"Nhap goc giua hinh chieu va truc nam ngang: ";
	cin>>alpha;
	alpha=alpha*PI/180;
	
	Matrix44 m;
	matrixSetIdentity(m);
	m[2][0]=l*cos(alpha);
	m[2][1]=l*sin(alpha);
	m[2][2]=0;
	
	matrixMul(m,Matrix);
	cout<<"Ma tran chieu xien: "<<endl;
	printMatrix(Matrix);
}
void trucgiao()
{
	Matrix44 m;
	matrixSetIdentity(m);
	cout<<"Lua chon mat chieu truc giao: "<<endl;
	cout<<"1. Mat OXY"<<endl;
	cout<<"2. Mat OXZ"<<endl;
	cout<<"3. Mat OYZ"<<endl;
	int choice;
	cin>>choice;
	switch (choice)
	{
		case 1: m[2][2]=0; break;
		case 2: m[1][1]=0; break;
		case 3: m[0][0]=0; break;
	}
	matrixMul(m,Matrix);
	cout<<"Ma tran chieu truc giao : "<<endl;
	printMatrix(Matrix);
}	
void phoicanh()
{
	float b,t,l,r,n,f;
	cout<<"Nhap cac thong so b,t,l,r: ";
	cin>>b>>t>>l>>r;
	cout<<"Nhap cac thong so near, far: ";
	cin>>n>>f;
	Matrix44 m;
	matrixSetIdentity(m);
	m[0][0]=2*n/(r-l);
	m[0][2]=(r+l)/(r-l);
	m[1][1]=2*n/(t-b);
	m[1][2]=(t+b)/(t-b);
	m[2][2]=-(f+n)/(f-n);
	m[2][3]=-2*f*n/(f-n);
	m[3][2]=-1;
	m[3][3]=0;
	cout<<"Ma tran Mpro : "<<endl;
	printMatrix(m);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			m[i][j]*=(1/-point[2]);
		}
	}
	matrixMul(m,Matrix);
	cout<<"Ma tran chieu phoi canh : "<<endl;
	printMatrix(Matrix);
}

void display(){
	matrixSetIdentity(Matrix);
	cout<<"Chon loai phep chieu: "<<endl;
	cout<<"1. Phep chieu xien"<<endl;
	cout<<"2. Phep chieu truc giao"<<endl;
	cout<<"3. Phep chieu phoi canh"<<endl;
	cout<<"=>";
	int choice;
	cin>>choice;
	switch (choice)
	{
		case 1: xien();break;
		case 2: trucgiao(); break;
		case 3: phoicanh(); break;
	}
	matrixMul(Matrix);
	cout<<"Toa do cua diem sau khi dieu chinh phep chieu: ";
	printpoint(Matrixkq);
}
int main(){
	
	float x,y,z;
	cout<<"Nhap toa do diem: "<<endl<<"=>";
	cin>>x>>y>>z;
	inputpoint(x,y,z);
	display();
	return 0;
}
