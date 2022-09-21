//
// Created by dando on 21/09/2022.
//

#ifndef DAVIDE_FLORE_66174_MURRA_H
#define DAVIDE_FLORE_66174_MURRA_H

#endif //DAVIDE_FLORE_66174_MURRA_H


#include "tris.h"


int murra(Elenco *);
void layout_murra(Elenco *, int);






int murra(Elenco *giocatori) {

    int i;

    int scelta[2];
    int somma[2];

    do {
        // turni
        for(i = 0; i < 2; i++) {

            layout_murra(&giocatori[0], i);

            if(is_player(giocatori[i])) {
                printf("[%s]: Inserisci il numero di dita che vuoi buttare e un pronostico della somma", game_name());
                printf("[%s]: Dita:\n[%s]: ", game_name(), print_player(giocatori[i]));
                scelta[i] = get_int("", 1, 5);
                getchar();

                printf("[%s]: Somma:\n[%s]: ", game_name(), print_player(giocatori[i]));
                somma[i] = get_int("", 2, 10);
                getchar();
            } else {

                // numeri del computer
                // la somma è sempre maggiore di o uguale al numero
                scelta[i] = rand_int(1, 5);
                somma[i] = rand_int(scelta[i], 10);

                printf("[%s]: Inserisci il numero che vuoi buttare e la somma", game_name());
                printf("[%s]: Butto %d dita e %d come somma!", print_player(giocatori[i]), scelta[i], somma[i]);
                getchar();
            }
        }

        // controlla pareggio
        if(somma[0] == somma[1] == scelta[0] + scelta[1]) {
            // stampa layout pareggio

            printf("[%s]: Sembra che la partita si sia conclusa in pareggio! Riproviamo!", game_name());
            getchar();
        } else if(somma[0] == scelta[0] + scelta[1]) {
            // stampa layout vittoria primo giocatore
            getchar();

            return 0;
        } else if(somma[1] == scelta[0] + scelta[1]) {
            // stampa layout vittoria secondo giocatore
            getchar();

            return 1;
        } else {
            // stampa layout fiasco

            printf("[%s]: Nessuno dei due ha avuto fortuna! Riproviamo!", game_name());
            getchar();
        }


    } while(true);
}







void layout_murra(Elenco *giocatori, int turno) {

    // 3 righe occupate
    printf("--------[STAI GIOCANDO A MURRA]--------\n\n");

    // stampa le mani


    // 5 righe occupate
    if(turno >= 2) {
        //
        
    } else {
        stampa_turno(&giocatori[0], 2, turno);
    }

}
