#include <stdio.h>
#define true 1
#define false 0
void display(int v[]);
int check(int v[]);
int displayMenu();
int main()
{
    int x,moves=0,session=true;
    int v[10];
    while(session)
    {
        int end = 0,first=1,firstWin=0,secWin=0;
        moves=0;
        for(int i=0; i<9; i++) v[i] = i+1+'0';
        session = displayMenu();
        if(!session)
        {
            printf("exited...\n");
            continue;
        }
        //game starts
        while(!end && ++moves)
        {
            printf("\033[2J\033[1;1H");
            display(v);
again:      if(first)	printf("Player 1 turn: ");
            else 		printf("Player 2 turn: ");
			scanf("%d",&x);
            if(v[x-1]=='O' || v[x-1]=='X')
            {
				printf("Already occupied.Try another box... :(\n\a");
				goto again;
			}
			else if(x<=0 || x>9)
			{
				printf("Please enter value between 1 and 9\n\a");
				goto again;
			}
            if(first)
            {
                v[x-1] = 'O';
                first = 0;
            }
            else
            {
                v[x-1] = 'X';
                first = 1;
            }
            if(check(v))
            {
                if(first)
                    secWin = 1;
                else
                    firstWin = 1;
                break;
            }
            if(moves==9)	end = 1;
        }
        if(end)
        {
            printf("Draw\a\n");
        }
        else
        {
            printf("\033[2J\033[1;1H");
            display(v);
            if(firstWin)	printf("\n\nWinner : Player 1\a\n");
            else if(secWin)	printf("\n\nWinner : Player 2\a\n");
            printf("Congratulations!!!\n");
        }
        char ss;
        printf("Press any key and hit enter to return to main menu.\n");
        scanf(" %c",&ss);
    }
    return 0;
}
void display(int v[])
{
    int x=0;
    printf("Enter the box number and hit enter to make a move");
    printf("\n\n");
    for(int i=0; i<3; i++)
    {
        printf("\t\t\t");
        for(int j=0; j<3; j++,x++)
        {
            printf("   %c  |",v[x]);
        }
        printf("\n");
        if(i<2)
        {
            printf("\t\t\t");
            for(int j=0; j<25; j++)
            {
                if(j%6==0 && j!=0 && j!=24)	printf("|-");
                else printf("-");
            }
            printf("\n");
        }
    }
    printf("\n\n");
}
int check(int v[])
{
    int i,j,x=0;
    char a[4][4];
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++,x++)
            a[i][j] = v[x];
    }
    //row
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            if(a[i][j] != a[i][j+1])	break;
        }
        if(j==2)
        {
            //printf("row\n";
            return 1;
        }
    }
    //coloumn
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            if(a[j][i] != a[j+1][i])	break;
        }
        if(j==2)
        {
            //printf("coloumn\n";
            return true;
        }
    }
    //diagonals
    if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) || (a[2][0]==a[1][1] && a[1][1]==a[0][2]))
    {
        //printf("diagonals\n";
        return true;
    }
    return false;
}
int displayMenu()
{
    char ss;
    int invalid = false;
    while(1)
    {
        printf("\033[2J\033[1;1H");
        if(invalid)
            printf("Invalid Command.Please try again...\n\n\a");
        printf("1.Play\n");
        printf("2.Exit\n\n");
        printf("Press 'p' to play or 'e' to exit the game.\n");
        scanf("%c",&ss);
        if(ss=='e' || ss=='E')	return false;
        if(ss== 'p' || ss=='P') return true;
        else
        {
            invalid = true;
        }
    }
}

