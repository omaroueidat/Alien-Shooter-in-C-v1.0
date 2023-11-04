#include "../src/player.h"
#include "../src/border.h"
#include <windows.h>


#define N 35
#define M 65

/*
player is defined as a 1d array of coordinates, then there is a function that will take the 1d array of coordinates
and transform it onto 2d on the border

from i=0 to i=2 it will be the 3 #'s on the top
from i=3 to i=7 it will be the 5 #'s below the top
from i=8 to i=14 it will be the 7 #'s below the upward line
from i=15 to i=18 it will be the 0's representing the fire from the ship

*/


//method for creating a player
player Create_player(){
    player p;
    p.power = 0;
    p.score = 0;

    for (int i=0;i<19;i++){
        if (i==0){
            p.indecies[i].x = M/2 - 1;
            p.indecies[i].y = N - 8;
        }
        else if (i==1 || i==2){
            p.indecies[i].x = p.indecies[i-1].x + 1;
            p.indecies[i].y = p.indecies[i-1].y;
        }
        else if (i==3){
            p.indecies[i].x = p.indecies[0].x - 1;
            p.indecies[i].y = p.indecies[0].y + 1;
        }
        else if (i==4 || i==5 || i==6 || i==7){
            p.indecies[i].x = p.indecies[i-1].x + 1;
            p.indecies[i].y = p.indecies[i-1].y;
        }
        else if (i==8){
            p.indecies[i].x = p.indecies[3].x - 1;
            p.indecies[i].y = p.indecies[3].y + 1;
        }
        else if (i==9 || i==10 || i==11 || i==12 || i==13 || i==14){
            p.indecies[i].x = p.indecies[i-1].x + 1;
            p.indecies[i].y = p.indecies[i-1].y;            
        }
        else if (i==15){
            p.indecies[i].x = p.indecies[8].x;
            p.indecies[i].y = p.indecies[8].y + 1;
        }
        else if (i==17){
            p.indecies[i].x = p.indecies[15].x;
            p.indecies[i].y = p.indecies[15].y + 1;
        }
        else if (i==16){
            p.indecies[i].x = p.indecies[14].x;
            p.indecies[i].y = p.indecies[14].y + 1;
        }
        else if (i==18){
            p.indecies[i].x = p.indecies[16].x;
            p.indecies[i].y = p.indecies[16].y + 1;
        }
    }

    return p;
}



//method to place the player on the board
void Place_Player(char ** border, player p){
    for (int i=0;i<19;i++){
        if (i<=14){
            border[p.indecies[i].y][p.indecies[i].x] = '#';
        }
        else{
            border[p.indecies[i].y][p.indecies[i].x] = '0';
        }
    }
}

//this method to remove the player from the border
void Remove_Player(char ** border, player p){
    for (int i=0;i<19;i++){
        border[p.indecies[i].y][p.indecies[i].x] = ' ';
    }
}

//move the player up
void Move_Up(player *p){
    for (int i=0;i<19;i++){
        p->indecies[i].y--;
    }
}

//move the player down
void Move_Down(player *p){
    for (int i=0;i<19;i++){
        p->indecies[i].y++;
    }
}

//move the player to the right
void Move_Right(player *p){
    for (int i=0;i<19;i++){
        p->indecies[i].x++;
    }
}

//move the player to the left
void Move_Left(player *p){
    for (int i=0;i<19;i++){
        p->indecies[i].x--;
    }
}


//this method is to shoot fire from the ship
void *Shoot_fire (char **border, player p){

    point center; 
    center.x = p.indecies[1].x;
    center.y = p.indecies[1].y;

    for (;center.y != 1;){
        border[--center.y][center.x] = '*';
        system("cls");
        Place_Player(border , p);
        if (center.y != 1)
            display_borer(border);
        Sleep(30);
        border[center.y][center.x] = ' ';
    }

}


//method to move the player
void *Move_Player(char user_input, char **border, player *p){

    int flag = 1;

    if (p->indecies[18].y == N-2 && user_input == 's')
        flag = 0;
    else if (p->indecies[0].y == 1 && user_input == 'w')
        flag = 0;
    else if (p->indecies[18].x == M-2 && user_input == 'd')
        flag = 0;
    else if (p->indecies[8].x == 1 && user_input == 'a')
        flag = 0;


    if (flag == 1){
    Remove_Player(border,*p);

    if (user_input == 'w')
        Move_Up(p);
    else if (user_input == 's')
        Move_Down(p);
    else if (user_input == 'a')
        Move_Left(p);
    else if (user_input == 'd')
        Move_Right(p);

    Place_Player(border,*p);
    }

}


