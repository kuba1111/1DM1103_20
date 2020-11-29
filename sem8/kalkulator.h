# ifndef kalkulator_h
# define kalkulator_h
#include <math.h>
#include "matlab.h"

struct Macierz dodaj (struct Macierz m1,struct Macierz m2);

struct Macierz odejmij (struct Macierz m1,struct Macierz m2);

struct Macierz pomnoz_A_przez_b (struct Macierz m1,struct Macierz m2);

struct Macierz pomnoz_A_przez_liczbe (struct Macierz m1,float q);

float norm(struct Macierz m1) ;
# endif

