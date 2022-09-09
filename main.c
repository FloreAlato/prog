#include "black_jack.h"



void scrematura(Elenco *, int);
void svolgimento(Elenco *, int);
void finale(Elenco *);




int main() {


    srand(time(NULL));


    ProfiloGiocatore giovanni = {
            13,
            "Giovanni Maranza",
            0,
            0,
            0,
            0,
            0
    };


    Elenco fine[2] = {
            {
                0,
                true,
                &giovanni
            },
            {
                13,
                true,
                NULL
            }
    };


    getchar();
    int d = black_jack(fine);
    getchar();


    // scrematura




    // svolgimento




    // finale



    return 0;
}



