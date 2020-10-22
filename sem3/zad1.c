#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (int argc, char *argv[])
    {
        float b;
        float a;
        a = atof(argv[1]);
        b= a*a;
        printf("Wartość %0.1f do kwadratu to %0.1f.\n", a, b);
        return 0;
    }
