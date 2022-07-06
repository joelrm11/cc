#include<GL/glut.h>
#include<stdio.h>
GLfloat vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[][3]={{0.0,0.0,0.0},{1.0,1.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};
void polygon(int a,int b,int c,int d)
   {
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
 void colorcube(void )
 {
  polygon(0,1,2,3);
  polygon(3,2,6,7);
  polygon(0,4,7,3);
  polygon(1,5,6,2);
  polygon(4,5,6,7);
  polygon(0,1,5,4);
 }
  GLfloat theta[]={0.0,0.0,0.0};
  GLint axis=1;
  void display(void)
  {
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
   glRotatef(theta[2],0.0,0.0,1.0);
   colorcube();
   glPopMatrix();
   glFlush();
   glutSwapBuffers();
  }
  void spincube()
  {
   theta[axis]+=0.5;
   if(theta[axis]>360.0)
      theta[axis]=0.0;
   glutPostRedisplay();
  }
   void mouse(int btn,int state,int x,int y)
     {
     if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP) axis=0;
      if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_UP) axis=1;
      if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP) axis=2;
      } 
   void myreshape(int w,int h)
   {
      glViewport(0,0,w,h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      if(w<=h)
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-500.0,500.0);
      else
       glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-500.0,500.0);
       }
  
  int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
     glutInitWindowSize(500,500);
     glutCreateWindow("roatating a color cube_4MT19CS052");
     glutReshapeFunc(myreshape);
     glutDisplayFunc(display);
     glutIdleFunc(spincube);
     glutMouseFunc(mouse);
     glEnable(GL_DEPTH_TEST);
     glutMainLoop();
     return 0;
 }    
     
