#include "../src/border.h"
#include <stdio.h>
#include <stdlib.h>


#define N 35
#define M 65


//create the border of the game
char ** Border(){
    char ** border;

    border = (char **)malloc(N * sizeof(char *));

    for (int i=0;i<N;i++){
        border[i] = (char *)malloc(M * sizeof(char));
        border[i][M] = '\0';
    }
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if ( i==0 || i==N-1 )
                border[i][j] = '#';
            else if ( j==0 || j==M-1 )
                border[i][j] = '#';
            else    
                border[i][j] = ' ';
        }
    }

    return border;
}



void display_borer(char **border){
    for (int i=0;i<N;i++)
        puts(border[i]);
}
