#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"



int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);
    FILE *fin = fopen(argv[1], "w");

    if (strcmp("list_students", argv[2]) == 0) {
        wypisz_studentow(baza);

    } else if (strcmp("add_student", argv[2]) == 0) {
        dodaj_studenta(baza, argv[3], argv[4], argv[5], argv[6]);

    }else if (strcmp("add_course", argv[2]) == 0) {
        dodaj_przedmiot(baza, argv[3], argv[4], argv[5]);

    }else if (strcmp("add_student_to_course", argv[2]) == 0) {
        dodaj_studenta_do_przedmiotu(baza, argv[3], argv[4], argv[5], argv[6]);

    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));////KONIEC STARYCH
////////////////////////////////////////////////////////////////////////////////////////////
    } else if (strcmp("sortuj_studentów-alfabetycznie", argv[2]) == 0) {
         baza->lista_studentow = sortuj_przez_wybieranie_zgodnie(baza->lista_studentow); 
        listuj_studentow(baza, fin);

    } else if (strcmp("sortuj_studentów-odwrotnie_alfabetycznie", argv[2]) == 0) {
       baza->lista_studentow = sortuj_przez_wybieranie_przeciwnie(baza->lista_studentow); 
        listuj_studentow(baza, fin);
    } else if (strcmp("sortuj_przedmioty_po_kodzie_rosnąco", argv[2]) == 0) {
        baza->lista_przedmiotow = najwiekszyS (baza->lista_przedmiotow); 
        listuj_przedmioty(baza, fin);
    } else if (strcmp("sortuj_przedmioty_po_kodzie_malejąco", argv[2]) == 0) {
        baza->lista_przedmiotow = najmniejszyS (baza->lista_przedmiotow); 
         listuj_przedmioty(baza, fin);
    } else if (strcmp("sortuj_przedmioty_po_NAZWIE_malejąco_alfabetycznie", argv[2]) == 0) {
         baza->lista_przedmiotow = najmniejszyS_N (baza->lista_przedmiotow); 
         listuj_przedmioty(baza, fin);
    } else if (strcmp("sortuj_przedmioty_po_NAZWIE_malejąco_odwrotnie_alfabetycznie", argv[2]) == 0) {
        baza->lista_przedmiotow = najwiekszyS_N (baza->lista_przedmiotow); 
        listuj_przedmioty(baza, fin);
    //////////////////////////////////////////////////////////
    } else if (strcmp("wypisz_sortuj_studentów-alfabetycznie", argv[2]) == 0) {
         wypisz_studentow_odwr_alfabetycznie(baza->lista_studentow);
    } else if (strcmp("wypisz_sortuj_studentów-odwrotnie_alfabetycznie", argv[2]) == 0) {
      wypisz_studentow_odwr_alfabetycznie(baza->lista_studentow);
    } else if (strcmp("wypisz_sortuj_przedmioty_po_kodzie_rosnąco", argv[2]) == 0) {
        wypisz_przedmioty_rosnaco_po_kodzie(baza->lista_przedmiotow);
    } else if (strcmp("wypisz_sortuj_przedmioty_po_kodzie_malejąco", argv[2]) == 0) {
         wypisz_przedmioty_malejaco_po_kodzie(baza->lista_przedmiotow);
    } else if (strcmp("wypisz_sortuj_przedmioty_po_nazwie_malejąco_alfabetycznie", argv[2]) == 0) {
         wypisz_przedmioty_odwr_alfabetycznie_po_kodzie(baza->lista_przedmiotow);
    } else if (strcmp("wypisz_sortuj_przedmioty_po_nazwie_malejąco_odwrotnie_alfabetycznie", argv[2]) == 0) {
        wypisz_przedmioty_alfabetycznie_po_kodzie(baza->lista_przedmiotow);
    
    ///////////////////////////////////////////////////////////////////////////
    } else if (strcmp("wyświetlenie_listy_ocen_z_przedmiotu_o_zadanym_kodzie", argv[2]) == 0) {
       wypisz_rekurencyjnie_filtr(filtruj(baza->lista_ocen, argv[3]));
    } else if (strcmp("wyświetlenie_listy_ocen_z_przedmiotu_o_zadanym_nr_albumu", argv[2]) == 0) {
        wypisz_rekurencyjnie_filtr(filtruj2(baza->lista_ocen, argv[3]));
    }
    zapisz_baze("baza.csv", baza);
    zwolnij(baza);
    return 0;
}

