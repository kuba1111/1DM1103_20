#include<stdio.h>
#include<stdlib.h>
#include<string.h>



 int main (int argc, char*argv[])
 {
    //Otwieram pierwszy plik
    FILE* fp = fopen(argv[1], "r");
    //Otwieram drugi plik
    FILE *ft = fopen(argv[2],"r");

    //Zmienne pomocnicze
    int value;
    int no_columns_A;
    int no_rows_A;
    int count =0;
    int *tab;
    //Szukam w pierwszym pliku kolejnych linii
    while (fscanf(fp, "%d", &value) != -1) 
    {
        //Znajduję liczbę wierszy
        if(count == 0)
            no_rows_A = value;
        //Znajduję liczbę kolumn
        else if(count == 1)
            no_columns_A = value;
        //Zapisuje do tabeli pomocniczej pozostałe wartości
        else
            tab[count-2] = value;

        count++;
    }
    //Tworzę pierwszą tablicę
    int tab_A[no_rows_A][no_columns_A];
    
    int k=0;
    //Wypełniam pierwszą tablicę wartościami z tabeli pomocniczej
    for(int i = 0; i< no_rows_A;i++)
    {
        for(int j=0; j <no_columns_A; j++)
        {
            tab_A[i][j] = tab[k];
            k++;
        }
    }
    int no_columns_X;
    int no_rows_X;
    count = 0;
    //Szukam w drugim pliku kolejnych linii
    while ((fscanf(ft, "%d", &value)) != -1) 
    {
        //Znajduję liczbę wierszy
        if(count == 0)
            no_rows_X = value;
        //Znajduję liczbę kolumn
        else if(count == 1)
            no_columns_X = value;
        //Zapisuje do tabeli pomocniczej pozostałe wartości
        else
            tab[count-2] = value;

        count++;
    }

    //Tworzę drugą tablicę
    int tab_X[no_rows_X][no_columns_X];
  
    k=0;
    //Wypełniam drugą tablicę wartościami z tabeli pomocniczej
    for(int i = 0; i< no_rows_X;i++)
    {
        for(int j=0; j <no_columns_X; j++)
        {
            tab_X[i][j] = tab[k];
            k++;
            
        }
    }

    //Zamykam otwarte pliki
    fclose(fp);
    fclose(ft);
    printf("(%d)(", no_rows_X);

    //Tworzę tablicę wyników mnożenia
    int return_tab[no_rows_A][no_columns_X];
    int n;
    //iteracja po wierszach tablicy A
    for (int i=0; i<no_rows_A; i++)                              //mnozenie macierzy
    {
        //iteracja po kolumnach tablicy X
        for(int j=0; j<no_columns_X; j++)
        {
            return_tab[i][j]=0;
            //Właściwa operacja mnożenia
            for(n=0; n<no_columns_A; n++)
                return_tab[i][j] += tab_A[i][n] * tab_X[n][j];  
                  
             printf("%3d",return_tab[i][j]);
        }
       
    }
    printf(" )\n");
    exit(0);
    return 0;
 
 }