#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matlab.h"
#include "odczyt_zapis.h"
#include "kalkulator.h"




int main(int argc, char *argv[]) 
{
    struct Macierz *mac1;
    struct Macierz *mac2;
    FILE * fin;
    FILE * fin2;
    if ( strcmp( argv[1], "sum") == 0) 
    {
        if( argc == 5)
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            mac1=wczytaj(fin);
            mac2=wczytaj(fin2);

            
            if( (mac1->r==mac2->r) && (mac2->c==mac1->c) )
                zapisz("do_B.txt", dodaj(*mac1, *mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe\n");
            }
        }
        else
        {
            printf("wchodzę\n");
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            printf("przed\n");
            mac1=wczytaj(fin);
            printf("1\n");
            mac2=wczytaj(fin2);
            printf("2\n");

            printf("%d %d %d %d\n",mac1->r, mac1->c, mac2->r, mac2->c);
            
            for(int i=0; i < mac1->c; i++)
            {
                for(int j=0; j< mac1->r;j++)
                {
                    printf("%f ",mac1->tab[i][j]);
                }
            }

            printf("po for\n");

            if( (mac1->r==mac2->r) && (mac2->c==mac1->c) ) 
                zapiszwT(dodaj(*mac1, *mac2));

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
            mac1=wczytaj(fin);
            mac2=wczytaj(fin2);
            if( (mac1->r==mac2->r) && (mac2->c==mac1->c) )
                zapisz("do_B.txt", odejmij(*mac1,*mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ wymiary macieży nie są równe");
            }
        }
        else
        {
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            mac1=wczytaj(fin);
            mac2=wczytaj(fin2);

            if( (mac1->r==mac2->r) && (mac2->c==mac1->c) ) 
                zapiszwT(odejmij(*mac1,*mac2));
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
            mac1=wczytaj(fin);
            mac2=wczytaj(fin2);
            if(mac1->c==mac2->r) 
            zapisz("do_B.txt", pomnoz_A_przez_b(*mac1,*mac2));
            else
            {
                printf("niestety nie da się dodać, ponieważ liczba kolumna w A jest różna on liczbt wierszy w B");
            }
        }
        else
        { 
            fin  = fopen(argv[2], "r");
            fin2 = fopen(argv[3], "r");
            mac1=wczytaj(fin);
            mac2=wczytaj(fin2);
            if(mac1->c==mac2->r) 
                zapiszwT(pomnoz_A_przez_b(*mac1,*mac2));
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
          mac1 = wczytaj(fin); 
          mac2 = NULL;
          zapisz("do_B.txt", pomnoz_A_przez_liczbe(*mac1, value));
        }
        else
        {
            int i= 0; 
            fin  = fopen(argv[2], "r");
            fin2 = NULL; 
            mac1 = wczytaj(fin); 
            mac2 = NULL; 
            float value =  atof(argv[3]);   
            zapiszwT(pomnoz_A_przez_liczbe(*mac1, value));
        }
    fclose(fin);
            
    }

    if(strcmp( argv[1], "norm") == 0)
    {
        if(argc == 4)
        {
            fin  = fopen(argv[2], "r");
            fin2 = NULL;
            mac1 = wczytaj(fin);
            mac2 = NULL;
            FILE * fout = fopen("do_B.txt", "w");
            fprintf(fout,"%f",norm(*mac1));
           
            fclose(fout);
        }
        else
        {
            fin  = fopen(argv[2], "r");
            fin2 = NULL;
            mac1 = wczytaj(fin);
            mac2 = NULL;
            printf("%f",norm(*mac1));
        }
        
    fclose(fin);
    }
    if (mac1 !=NULL)
        free (mac1);
    if (mac2 !=NULL)
        free (mac2);
}
