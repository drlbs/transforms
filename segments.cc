#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void transpose( int ndim, float *m )
{
// m is a pointer to a square matrix of dimension ndim 
  int i, j;
  float temp; 
  for ( i=0; i<ndim; i++)
	  for (j=i+1;j<ndim; j++)
                  {
                  temp = *(m+i*ndim+j);
		  *(m+i*ndim+j)=*(m+j*ndim+i);
                  *(m+j*ndim+i)=temp;
                  }
}

void vmatm (int SIZE, float *pA, float *pB)

// pA is a pointer to the first element of matrix A
// pB is a pointer to the first element of vector B
// On return, B will contain transformed coordinates
{
   int i, j;
   float temp[4];

   for (i=0; i<SIZE; i++)
             temp[i] = 0.0;

   for (i = 0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
           temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);

   for (i = 0; i < SIZE; i++)
         *(pB+i) = temp[i];
}


void mmatm (int SIZE, float *pA, float *pB)

// pA is a pointer to the first element of matrix A
// pB is a pointer to the first element of matrix B
// On return, B will contain the matrix product 
{
   int i, j, k;
   float temp[4][4];

   for (i=0; i<SIZE; i++)
	   for (j=0; j<SIZE; j++)
             temp[i][j] = 0.0;

   for (i = 0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
	 for (k = 0; k < SIZE; k++)
           temp[i][j] += *(pA+(i*SIZE+k)) * *(pB+(k*SIZE+j));
        

   for (i = 0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
         *(pB+(i*SIZE+j)) = temp[i][j];

}

float vlength( float x0, float y0, float z0, float x1, float y1, float z1)
{
/* This will return the length of the line segment */

	float X, Y, Z;
	float length;
	
	X = x0-x1; Y=y0-y1; Z=z0-z1;
        length = sqrt(X*X+Y*Y+Z*Z);
	return(length);
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

   /* Your code to move the object should appear below this line */


  


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
