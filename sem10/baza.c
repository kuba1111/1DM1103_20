#include "baza.h"
void wypisz_rekurencyjnie(Student *el) {
    if (el != NULL) {
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
        wypisz_rekurencyjnie( el->nast );
    }
}
Student * ostatni(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}
Student * usun(Student *glowa, Student *l) {
    Student *c = glowa;
    if (glowa == l) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == l) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Student * najwiekszy(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * sortuj_przez_wybieranie_przeciwnie(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy(glowa);
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;
}
Student * najmniejszy(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) < 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * sortuj_przez_wybieranie_zgodnie(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy(glowa);
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;

}

void wypisz_studentow_alfabetycznie(Student *glowa)
{
    Student *s = najmniejszy(glowa);

   printf("najmniejsz: %s,%s,%s,%s\n",  s->imie, s->nazwisko, s->nr_albumu, s->email);
   wypisz_rekurencyjnie(sortuj_przez_wybieranie_zgodnie(glowa));
}

void wypisz_studentow_odwr_alfabetycznie(Student *glowa)
{
    Student *s = najwiekszy(glowa);
   printf("Najwiekszy: %s,%s,%s,%s\n", s->imie,s->nazwisko,s->nr_albumu,s->email );
   wypisz_rekurencyjnie(sortuj_przez_wybieranie_przeciwnie(glowa));
}
Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Student *c;

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni(glowa);
            c->nast = stud;
            stud->poprz = c;
        }
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * ostatniS(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}
Przedmiot * usunS(Przedmiot *glowa, Przedmiot *l) {
    Przedmiot *c = glowa;
    if (glowa == l) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == l) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}
Przedmiot * najwiekszyS(Przedmiot *l) {
    Przedmiot * max = NULL;
    while (l != NULL) {
        if (max == NULL) {
            max = l;
        } else {
            if ( strcmp(l->kod_przedmiotu, max->kod_przedmiotu) > 0 ) 
                max = l;
        }
        l = l->nast;
    }
    return max;
}
Przedmiot * najmniejszyS(Przedmiot *l) {
    Przedmiot * max = NULL;
    while (l != NULL) {
        if (max == NULL) {
            max = l;
        } else {
            if ( strcmp(l->kod_przedmiotu, max->kod_przedmiotu) < 0 ) 
                max = l;
        }
        l = l->nast;
    }
    return max;
}


