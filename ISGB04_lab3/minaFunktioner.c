#include "minaFunktioner.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// genererar en lottorad men 7 unika tal
void lottoGenerator(int *lottorad){
    // variabel med 35 platser
    int tal[35];
    // loop som lägger in värden 1-35 i arrayen "tal".
    for(int i = 0; i < 35; i++){
        tal[i] = i + 1;
    }
    for(int i = 0; i < 7; i++){
        // slumpar ett index att använda för att plocka tal,
        //minskar rand med ett steg för att endast använda de tillgängliga talen.
        int index = rand() % (35 - i);
        // tilldelar det värdet tal har på den slumpade positionen
        lottorad[i] = tal[index];
        // flyttar det sista oanvända talet till den använda platsen
        tal[index] = tal[34 - i];
    }
}

// öppnar fil
FILE* openFil(const char* filenamn, const char* typ){
    FILE* fp = fopen(filenamn, typ);
    if(fp == NULL){
        printf("Kunde inte öppna filen!\n");
        return NULL;
    }
    return fp;
}

// skriver till fil
void skriv(FILE* fp, int lottorader[][7], int antal){
    if(fp == NULL){
        printf("\nKunde inte skriva till filen\n");
        return;
    }
    for(int i = 0; i < antal; i++){
        for(int j = 0; j < 7; j++){
            fprintf(fp, "%i ", lottorader[i][j]);
        }
        fprintf(fp, "\n");
    }
}

// skriver ut från fil
void lasFil(FILE* fp){

    if(fp == NULL){
        printf("\nKunde inte läsa filen!\n");
        return;
    }
    // variabel för att lagra varje rad tillfälligt för att skriva ut
    char rad[40];
    // läser rad för rad i filen tills den blir NULL
    while (fgets(rad, sizeof(rad), fp)!=NULL){
        printf("%s", rad);
    }
}





