
#include "odczyt_zapis.h"



struct Macierz *wczytaj(FILE * fin)
{
    struct Macierz*mc;
    mc= (struct Macierz*) malloc(sizeof(struct Macierz));
    //printf("pierwszy malloc\n");
    int i;
    int j;
    fscanf(fin, "%d", &mc->r);
    fscanf(fin, "%d", &mc->c);
    mc->tab=(float**)malloc(sizeof(float*)*mc->r);
    //printf("drugi malloc\n");
    for (i=0; i < mc->r; i++) 
    {
        mc->tab[i]=(float*)malloc(sizeof(float)*mc->c);
       // printf("TRZECi malloc\n");
        for (j=0; j < mc->c; j++) 
        {
            fscanf(fin, "%f", &mc->tab[i][j]);    
        }
    
    }
    return mc;
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
