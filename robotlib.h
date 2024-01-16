//
//  robotlib.h
//  labirinto
//
//  Created by Rosa Pia Esposito on 14/01/24.
//

#ifndef robotlib_h
#define robotlib_h

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    DOWN, UP, RIGHT, LEFT
} dir;

typedef struct {
    int i, j;
} coord;

//funzione per i muri esterni
//matrix: la matrice che rappresenta la stanza
void walls(char matrix[][16]);

//funzione per stampare una matrice
//matrix: la matrice che rappresenta la stanza
void printmatrix(char matrix[][16]);

//funzione per la stampa della stanza
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
void pretty_printmatrix(char matrix[][16], coord robot);

//funzione per pavimento interno
//matrix: la matrice che rappresenta la stanza
void floors(char matrix[][16]);

//funzione per muri interni prima versione
//matrix: la matrice che rappresenta la stanza
void iwalls(char matrix[][16]);

//funzione per muri interni seconda versione
void iwalls2(char matrix[][16]);

//funzione per muri interni terza versione
//matrix: la matrice che rappresenta la stanza
void iwalls3(char matrix[][16]);

//funzione per generare una porta
//matrix: la matrice che rappresenta la stanza
void door(char matrix[][16]);

//funzione per generare buchi neri e botole
//matrix: la matrice che rappresenza la stanza
//c: il tipo di oggetto che verrà generato
void items(char matrix[][16], char c);

//funzione per generare i buchi neri
//matrix: la matrice che rappresenta stanza
void black_hole(char matrix[][16]);

//funzione per generare le trappole
//matrix: la matrice che rappresenta la stanza
void traps(char matrix[][16]);

//funzione per la scelta delle modalità di gioco, l'unico fattore che cambia sono i muri interni
//matrix: la matrice che rappresenta la stanza
//x: carattere per la scelta
int levels(char matrix[][16], char *x);

//funzione per generare le coordinate del robot
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
void randcoords(char matrix[][16], coord *robot);

//funzione per la direzione del robot
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
//direction: la direzione
void movedirection(char matrix[][16], coord *robot, int direction);

//funzione per muovere randomicamente il robottino
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
void move30(char matrix[][16], coord *robot);

//funzione per calcolare la distanza del muro superiore più vicino
// matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
int view_up(char matrix[][16], coord robot);

//funzione per calcolare la distanza del muro inferiore più vicino
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
int view_down(char matrix[][16], coord robot);

//funzione per calcolare la distanza del muro più vicino a sinistra
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
//robot: le coordinate del robottino
int view_left(char matrix[][16], coord robot);

//funzione per calcolare la distanza del muro più vicino a destra
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
int view_right(char matrix[][16], coord robot);

//funzione per calcolare la distanza del muro in base alla direzione
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
//direction: la direzione
int get_distance(char matrix[][16], coord robot, int direction);

//algoritmo di ricerca del massimo per trovare il muro più lontano
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
int max_distance(char matrix[][16], coord robot);

//funzione per muovere il robottino verso il muro più lontano
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
void move70(char matrix[][16], coord *robot);

//funzione per i movimenti del robot
//matrix: la matrice che rappresenta la stanza
//robot: le coordiate del robottino
void moves(char matrix[][16], coord *robot);

//funzione per determinare se si è verifica la condizione di game over
//matrix: la matrice che rappresenta la stanza
//robot: le coordinate del robottino
int game_over(char matrix[][16], coord robot);


#endif /* robotlib_h */
