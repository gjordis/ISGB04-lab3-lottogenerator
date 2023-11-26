#include "minaFunktioner.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// genererar en lottorad men 7 unika tal
void lottoGenerator(int *lottorad){
    // variabel med 35 platser
    int tal[35];
    // loop som l�gger in v�rden 1-35 i arrayen "tal".
    for(int i = 0; i < 35; i++){
        tal[i] = i + 1;
    }
    for(int i = 0; i < 7; i++){
        // slumpar ett index att anv�nda f�r att plocka tal,
        //minskar rand med ett steg f�r att endast anv�nda de tillg�ngliga talen.
        int index = rand() % (35 - i);
        // tilldelar det v�rdet tal har p� den slumpade positionen
        lottorad[i] = tal[index];
        // flyttar det sista oanv�nda talet till den anv�nda platsen
        tal[index] = tal[34 - i];
    }
}

// �ppnar fil
FILE* openFil(const char* filenamn, const char* typ){
    FILE* fp = fopen(filenamn, typ);
    if(fp == NULL){
        printf("Kunde inte �ppna filen!\n");
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

// skriver ut fr�n fil
void lasFil(FILE* fp){

    if(fp == NULL){
        printf("\nKunde inte l�sa filen!\n");
        return;
    }
    // variabel f�r att lagra varje rad tillf�lligt f�r att skriva ut
    char rad[40];
    // l�ser rad f�r rad i filen tills den blir NULL
    while (fgets(rad, sizeof(rad), fp)!=NULL){
        printf("%s", rad);
    }
}





