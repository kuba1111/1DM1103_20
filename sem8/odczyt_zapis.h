# ifndef odczyt_h
# define odczyt_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matlab.h"


struct Macierz *wczytaj(FILE * fin);
  
void zapisz(char *nazwa, struct Macierz m) ;

void zapiszwT(struct Macierz w);
# endif
