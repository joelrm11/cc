#include<stdio.h>
#include<GL/glut.h>
GLfloat vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };
GLfloat colors[][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0},{0.5,1.0,0.0},{0.0,1.0,0.7} };
GLfloat theta[]={0.0,0.0,0.0};
GLint axis=1;
GLfloat viewer[3]={0.0,0.0,5.0};
void polygon(int a,int b,int c,int d){
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}
void colorcube(){
    polygon(0,1,2,3);
    polygon(2,3,6,7);
    polygon(6,7,4,5);
    polygon(0,1,5,4);
    polygon(1,2,6,5);
    polygon(0,3,7,5);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   //glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
    glPushMatrix();
    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);
    colorcube();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,2.0,20.0);
    }else{
         glFrustum(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,2.0,20.0);
    }
    glMatrixMode(GL_MODELVIEW);
}
void mouse(int btn,int state,int x,int y){
    if(btn==GLUT_LEFT_BUTTON&& state==GLUT_UP) axis=0;
    if(btn==GLUT_MIDDLE_BUTTON&& state==GLUT_UP) axis=1;
    if(btn==GLUT_RIGHT_BUTTON&& state==GLUT_UP) axis=2;
    theta[axis]+=0.2;
    if(theta[axis]>360.0){
        theta[axis]=0.0;
    }
}
void key(unsigned char key,int x,int y){
    if(key=='x') viewer[0]-=1;
    if(key=='X') viewer[0]+=1;
    if(key=='y') viewer[1]-=1;
    if(key=='Y') viewer[1]+=1;
    if(key=='z') viewer[2]-=1;
    if(key=='Z') viewer[2]+=1;
    glutPostRedisplay();

}
int main(int argv,char** argc){
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(900,900);
    glutCreateWindow("cube color");
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
