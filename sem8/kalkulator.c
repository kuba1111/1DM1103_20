#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kalkulator.h"


struct Macierz dodaj (struct Macierz m1,struct Macierz m2)
{
    //struct Macierz suma;
    int i,j;
        //suma.r=m1.r;
        //suma.c=m1.c;
        printf("dodaj.. %d %d %f %f\n",m1.r,m1.c, m1.tab[2][2],m2.tab[2][2]);
        for (i = 0; i < m1.r; i++)
        {
            for (j=0; j < m1.c; j++)
            {
                m1.tab[i][j] += m2.tab[i][j];
                printf("%f ",m1.tab[i][j]);
            }
        }   
       
    return m1;
}
struct Macierz odejmij (struct Macierz m1,struct Macierz m2)
{
   // struct Macierz roznica;
    int i,j;
        //roznica.r=m1.r;
        //roznica.c=m1.c;
        for (i = 0; i < m1.r; i++)
        {
            for (j=0; j < m1.c; j++)
            {
                m1.tab[i][j] -=m2.tab[i][j];
            }
        }   
       
    return m1;
}
struct Macierz pomnoz_A_przez_b (struct Macierz m1,struct Macierz m2)
{
   //struct Macierz iloczyn1;
   int i,j,n;
  // iloczyn1.c=m2.c;
   //iloczyn1.r=m1.r;
   for (i = 0; i < m1.r; i++)
   {
        for (j=0; j < m1.c; j++)
        {
             for( int n = 0; n<m1.r; n++)
             m1.tab[i][j] *=m2.tab[n][j];
        }
    }
    return m1;
}
struct Macierz pomnoz_A_przez_liczbe (struct Macierz m1,float q)
{
   //struct Macierz iloczyn2;
   int i,j;
  // iloczyn2.c=m1.c;
  // iloczyn2.r=m1.r; 
   for (i = 0; i < m1.r; i++)
   {
        for (j=0; j < m1.c; j++)
        {
            m1.tab[i][j] *=q;
        }
   }
   return m1;
}
float norm(struct Macierz m1) 
{
    float s = 0;
    int i,j;
   // printf("norm %d %d %f\n",m1.r,m1.c,m1.tab[2][2]);
    for (i = 0; i < m1.r; i++) 
    {
        //printf("i: %d ", i);
        for (j=0; j < m1.c; j++) 
        {
           // printf("j: %d ",j);
            s += (m1.tab[i][j] * m1.tab[i][j]);
            //printf("s: %f\n",s);
        }
    }
    //printf("1234");
    return sqrt(s); 
}