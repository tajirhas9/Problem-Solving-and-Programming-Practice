#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vl;
void display(vl v);
bool check(vl v);
bool displayMenu();
int main()
{
    int x,moves=0,session=true;
    vl v;
    while(session)
    {
        bool end = false,first=true,firstWin=false,secWin=false;
        v.clear();
        moves=0;
        for(int i=0; i<9; i++) v.emplace_back(i+1+'0');
        session = displayMenu();
        if(!session)
        {
            cout << "exited...\n";
            continue;
        }
        //game starts
        while(!end && ++moves)
        {
            cout << "\033[2J\033[1;1H";
            display(v);
again:      if(first)	cout << "Player 1 turn: ";
            else 		cout << "Player 2 turn: ";
            cin >> x;
            if(v[x-1]=='O' || v[x-1]=='X')
            {
				printf("Already occupied.Try another box... :(\n\a");
				goto again;
			}
			else if(x==0)
			{
				printf("Please enter value between 1 and 9\n\a");
				goto again;
			}
            if(first)
            {
                v[x-1] = 'O';
                first = false;
            }
            else
            {
                v[x-1] = 'X';
                first = true;
            }
            if(check(v))
            {
                if(first)
                    secWin = true;
                else
                    firstWin = true;
                break;
            }
            if(moves==9)	end = true;
        }
        if(end)
        {
            cout << "Draw\a" << endl;
        }
        else
        {
            cout << "\033[2J\033[1;1H";
            display(v);
            if(firstWin)	cout << "\n\nWinner : Player 1\a" << endl;
            else if(secWin)	cout << "\n\nWinner : Player 2\a" << endl;
            cout << "Congratulations!!!" << endl;
        }
        char ss;
        cout << "Press any key and hit enter to return to main menu.\n";
        cin >> ss;
    }
    return 0;
}
void display(vl v)
{
    int x=0;
    cout << "Enter the box number and hit enter to make a move";
    cout << endl << endl;
    for(int i=0; i<3; i++)
    {
		cout << "\t\t\t";
        for(int j=0; j<3; j++,x++)
        {
            cout << "   " << v[x] << "  |";
        }
        cout << endl;
        if(i<2)
        {   
			cout << "\t\t\t";
			for(int j=0; j<25; j++)
            {
                if(j%6==0 && j!=0 && j!=24)	cout << "|-";
                else cout << "-";
            }
            cout << endl;
        }
    }
    cout << endl << endl;
}
bool check(vl v)
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
            //cout << "row\n";
            return true;
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
            //cout << "coloumn\n";
            return true;
        }
    }
    //diagonals
    if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) || (a[2][0]==a[1][1] && a[1][1]==a[0][2]))
    {
        //cout << "diagonals\n";
        return true;
    }
    return false;
}
bool displayMenu()
{
    char ss;
    bool invalid = false;
    while(1)
    {
        cout << "\033[2J\033[1;1H";
        if(invalid)
            cout << "Invalid Command.Please try again...\n\n\a";
        \
        cout << "1.Play\n";
        cout << "2.Exit\n\n";
        cout << "Press 'p' to play or 'e' to exit the game.\n";
        cin >> ss;
        if(ss=='e' || ss=='E')	return false;
        if(ss== 'p' || ss=='P') return true;
        else
        {
            invalid = true;
        }
    }
}
