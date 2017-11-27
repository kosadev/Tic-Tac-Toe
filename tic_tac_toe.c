#include <stdio.h>
#include <stdlib.h>
#include <conio.h >
#include <stdbool.h>
#include <time.h>



void draw_board(char *board);
void fill_board_with_space(char *board);
bool check(char *board);
void menu();
void interface(char *board, int player);
void two_players_game(char *board);
void single_player_game(char *board);
void computers_move(char *board);

int main()
{
    menu();

    char play_bg[3][3];


    int selection;
    scanf("%i", &selection);

    switch(selection)
    {
    case 1:
        two_players_game(play_bg);
        break;
    case 2:
        single_player_game(play_bg);
        break;
    case 0:
        break;
    }



    return 0;
}


void two_players_game(char *board)
{
    fill_board_with_space(board);

    printf("\nNow board is empty\n\n");

    int round=1;
    int player=0;
    bool result;
    while(round<=5)
    {

        draw_board(board);
        printf("\nIt's round nr %i", round);
        (player==0) ? printf("\nTurn of player A") : printf("\nTurn of player B");


        interface(board, player);
        result=check(board);
        if(round>=3 && result==true)
        {
           draw_board(board);
           (player==0) ? printf("\nPlayer nr A") : printf("\nPlayer nr B");
           printf(" WON!!!");
           break;
        }

        if(player==1) round++;
        (player==0) ? player++: player--;

    }

    if(result==0) printf("DRAW :o");

}


void single_player_game(char *board)
{
    fill_board_with_space(board);

    printf("\nNow board is empty\n\n");

    int round=1;
    int player=0;
    bool result;
    while(round<=5)
    {

        draw_board(board);
        printf("\nIt's round nr %i", round);
        (player==0) ? printf("\nYour turn") : printf("\nComputer turn");



        (player==0) ? interface(board, player) : computers_move(board);
        result=check(board);
        if(round>=3 && result==true)
        {
           draw_board(board);
           (player==0) ? printf("\nPlayer nr A") : printf("\nComputer");
           printf(" WON!!!");
           break;
        }

        if(player==1) round++;
        (player==0) ? player++: player--;

    }

    if(result==0) printf("DRAW :o");
}

void menu()
{
    printf("Hi! Welcome to my Tic Tac Toe game!\n");
    printf("1. Play with your buddy [Insert 1]\n");
    printf("2. Play with AI [Insert 2]\n");
    printf("0. Exit [Insert 0]\n");
}


void interface(char *board, int player)
{
    int i;
    int j;
    int condition=0;
    while(condition==0)
    {
      printf("\nInsert row number ");
      scanf("%i", &i);
      printf("\nInsert column number ");
      scanf("%i", &j);

      if(*((board+i*3) + j)=='X' || *((board+i*3) + j)=='O' || i>2 || j>2)
      {
          printf("\nError... Insert coordinates again...");
      }else condition = 1;

    }

    if(player==0) *((board+i*3) + j)='X';
    else *((board+i*3) + j)='O';

}

void computers_move(char *board)
{
    srand( time( NULL ) );

    int i;
    int j;
    int condition=0;
    while(condition==0)
    {
      i=rand()%3;
      j=rand()%3;

      if(*((board+i*3) + j)!='X' && *((board+i*3) + j)!='O')
      {
         condition = 1;
      }

    }
    *((board+i*3) + j)='O';

}


void draw_board(char *board)
{
    system("cls");
    int i;
    int j;
    for(i=0; i<3; i++)
    {
        printf("|");
        for(j=0;j<3; j++) printf("%c|", *((board+i*3) + j));
        printf("\n");
    }
}

void fill_board_with_space(char *board)
{
    int i;
    int j;
    for(i=0; i<3; i++)
    {
        for(j=0;j<3; j++) *((board+i*3) + j)=' ';
    }
}

bool check(char *board)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(*((board+i*3))=='X' &&*((board+i*3) + 1)=='X' && *((board+i*3) + 2)=='X') return true;
        if(*((board+i*3))=='O' &&*((board+i*3) + 1)=='O' && *((board+i*3) + 2)=='O') return true;
    }

    for(i=0; i<3; i++)
    {
        if(*((board) + i)=='X' && *((board+1*3) + i)=='X' && *((board+2*3) + i)=='X') return true;
        if(*((board) + i)=='O' && *((board+1*3) + i)=='O' && *((board+2*3) + i)=='O') return true;
    }

   if(*board=='X' && *((board+3) + 1)=='X' && *((board+6) + 2)=='X') return true;
   if(*board=='O' && *((board+3) + 1)=='O' && *((board+6) + 2)=='O') return true;

   if(*(board+2)=='X' && *((board+3) + 1)=='X' && *(board+6 )=='X') return true; 
   if(*(board+2)=='O' && *((board+3) + 1)=='O' && *(board+6 )=='O') return true; 

    return false;
}
