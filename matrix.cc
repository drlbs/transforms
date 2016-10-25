#include <cmath>


float dot( float x0, float y0, float z0, float x1, float y1, float z1)
{
	return(x0*x1+y0*y1+z0*z1);
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

   for (i=0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
           temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);

   for (i=0; i<SIZE; i++)
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

	return(sqrt(dot(x0,y0,z0,x1,y1,z1)));
}	

void buildTranslate( float x, float y, float z, float *pA )
{
     *(pA+0)=1.0; *(pA+1)=0.0; *(pA+2)=0.0; *(pA+3)=x;
     *(pA+4)=0.0; *(pA+5)=1.0; *(pA+6)=0.0; *(pA+7)=y;
     *(pA+8)=0.0; *(pA+9)=0.0; *(pA+10)=1.0; *(pA+11)=z;
     *(pA+12)=0.0; *(pA+13)=0.0; *(pA+14)=0.0; *(pA+15)=1.0;
}

void buildIdentity( float theta, float *pA )
{

     *(pA+0)=1.0; *(pA+1)=0.0;       *(pA+2)=0.0;       *(pA+3)=0.0;
     *(pA+4)=0.0; *(pA+5)=1.0;       *(pA+6)=0.0;       *(pA+7)=0.0;
     *(pA+8)=0.0; *(pA+9)=0.0;       *(pA+10)=1.0;      *(pA+11)=0.0;
     *(pA+12)=0.0;*(pA+13)=0.0;      *(pA+14)=0.0;      *(pA+15)=1.0;
}      

void buildRotateX( float theta, float *pA )
{
     float phi;

     phi = theta * M_PI / 180.0;

     *(pA+0)=1.0; *(pA+1)=0.0;       *(pA+2)=0.0;       *(pA+3)=0.0;
     *(pA+4)=0.0; *(pA+5)= cos(phi); *(pA+6)=-sin(phi); *(pA+7)=0.0;
     *(pA+8)=0.0; *(pA+9)=sin(phi);  *(pA+10)=cos(phi); *(pA+11)=0.0;
     *(pA+12)=0.0;*(pA+13)=0.0;      *(pA+14)=0.0;      *(pA+15)=1.0;
}      

void buildRotateY( float theta, float *pA )
{
     float phi;
 
     phi = theta * M_PI / 180.0;

     *(pA+0)=cos(phi);  *(pA+1)=0.0;  *(pA+2)=sin(phi);  *(pA+3)=0.0;
     *(pA+4)=0.0;       *(pA+5)= 1.0; *(pA+6)=0.0;       *(pA+7)=0.0;
     *(pA+8)=-sin(phi); *(pA+9)=0.0;  *(pA+10)=cos(phi); *(pA+11)=0.0;
     *(pA+12)=0.0;      *(pA+13)=0.0; *(pA+14)=0.0;      *(pA+15)=1.0;
}      
      
void buildRotateZ( float theta, float *pA )
{
     float phi;

     phi = theta * M_PI / 180.0;

     *(pA+0)=cos(phi); *(pA+1)=-sin(phi); *(pA+2)=0.0; *(pA+3)=0.0;
     *(pA+4)=sin(phi); *(pA+5)= cos(phi); *(pA+6)=0.0; *(pA+7)=0.0;
     *(pA+8)=0.0;      *(pA+9)=0.0;       *(pA+10)=1.0; *(pA+11)=0.0;
     *(pA+12)=0.0;     *(pA+13)=0.0;      *(pA+14)=0.0; *(pA+15)=1.0;
}      

