//
//  robotlib.c
//  labirinto
//
//  Created by Rosa Pia Esposito on 14/01/24.
//


#include "robotlib.h"


//funzione per muri esterni
void walls(char matrix[][16]){
    for(int i = 0; i < 16; i++) {
        matrix[0][i] = 'x';
        matrix[15][i] = 'x';
        matrix[i][0] = 'x';
        matrix[i][15] = 'x';
    }
}

//funzione per stampare una matrice
void printmatrix(char matrix[][16]){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            printf("[%c]", matrix[i][j]);
        }
        printf("\n");
    }
}

//funzione per la stampa della stanza
void pretty_printmatrix(char matrix[][16], coord robot){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if (i == robot.i && j == robot.j){
                printf(" & ");
            }
            
            else if (matrix[i][j] == 'o'){
                printf("   ");
            }
            
            else {
                printf(" %c ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

//funzione per pavimento intero
void floors(char matrix[][16]){
    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            matrix[i][j] = 'o';
        }
        
    }
}

//funzione per muri interni
void iwalls(char matrix[][16]){
    for(int i = 1; i < 9; i++){
        matrix[i][3] = 'x';
    }
    for(int i = 7; i < 15; i++){
        matrix[4][i] = 'x';
    }
    for(int i = 8; i < 15; i++){
        matrix[i][7] = 'x';
    }
    for(int i = 11; i < 14 ; i++){
        matrix[10][i] = 'x';
    }
}

//funzione per muri interni ver 2
void iwalls2(char matrix[][16]){
    for(int i = 3; i < 7; i++){
        matrix[i][5] = 'x';
    }
    for(int i = 5; i < 12; i++){
        matrix[i][9] = 'x';
    }
    for(int i = 6; i < 14; i++){
        matrix[8][i] = 'x';
    }
}

//funzione per muri interno ver 3
void iwalls3(char matrix[][16]){
    for(int i = 6; i < 16; i++){
        matrix[i][10] = 'x';
    }
    for(int i = 4; i < 15; i++){
        matrix[i][3] = 'x';
    }
    for(int i = 1; i < 9; i++){
        matrix[i][6] = 'x';
    }
    for(int i = 1; i < 12; i++){
        matrix[i][13] = 'x';
    }
    
}

//funzione per generare una porta
void door(char matrix[][16]){
    matrix[11][0] = 'd';
    matrix[12][0] = 'd';
    matrix[13][0] = 'd';
}

//funzione per generare buchi neri e botole
void items(char matrix[][16], char c){
    int i, j, k = 0;
    while (k < 5) {
        i = rand()%16;
        j = rand()%16;
        if (matrix[i][j] == 'o'){
            matrix[i][j] = c;
            k++;
        }
    }
}

void black_hole(char matrix[][16]){
    items(matrix, 'b');
}

void traps(char matrix[][16]){
    items(matrix, 't');
}

//scelta della modalità di gioco, l'unico fattore che cambia sono i muri interni
int levels(char matrix[][16], char *x){
    printf("scegliere la modalità di gioco: easy, hard o nightmare (inserire solo l'iniziale)\n");
    scanf("%c", x);
    fflush(stdin);
    switch (*x) {
        case 'e' : iwalls(matrix);
            return 1;
            break;
        case 'h' : iwalls2(matrix);
            return 1;
            break;
        case 'n' : iwalls3(matrix);
            return 1;
            break;
        default : printf("errore nell'inserimento\n");
            return 0;
    }
}

//funzione per generare le coordinate del robot
void randcoords(char matrix[][16], coord *robot){
    int i, j, ok = 0;
    while (! ok) {
        i = rand()%16;
        j = rand()%16;
        if (matrix[i][j] == 'o'){
            robot -> i = i;
            robot -> j = j;
            ok = 1;
        }
    }
}

void movedirection(char matrix[][16], coord *robot, int direction){
    switch (direction) {
        case DOWN :
            if (matrix[robot->i+1][robot->j] != 'x') robot -> i++;
            break;
        case UP :
            if (matrix[robot->i-1][robot->j] != 'x') robot -> i--;
            break;
        case RIGHT :
            if (matrix[robot->i][robot->j+1] != 'x') robot -> j++;
            break;
        case LEFT :
            if (matrix[robot->i][robot->j-1] != 'x') robot -> j--;
            break;
        default : break;
    }
}
    
void move30(char matrix[][16], coord *robot){
    int direction = rand()%4;
    //printf("move30: direction %d\n", direction);
    movedirection(matrix, robot, direction);
}

int view_up(char matrix[][16], coord robot){
    int distance = -1;
    for(int i = robot.i; i > 0; i--){
        distance++;
        if(matrix[i][robot.j] == 'x' || matrix[i][robot.i] == 'd'){
            return distance;
        }
    }
    return distance;
}

int view_down(char matrix[][16], coord robot){
    int distance = -1;
    for(int i = robot.i; i < 16; i++){
        distance++;
        if(matrix[i][robot.j] == 'x' || matrix[i][robot.j] == 'd'){
            return distance;
        }
    }
    return distance;
}

int view_left(char matrix[][16], coord robot){
    int distance = -1;
    for(int j = robot.j; j > 0; j--){
        distance++;
        if(matrix[robot.i][j] == 'x' || matrix[robot.i][j] == 'd'){
            return distance;
        }
    }
    return distance;
}

int view_right(char matrix[][16], coord robot){
    int distance = -1;
    for(int j = robot.j; j < 16; j++){
        distance++;
        if(matrix[robot.i][j] == 'x' || matrix[robot.i][j] == 'd'){
            return distance;
        }
    }
    return distance;
}

int get_distance(char matrix[][16], coord robot, int direction){
    switch (direction){
        case UP :
            return view_up(matrix, robot);
            break;
        case DOWN :
            return view_down(matrix, robot);
            break;
        case LEFT:
            return view_left(matrix, robot);
            break;
        case RIGHT :
            return view_right(matrix, robot);
            break;
        default :
            return -1;
            break;
    }
}

int max_distance(char matrix[][16], coord robot){
    int max = 0;
    int direction = 0;
    for(int curdir = 0; curdir < 4; curdir++){
        int curdist = get_distance(matrix, robot, curdir);
        if(curdist >= max){
            max = curdist;
            direction = curdir;
        }
    }
    return direction;
}

void move70(char matrix[][16], coord *robot){
    int direction = max_distance(matrix, *robot);
    //printf("move70: direzione %d\n", direction);
    movedirection(matrix, robot, direction);
}

//funzione per i movimenti del robot
void moves(char matrix[][16], coord *robot){
    int prob = rand()%100;
    if (prob < 30) {
        move30(matrix, robot);
    }
    else {
        move70(matrix, robot);
    }
}

int game_over(char matrix[][16], coord robot){
    if(matrix[robot.i][robot.j] == 'd' || matrix[robot.i][robot.j] == 'b'){
        return 1;
    }
    else {
        return 0;
    }
}
