#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Macierz {
    int r;
    int c;
    float tab[200][200];
};
void wczytaj(FILE * fin, struct Macierz *m1)
 {
    int i;
    int j;
    fscanf(fin, "%d", &m1->r);
    fscanf(fin, "%d", &m1->c);

    for (i=0; i < m1->r; i++) {
        for (j=0; j < m1->c; j++) {
            fscanf(fin, "%f", &m1->tab[i][j]);
        }
    }
}
void wczytaj2(FILE * fin2, struct Macierz *m2) {
    int i,j;
    fscanf(fin2, "%d", &m2->r);
    fscanf(fin2, "%d", &m2->c);

    for (i=0; i < m2->r; i++) {
        for (j=0; j < m2->c; j++) {
            fscanf(fin2, "%f", &m2->tab[i][j]);
        }
    }
}
struct Macierz dodaj (struct Macierz m1,struct Macierz m2)
{
    struct Macierz suma;
    int i,j;
        suma.r=m1.r;
        suma.c=m1.c;
        for (i = 0; i < m1.r; i++)
        {
            for (j=0; j < m1.c; j++)
            {
                suma.tab[i][j] = m1.tab[i][j]+m2.tab[i][j];
            }
        }   
       
    return suma;
}
struct Macierz odejmij (struct Macierz m1,struct Macierz m2)
{
    struct Macierz roznica;
    int i,j;
        roznica.r=m1.r;
        roznica.c=m1.c;
        for (i = 0; i < m1.r; i++)
        {
            for (j=0; j < m1.c; j++)
            {
                roznica.tab[i][j] = m1.tab[i][j]-m2.tab[i][j];
            }
        }   
       
    return roznica;
}
struct Macierz pomnoz_A_przez_b (struct Macierz m1,struct Macierz m2)
{
   struct Macierz iloczyn1;
   int i,j,n;
   iloczyn1.c=m2.c;
   iloczyn1.r=m1.r;
   for (i = 0; i < m1.r; i++)
   {
        for (j=0; j < m1.c; j++)
        {
             for( int n = 0; n<m1.r; n++)
             iloczyn1.tab[i][j] = m1.tab[i][n]*m2.tab[n][j];
        }
    }
    return iloczyn1;
}
struct Macierz pomnoz_A_przez_liczbe (struct Macierz m1,float q)
{
   struct Macierz iloczyn2;
   int i,j;
   iloczyn2.c=m1.c;
   iloczyn2.r=m1.r; 
   for (i = 0; i < m1.r; i++)
   {
        for (j=0; j < m1.c; j++)
        {
            iloczyn2.tab[i][j] = m1.tab[i][j]*q;
        }
   }
   return iloczyn2;
}
float norm(struct Macierz m1) 
{
    float s = 0;
    int i,j;

    for (i = 0; i < m1.r; i++) {
        for (j=0; j < m1.c; j++) {
            s += m1.tab[i][j] * m1.tab[i][j];
        }
    }
    return sqrt(s); 
}
void zapisz(char *nazwa, struct Macierz m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;
    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) 
            fprintf(fout, "%4f  ", m.tab[i][j]);
        if (i < (m.r-1))
            {fprintf(fout,"\n ");}  
    }

    fclose(fout);
}
void zapiszwT(struct Macierz w)
{
    int i,j;
    printf("[");
    for (i = 0; i < w.r; i++) {
        for (j=0; j < w.c; j++)
            {
                printf("%8f", w.tab[i][j]);
                if( j< w.c-1)
                printf(" ");
            }
        if (i < (w.r-1))
            {printf("\n ");}  
    }
    printf("]\n");    
}

int main(int argc, char *argv[]) 
{
    struct Macierz mac1;
    struct Macierz mac2;
    FILE * fin;
    FILE * fin2;
    if ( strcmp( argv[1], "sum") == 0) 
    {
        if( argc == 5)
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);

            
            if( (mac1.r==mac2.r) && (mac2.c==mac1.c) )
                zapisz("do_B.txt", dodaj(mac1, mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe\n");
            }
        }
        else
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);

            
            if( (mac1.r==mac2.r) && (mac2.c==mac1.c) ) 
                zapiszwT(dodaj(mac1, mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe\n");
            }
        }
    fclose(fin);
    fclose(fin2); 
    }
    if ( strcmp( argv[1], "subtract") == 0) 
    {
        if(argc == 5)
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);
            if( (mac1.r==mac2.r) && (mac2.c==mac1.c) )
                zapisz("do_B.txt", odejmij(mac1,mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe");
            }
        }
        else
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);

            if( (mac1.r==mac2.r) && (mac2.c==mac1.c) ) 
                zapiszwT(odejmij(mac1,mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe");
            }
        }
    fclose(fin);
    fclose(fin2); 
    }
    if ( strcmp( argv[1], "prod") == 0) 
    {
        if( argc == 5)
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);
            if(mac1.c==mac2.r) 
            zapisz("do_B.txt", pomnoz_A_przez_b(mac1,mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ liczba kolumna w A jest różna on liczbt wierszy w B");
            }
        }
        else
        { 
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            wczytaj(fin, &mac1);
            wczytaj2(fin2, &mac2);
            if(mac1.c==mac2.r) 
                zapiszwT(pomnoz_A_przez_b(mac1,mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ liczba kolumna w A jest różna on liczbt wierszy w B");
            }
            
        }
    fclose(fin);
    fclose(fin2); 
    }

    if ( strcmp( argv[1], "multiply") == 0)
    {
        if( argc == 5)
        {
          fin  = fopen(argv[2], "r");
          fin2 = NULL;
          float value = atof(argv[3]);
          wczytaj(fin, &mac1); 
          zapisz("do_B.txt", pomnoz_A_przez_liczbe(mac1, value));
        }
        else
        {
            int i= 0; 
            fin  = fopen(argv[2], "r");
            fin2 = NULL; 
            wczytaj(fin, &mac1);  
            float value =  atof(argv[3]);   
            wczytaj(fin, &mac1);
            zapiszwT(pomnoz_A_przez_liczbe(mac1, value));
        }
    fclose(fin);
            
    }

    if(strcmp( argv[1], "norm") == 0)
    {
        if(argc == 4)
        {
            fin  = fopen(argv[2], "r");
            fin2 = NULL;
            wczytaj(fin, &mac1);
            FILE * fout = fopen("do_B.txt", "w");
            fprintf(fout,"%f",norm(mac1));
           
            fclose(fout);
        }
        else
        {
            fin  = fopen(argv[2], "r");
            fin2 = NULL;
            wczytaj(fin, &mac1);
            printf("%f",norm(mac1));
        }
        
    fclose(fin);
    }
}

        







