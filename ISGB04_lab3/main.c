#include <stdio.h>
#include <stdlib.h>
#include "minaFunktioner.h"
#include <time.h>


int main(int argc, const char * argv[]){
    srand(time(NULL));
    int val;
    FILE *fp;

    while(1){
        printf("\nSlumpa lottorader [1]\nVisa sparade lottorader [2]\n");
        scanf("%i", &val);
        printf("\n");

        switch(val){

        case 1:{

            printf("Hur många rader vill du slumpa?\n");
            int antal;
            scanf("%i", &antal);
            printf("\n");

            int lottorader[antal][7]; // array för att lagra alla genererade rader

            for(int i = 0; i < antal; i++){
                lottoGenerator(lottorader[i]);
                for(int j = 0; j < 7; j++){
                    //skriver ut från den aktiva raden samt den aktuella positionen
                    printf("%i ", lottorader[i][j]);
                }
                printf("\n");


            }
            while(1){
                printf("\nSpara? [ja/nej]\n");
                char svar[4];
                scanf("%s", svar);

                if(strncmp(svar, "ja", 2) == 0){

                    fp = openFil("lottorader.txt", "w");
                    if(fp != NULL){
                        skriv(fp, lottorader, antal);
                        fclose(fp);
                        printf("\nsparad\n");
                    }
                    break;
                }
                if(strncmp(svar, "nej", 3) == 0){
                    // bryter while, återgår till föregående while-loop
                    break;
                }
                else{
                    // vid ogiltig inmatning, återgår till start av aktuell while-loop
                    printf("ogiltigt svar\n");
                }
            }
        }
        break;


        case 2:
            fp = openFil("lottorader.txt", "r");
            if(fp != NULL){
                lasFil(fp);
                fclose(fp);
                printf("\n");
            }
            else{
                break;
            }
            break;
        }
    }
    return 0;
}
