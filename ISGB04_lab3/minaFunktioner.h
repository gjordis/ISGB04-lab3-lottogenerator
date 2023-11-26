#ifndef MINAFUNKTIONER_H
#define MINAFUNKTIONER_H
#include <stdio.h>

// deklarerar funktioner.
// använder filpekare för att direkt manipulera variabler
void lottoGenerator(int* lottorad);
FILE* openFil(const char* filename, const char* mode);
void skriv(FILE* fp, int lottorader[][7], int antal);
void lasFil(FILE* fp);

#endif
