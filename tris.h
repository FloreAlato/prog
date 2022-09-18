//
// Created by dando on 09/09/2022.
//

#ifndef DAVIDE_FLORE_66174_TRIS_H
#define DAVIDE_FLORE_66174_TRIS_H

#endif //DAVIDE_FLORE_66174_TRIS_H


#include "black_jack.h"




int tris(Elenco *);
void print_table(char[3][3]);
void layout_tris(char[3][3], Elenco *, int);
void print_turn(Elenco *, int, char);









int tris(Elenco *coppia) {

    bool won = false;
    bool i = 0;
    bool ritenta = false;
    char scelta[4];
    char num1[2], num2[2];

    num1[1] = num2[1] = '\0';

    char table[3][3] = {
            '-', '-', '-',
            '-', '-', '-',
            '-', '-', '-'
    };


    do {
        // turno
        if(is_player(coppia[(int)i])) {
            layout_tris(table, coppia, (int)i);
            printf("\n[%s]: Inserisci le coordinate (esempio: 1,2)", game_name());

            ritenta = false;

            do {
                printf("\n[%s]: ", print_player(coppia[(int)i]));
                scanf(" %s", scelta);

                // controlla che la scelta sia valida
                num1[0] = scelta[0];
                num2[0] = scelta[2];

                if(is_numeric(num1) && is_numeric(num2) && scelta[1] == ',') {

                    // controlla che la casella sia libera

                    if(table[string_to_int(num1)][string_to_int(num2)] == '-') {

                        // aggiorna la tabella

                        table[string_to_int(num1)][string_to_int(num2)] = 'X';

                    } else {
                        layout_tris(table, coppia, (int)i);

                        printf("Questa casella e' gia' occupata!");

                        ritenta = true;
                    }

                } else {
                    layout_tris(table, coppia, (int)i);

                    printf("Format sbagliato!");

                    ritenta = true;
                }

            } while(ritenta == true);
        }

        // controlla eventuale vittoria


        // stampa


        i = !i;

    } while(won == false);


    return 0;
}






void print_table(char table[3][3]) {

    int c = 0;

    printf("\n\n");

    char table_image[2][15] = {
            " %c | %c | %c \0",
            "---|---|---\0"
    };

    for(int i = 0; i < 5; i++) {
        if(i % 2 == 0) {
            printf(table_image[0], table[c][0], table[c][1], table[c][2]);
            c++;
        } else {
            printf(table_image[1], "");
        }
        printf("\n");
    }
}





void layout_tris(char table[3][3], Elenco *giocatori, int turno) {

    int i, j;

    // 1 riga occupata
    printf("--------[STAI GIOCANDO A BLACKJACK]--------\n\n");

    // stampa tabella
    print_table(table);

    // linea primo giocatore
    print_turn(giocatori, turno, '_');

    if(turno == 0) {
        printf("\n|");
    } else {
        printf("\n");
    }
    printf(" %s | %s", print_player(giocatori[0]), print_player(giocatori[1]));
    if(turno == 1) {
        printf("|\n");
    } else {
        printf("\n");
    }

    print_turn(giocatori, turno, '-');


    printf("\n\n\n");
}




void print_turn(Elenco *giocatori, int turno, char spot) {
    //
    for(int i = 0; i < 2; i++) {
        //
        printf(" ");

        for(int j = 0; j <= strlen(print_player(giocatori[i])); j++) {
            //
            if(turno == i) {
                printf("%c", spot);
            } else {
                printf(" ");
            }
        }
    }


}



