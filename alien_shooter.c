#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <pthread.h>
#include "assests/src/player.h"
#include "assests/src/border.h"


#define N 35
#define M 65




void Menu(){
    //Welcoming messsage
    printf("\t\t\t\t\t\tWELCOME TO ALIEN SHOOTER\n");
    printf("\n\n\n\n");

    //Choice choosing
    printf("Enter any of the choices: \n");

    //Menu
    printf("\t1) Play the Game!\n");
    printf("\t2) Credits!\n");
    printf("\t3) Exit :(\n");

    //choosing
    printf("\n\n\nEnter Your Choice: ");

    int choice;
    scanf("%d",&choice);

    while (choice<=0 || choice>=4){

        scanf("%d",&choice);

        printf("Enter a number from the existing numbers: ");

    }  

    if (choice == 1){
        //play

        system("cls");

        char **border = Border();
        

        player p = Create_player();
        Place_Player(border,p);

        display_borer(border);

        char user_input;

        do{
            
            

            user_input = getch();
            system("cls");

            if (user_input == 'w' || user_input == 'a' || user_input == 's' || user_input == 'd'){
                Move_Player(user_input,border,&p);
            }
            else if (user_input == ' '){
                Shoot_fire(border,p);
            }
            
            display_borer(border);
        } while (user_input != 'e');

        getchar();
    }

    else if (choice == 2){
        //credits
    }

    else
        exit(0);
}






int main(){

    Menu();

    getch();


    return 0;
}