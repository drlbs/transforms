#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "prototypes.h"

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void drawAxes(int length)
{   

/* This provides a coordinate axis about the origin. */
   glPointSize(1.0);
   glBegin(GL_LINES);
     glVertex3i(0,length,0);
     glVertex3i(0,-length,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(length,0,0);
     glVertex3i(-length,0,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(0,0,length);
     glVertex3i(0,0,-length);
   glEnd();
}

void display(void)
{
   const int DIMENSION=4;
   float matrix[DIMENSION*DIMENSION];
   float p1[4], p2[4], p3[4];
   float *M;
   int i, j;
  
   p1[0]=1.0; p1[1]=1.0; p1[2]=1.0; p1[3]=1.0;
   p2[0]=2.0; p2[1]=2.0; p2[2]=1.0; p2[3]=1.0;
   p3[0]=2.0; p3[1]=3.0; p3[2]=2.0; p3[3]=1.0;

   M = &matrix[0];

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */
   gluLookAt (3.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   /* Draw a coordinate axis */

   drawAxes(5);

#ifdef DEBUG
  printf("**************\n");
  printf( "Red Segment Vertices Before Transformation\n");
  printf( "    %f %f %f \n", p1[0], p1[1], p1[2]);
  printf( "    %f %f %f \n", p2[0], p2[1], p2[2]);
  printf( "Green Segment Vertices Before Transformation\n");
  printf( "    %f %f %f \n", p1[0], p1[1], p1[2]);
  printf( "    %f %f %f \n", p3[0], p3[1], p3[2]);
#endif


   /* Your code to move the object should appear below this line */

   buildTranslate(-1.0,-1.0,-1.0, M);
   glMultMatrixf(M);
   buildRotateZ(-45.0, M);
   glMultMatrixf(M);
   buildRotateX(35.27, M);
   glMultMatrixf(M);
   buildRotateZ(180.0, M);
   glMultMatrixf(M);

#ifdef DEBUG
  printf( "Red Segment Vertices After Transformation\n");
  printf( "    %f %f %f \n", p1[0], p1[1], p1[2]);
  printf( "    %f %f %f \n", p2[0], p2[1], p2[2]);
  printf( "Green Segment Vertices After Transformation\n");
  printf( "    %f %f %f \n", p1[0], p1[1], p1[2]);
  printf( "    %f %f %f \n", p3[0], p3[1], p3[2]);
  printf("**************\n");
#endif


   /* Draw the line segments */

   glColor3f(1.0,0.0,0.0);               /* Red Segment */
   glBegin(GL_LINES);
     glVertex3f(p1[0], p1[1], p1[2] );
     glVertex3f(p2[0], p2[1], p2[2] );
   glEnd();
   glColor3f(0.0,1.0,0.0);               /* Green Segment */
   glBegin(GL_LINES);
     glVertex3f(p1[0], p1[1], p1[2] );
     glVertex3f(p3[0], p3[1], p3[2] );
   glEnd();

   glFlush();

}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
