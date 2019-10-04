#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char arr[9]={'1','2','3','4','5','6','7','8','9'};
char c1,c2;
int player=1;
int checkResult()
{
    if (arr[0] == arr[1] && arr[1] == arr[2])
        return 1;

    else if (arr[3] == arr[4] && arr[4] == arr[5])
        return 1;

    else if (arr[6] == arr[7] && arr[7] == arr[8])
        return 1;

    else if (arr[0] == arr[3] && arr[3] == arr[6])
        return 1;

    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;

    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;

    else if (arr[0] == arr[4] && arr[4] == arr[8])
        return 1;

    else if (arr[2] == arr[4] && arr[4] == arr[6])
        return 1;

    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' &&
        arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6]
        != '7' && arr[7] != '8' && arr[8] != '9')

        return 0;
    else
        return  - 1;
}
void gameBoard()
{
    system("cls");
    int i,j;
    printf("\n\n---------- TIC TAC TOE---------------\n\n");
    printf(" Player 1 : %c and Player 2 : %c \n\n",c1,c2);
    printf("\n");
    for(i=0;i<9;i=i+3)
    {
        printf("                       ");
        for(j=i;j<(i+3);j++)
        {
            printf(" %c ",arr[j]);
            if(j!=(i+3)-1)
                printf("|");
        }
        if(j!=9)
        printf("\n                       ");
        if(i!=6)
            printf("--- --- --- \n");
    }
}
int main()
{
    char wish='s';
    while(wish=='s')
    {
    system("cls");
    char n;
    int j=0;
    for(n='1';n<='9';n++)
    {
        arr[j]=n;
        j++;
    }
    player=1;
    printf("\nChoices for players : 0/X\n");
    printf("\nPlayer 1 enter ur choice : \n");
    scanf("%c",&c1);
    while(!(c1=='X') && !(c1=='0'))
    {
        printf("enter a valid choice : ");
        fflush(stdin);
        scanf("%c",&c1);
    }
    if(c1=='X')
        c2='0';
    else
        c2='X';
    int i=-1;
    char ch;
    char val;
    while(i==-1)
    {
        __label__ l;
        gameBoard();
        val=(player==1)?c1:c2;
        printf("\n\nPlayer %d enter choice : ",player);
        l:
            fflush(stdin);
        scanf("%c",&ch);

        if(ch=='1' && arr[0]=='1')
            arr[0]=val;
        else if(ch=='2' && arr[1]=='2')
            arr[1]=val;
        else if(ch=='3' && arr[2]=='3')
            arr[2]=val;
        else if(ch=='4' && arr[3]=='4')
            arr[3]=val;
        else if(ch=='5' && arr[4]=='5')
            arr[4]=val;
        else if(ch=='6' && arr[5]=='6')
            arr[5]=val;
        else if(ch=='7' && arr[6]=='7')
            arr[6]=val;
        else if(ch=='8' && arr[7]=='8')
            arr[7]=val;
        else if(ch=='9' && arr[8]=='9')
            arr[8]=val;
        else
        {
            if(!(ch>='1' && ch<='9'))
                printf("invalid choice!!! ");
            else
                printf("already filled!!! ");
            printf("Player %d enter again : ",player);
                goto l;
        }
        i=checkResult();
        if(player==1)
            player=2;
        else
            player=1;
    }
    gameBoard();
    printf("\n\n");
    if(i==1)
        if(player==1)
        printf("Player 2 won :) Congratulations!!!\n");
        else
        printf("Player 1 won :) Congratulations!!!\n");
    else
        printf("Match draws!!! :( \n");
    printf("DO you wanna play again? . if yes Press S or s , if no press any other key to exit \n");
    fflush(stdin);
    scanf("%c",&wish);
    fflush(stdin);
    }
    return 0;
}
