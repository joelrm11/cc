#include<GL/glut.h>
#include<stdio.h>
int x=0,ch,theta,h,k;
/*void timer(int e){
	x++;
	glutPostRedisplay();
	glutTimerFunc(50,timer,0);
}*/
void draw_triangle(void){
	glColor3f(1.0,0.0,0.0);
	glLineWidth(10.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(40,40);
	glVertex2i(50,40);
	glVertex2i(45,60);
	glEnd();
}
void rotate_triangle(){
	glMatrixMode(GL_MODELVIEW);
	glRotatef(theta,0,1,0);
}
int rotate_triangle_fix(int h,int k){
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(h,k,0);
	glRotatef(theta,0,1,0);
	glTranslatef(-h,-k,0);
}
void dis_origin(void){
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	rotate_triangle();
	draw_triangle();
	glPopMatrix();
	glFlush();
}
void dis_fix(void){
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	rotate_triangle_fix(h,k);
	draw_triangle();
	glPopMatrix();
	glFlush();
}

int main(int argc,char ** argv){
	printf("enter the choice:(1 for fixed point & 2 for origin)\n");
	scanf("%d",&ch);
	printf("enter angle of rotation:\n");
	scanf("%d",&theta);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(0,0);
	switch(ch){
		case 1: printf("enter the fixed points(x,y):\n");
			   scanf("%d%d",&h,&k);
			   glutCreateWindow("fixed point rotation");
			   glutDisplayFunc(dis_fix);
			   break;
		case 2: glutCreateWindow("origin rotation");
		        glutDisplayFunc(dis_origin);
		        break;
		default: printf("wrong choice\n");
				break;
	}
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-100,100);
	//glutDisplayFunc(display);
	//timer(0);
	glutMainLoop();
}