Przedmiot * sortuj_przez_wybieranie_S(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszyS(glowa);
        glowa = usunS(glowa, m);
        
        o = ostatniS(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }

}
 return nglowa;
}
void wypisz_rekurencyjnie_S(Przedmiot *el) {
    if (el != NULL) {
        printf("%s %s %s \n", el->kod_przedmiotu, el->nazwa_przedmiotu, el->semestr);        
        wypisz_rekurencyjnie_S( el->nast );
    }
}
void wypisz_rekurencyjnie_PRZEDMIOTY(Przedmiot *el) {
    if (el != NULL) {
        printf("%s %s %s \n", el->kod_przedmiotu, el->nazwa_przedmiotu, el->semestr);        
        wypisz_rekurencyjnie_S( el->nast );
    }
}
void wypisz_rekurencyjnie_od_konca_PRZEDMIOTY(Przedmiot *el) {
    if (el != NULL) {
        wypisz_rekurencyjnie_S( el->nast );
        printf("%s %s %s\n", el->kod_przedmiotu, el->nazwa_przedmiotu, el->semestr);        
    }
}
void wypisz_przedmioty_rosnaco_po_kodzie(Przedmiot *glowa)
{
    Przedmiot *p = najwiekszyS(glowa);
   printf("Najwiekszy: %s,%s,%s\n", p->kod_przedmiotu, p->nazwa_przedmiotu, p->semestr);
   wypisz_rekurencyjnie_S(sortuj_przez_wybieranie_S(glowa));
}
void wypisz_przedmioty_malejaco_po_kodzie(Przedmiot *glowa)
{
    Przedmiot *p = najmniejszyS(glowa);
   printf("Najmniejszy: %s,%s,%s\n",  p->kod_przedmiotu, p->nazwa_przedmiotu, p->semestr);
   wypisz_rekurencyjnie_od_konca_PRZEDMIOTY(sortuj_przez_wybieranie_S(glowa));
}
Przedmiot* wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Przedmiot *c;

    for (i=0; i<n; i++) {
        Przedmiot *przedmiot = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedmiot->nast = NULL;
        przedmiot->poprz = NULL;

        if (glowa == NULL)
            glowa = przedmiot;
        else {
            c = ostatniS(glowa);
            c->nast = przedmiot;
            przedmiot->poprz = c;
        }

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przedmiot->nazwa_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->nazwa_przedmiotu, s);

        s = strtok(NULL, "\n");
        przedmiot->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->semestr, s);

    }

    return glowa;
}
Przedmiot * najwiekszyS_N(Przedmiot *l) {
    Przedmiot * max = NULL;
    while (l != NULL) {
        if (max == NULL) {
            max = l;
        } else {
            if ( strcmp(l->nazwa_przedmiotu, max->nazwa_przedmiotu) > 0 ) 
                max = l;
        }
        l = l->nast;
    }
    return max;
}
Przedmiot * najmniejszyS_N(Przedmiot *l) {
    Przedmiot * max = NULL;
    while (l != NULL) {
        if (max == NULL) {
            max = l;
        } else {
            if ( strcmp(l->nazwa_przedmiotu, max->nazwa_przedmiotu) < 0 ) 
                max = l;
        }
        l = l->nast;
    }
    return max;
}

Przedmiot * sortuj_przez_wybieranie_S_N(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszyS_N(glowa);
        glowa = usunS(glowa, m);
        
        o = ostatniS(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
    
}
return nglowa;
}

Ocena * filtruj(Ocena * glowa, char *kod_przedmiotu) {
Ocena * max = NULL;
    while (glowa != NULL) {
        if (max == NULL) {
            max = glowa;
        } else {
            if ( strcmp(glowa->kod_przedmiotu, kod_przedmiotu) == 0 ) 
                max = glowa;
        }
        glowa = glowa->nast;
    }
    return max;
}
Ocena * filtruj2(Ocena * glowa, char *nr_albumu) {
Ocena * max = NULL;
    while (glowa != NULL) {
        if (max == NULL) {
            max = glowa;
        } else {
            if ( strcmp(glowa->nr_albumu, nr_albumu) == 0 ) 
                max = glowa;
        }
        glowa = glowa->nast;
    }
    return max;
}

void wypisz_rekurencyjnie_filtr(Ocena *el) { //wypisz_rekurencyjnie_filtr(filtruj(...))
    if (el != NULL) {
        printf("%s %s %s %s \n", el->kod_przedmiotu, el->nr_albumu, el->ocena, el->komentarz);        
        wypisz_rekurencyjnie_filtr( el->nast );
    }
}


void wypisz_przedmioty_odwr_alfabetycznie_po_kodzie(Przedmiot *glowa)
{
    Przedmiot *p = najwiekszyS_N(glowa);
   printf("Najwiekszy: %s,%s,%s\n",p->kod_przedmiotu,p->nazwa_przedmiotu,p->semestr);
   wypisz_rekurencyjnie_S(sortuj_przez_wybieranie_S_N(glowa));
}
void wypisz_przedmioty_alfabetycznie_po_kodzie(Przedmiot *glowa)
{
    Przedmiot *p = najmniejszyS_N(glowa);
   printf("Najmniejszy: %s,%s,%s\n", p->kod_przedmiotu,p->nazwa_przedmiotu,p->semestr);
   wypisz_rekurencyjnie_od_konca_PRZEDMIOTY(sortuj_przez_wybieranie_S_N(glowa));
}
Ocena* wczytaj_oceny(FILE *fin) { 
    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_mark = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);


    for (i=0; i<n; i++) {
        Ocena *ocenA = (Ocena*) malloc(sizeof(Ocena));
        ocenA->nast = NULL;

        if (last_mark == NULL)
            glowa = ocenA;
        else
            last_mark->nast = ocenA;
        last_mark = ocenA;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocenA->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenA->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        ocenA->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenA->nr_albumu, s);

        s = strtok(NULL, ";");
        ocenA->ocena = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenA->ocena, s);

        s = strtok(NULL, "\n");
       ocenA->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenA->komentarz, s);

    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot *subject = baza->lista_przedmiotow;
    while (subject != NULL) {
        n++;
        subject = subject->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena *mark = baza->lista_ocen;
    while (mark != NULL) {
        n++;
       mark = mark->nast;
    }
    return n;
}

