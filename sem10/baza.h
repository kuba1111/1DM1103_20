#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;
    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
char * kod_przedmiotu;
char * nazwa_przedmiotu;
char * semestr;
struct _Przedmiot *poprz;
struct _Przedmiot *nast;
} Przedmiot;

 typedef struct _Ocena {
char * kod_przedmiotu;
char * nr_albumu;
char * ocena;
char * komentarz;
   struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;
Ocena * filtruj(Ocena * glowa, char *kod_przedmiotu);
Ocena * filtruj2(Ocena * glowa, char *kod_przedmiotu);
SBaza * wczytaj_baze(char *nazwa_pliku);
Student * sortuj_przez_wybieranie_zgodnie(Student *glowa);// nowe prz
Student * sortuj_przez_wybieranie_przeciwnie(Student *glowa);
Przedmiot * najwiekszyS(Przedmiot *l);
Przedmiot * najmniejszyS(Przedmiot *l);
Przedmiot * sortuj_przez_wybieranie_S(Przedmiot *glowa);
Przedmiot * najwiekszyS_N(Przedmiot *l);
Przedmiot * najmniejszyS_N(Przedmiot *l);
Przedmiot * sortuj_przez_wybieranie_S_N(Przedmiot *glowa);
void zapisz_baze(char *nazwa_pliku, SBaza * baza);
void dodaj_studenta(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
void dodaj_przedmiot(SBaza * baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr);
void dodaj_studenta_do_przedmiotu(SBaza * baza, char *nr_albumu, char *kod_przedmiotu, char *oceneczka, char *komentarzyk);
void wypisz_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
void wypisz_studentow_odwr_alfabetycznie(Student *glowa);//NOWE
void wypisz_studentow_alfabetycznie(Student *glowa);//NOWE
void wypisz_przedmioty_rosnaco_po_kodzie(Przedmiot *glowa);//NOWE
void wypisz_przedmioty_malejaco_po_kodzie(Przedmiot *glowa);//NOWE
void wypisz_przedmioty_odwr_alfabetycznie_po_kodzie(Przedmiot *glowa);//NOWE
void wypisz_przedmioty_alfabetycznie_po_kodzie(Przedmiot *glowa);//NOWE
void listuj_studentow(SBaza *baza,FILE*fin);//nowe prz
void listuj_przedmioty(SBaza *baza,FILE*fin);// nowe prz
void wypisz_rekurencyjnie_S(Przedmiot *el);
void wypisz_rekurencyjnie_PRZEDMIOTY(Przedmiot *el);
void wypisz_rekurencyjnie_filtr(Ocena *el);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);

#endif