#include<stdio.h>
#include<GL/glut.h>
float v[4][3]={{0.0,1.0,1.0},{1.0,0.0,0.0},{0.0,2.0,0.0},{-1.0,0.0,0.0}};
int n;

void triangle(float a[3],float b[3],float c[3]){
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide(float a[3],float b[3],float c[3],int m){
	float v1[3],v2[3],v3[3];
	int j;
	if(m>0){
		for(j=0;j<3;j++){
			v1[j]=(a[j]+b[j])/2;
			v2[j]=(a[j]+c[j])/2;
			v3[j]=(b[j]+c[j])/2;
		}
		divide(a,v1,v2,m-1);
		divide(v1,b,v3,m-1);
		divide(v2,v3,c,m-1);
	}else{
		triangle(a,b,c);
	}
}
void tetra_division(int m){
	glColor3f(1.0,0.0,0.0);
	divide(v[0],v[1],v[3],m);
	
	glColor3f(0.0,1.0,0.0);
	divide(v[0],v[2],v[3],m);
	
	glColor3f(0.0,0.0,1.0);
	divide(v[0],v[1],v[2],m);
	
	glColor3f(1.0,0.0,1.0);
	divide(v[1],v[2],v[3],m);
}


void display(){

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	tetra_division(n);
	glFlush();
	
}
int main(int argc,char **argv){

	printf("Enter no of divisions:");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("4MT19CS063-3d tetrahedran");
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0,3.0,-3.0,3.0,-10.0,10.0);
	glutMainLoop();
	return 0;
	
}