void wypisz_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_studentow(SBaza *baza,FILE*fin) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}
void listuj_przedmioty(SBaza *baza,FILE*fin) {
    Przedmiot * subject = baza->lista_przedmiotow;
    while (subject != NULL) {
        fprintf(fin,"%s;%s;%s\n", subject->kod_przedmiotu, subject->nazwa_przedmiotu, subject->semestr);
        subject = subject->nast;
    }
}
void listuj_oceny(SBaza *baza,FILE*fin) {
    Ocena * mark = baza->lista_ocen;
    while (mark != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", mark->kod_przedmiotu, mark->nr_albumu, mark->ocena, mark->komentarz);
        mark = mark->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_przedmiot(Przedmiot *p) {
    free(p->kod_przedmiotu);
    free(p->nazwa_przedmiotu);
    free(p->semestr);
    free(p);
}

void zwolnij_liste_przedmiotow(Przedmiot *p){
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnij_ocena(Ocena *o) {
    free(o->kod_przedmiotu);
    free(o->nr_albumu);
    free(o->ocena);
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_ocen(Ocena *o){
    Ocena *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_ocena(o);
        o = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

void dodaj_studenta(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email){
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    teraz=baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }
    else
    {
      for(int i=1; i<ile_studentow(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }   
}


void dodaj_przedmiot(SBaza * baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr){

 	Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
  	Przedmiot *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);
    nowy->nazwa_przedmiotu = (char*) malloc(sizeof(char) * (strlen(nazwa_przedmiotu) + 1));
    strcpy(nowy->nazwa_przedmiotu, nazwa_przedmiotu);
    nowy->semestr = (char*) malloc(sizeof(char) * (strlen(semestr) + 1));
    strcpy(nowy->semestr, semestr);
    teraz = baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
      baza->lista_przedmiotow = nowy;
    }
    else
    {
      for(int i=1; i<ile_przedmiotow(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }

}

void dodaj_studenta_do_przedmiotu(SBaza * baza, char *nr_albumu, char *kod_przedmiotu, char *oceneczka, char *komentarzyk){
Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
  	Ocena *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->ocena = (char*) malloc(sizeof(char) * (strlen(oceneczka) + 1));
    strcpy(nowy->ocena, oceneczka);
    nowy->komentarz = (char*) malloc(sizeof(char) * (strlen(komentarzyk) + 1));
    strcpy(nowy->komentarz, komentarzyk);
    teraz = baza->lista_ocen;
    
    if(ile_ocen(baza) == 0)
    {
      baza->lista_ocen = nowy;
    }
    else
    {
      for(int i=1; i<ile_ocen(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }
}

void zapisz_baze(char *nazwa_pliku, SBaza * baza) {
FILE *fin = fopen(nazwa_pliku, "w+");
fprintf(fin,"%d\n",ile_studentow(baza));
listuj_studentow(baza,fin);
fprintf(fin,"%d\n",ile_przedmiotow(baza));
listuj_przedmioty(baza,fin);
fprintf(fin,"%d\n",ile_ocen(baza));
listuj_oceny(baza,fin);
fclose(fin);
}