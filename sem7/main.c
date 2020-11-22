#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spis.h"
#include "ranking.h"

// jak uruchamiać?
// gcc zad5 (co chcemy zrobić) (z jakiego pliku txt) 




int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[2]);
if(strcmp(argv[1], "najtrudniejszy_przedmiot")==0)
    najtrudniejszy_przedmiot(dane, ile);
if(strcmp(argv[1], "najlatwiejszy_przedmiot")==0)
    najlatwiejszy_przedmiot(dane, ile);
if(strcmp(argv[1], "najlepszy_student")==0)
    najlepszy_student(dane,ile);
}