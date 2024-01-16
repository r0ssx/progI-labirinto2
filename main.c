//
//  main.c
//  labirinto
//
//  Created by Rosa Pia Esposito on 09/01/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "robotlib.h"

int main(void) {
    srand((int)time(0));    
    char matrix[16][16];
    walls(matrix);
    floors(matrix);
    char x;
    do {} while(levels(matrix, &x) != 1);
    door(matrix);
    black_hole(matrix);
    traps(matrix);
    coord robot = {-1, -1};
    randcoords(matrix, &robot);
    pretty_printmatrix(matrix, robot);
    char in;
    do {
        printf("premi invio per muoverti: ");
        scanf("%c", &in);
        fflush(stdin);
        moves(matrix, &robot);
        pretty_printmatrix(matrix, robot);
        if (matrix[robot.i][robot.j] == 't') {
            randcoords(matrix, &robot);
            printf("teletrasporto!\n");
            pretty_printmatrix(matrix, robot);
        }
    }
    while (!game_over(matrix, robot));
    
    return 0;
}
