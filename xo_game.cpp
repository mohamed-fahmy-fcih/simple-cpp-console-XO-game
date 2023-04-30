#include <iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

int check();
void game();
int check()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    else if (board[4] == board[5] && board[5] == board[6])
        return 1;
    else if (board[7] == board[8] && board[8] == board[9])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[3] == board[6] && board[6] == board[9])
        return 1;
    else if (board[1] == board[5] && board[5] == board[9])
        return 1;
    else if (board[3] == board[5] && board[5] == board[7])
        return 1;
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3'
                    && board[4] != '4' && board[5] != '5' && board[6] != '6'
                  && board[7] != '7' && board[8] != '8' && board[9] != '9')
        return 0;
    else
        return -1;
}
int main()
{
	int player = 1,i,pos;
    char shape;
    do
    {
        game();
        player=(player%2)?1:2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> pos;
        shape=(player == 1) ? 'X' : 'O';
        if (pos == 1 && board[1] == '1')
            board[1] = shape;
        else if (pos == 2 && board[2] == '2')
            board[2] = shape;
        else if (pos == 3 && board[3] == '3')
            board[3] = shape;
        else if (pos == 4 && board[4] == '4')
            board[4] = shape;
        else if (pos == 5 && board[5] == '5')
            board[5] = shape;
        else if (pos == 6 && board[6] == '6')
            board[6] = shape;
        else if (pos == 7 && board[7] == '7')
            board[7] = shape;
        else if (pos == 8 && board[8] == '8')
            board[8] = shape;
        else if (pos == 9 && board[9] == '9')
            board[9] = shape;
        else
        {
            cout<<"Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i=check();
        player++;
    }while(i==-1);
    game();
    if(i==1)
        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";
    cin.ignore();
    cin.get();
    return 0;
}


void game()
{
    system("cls");
    cout << endl<< endl <<"welcome to XO game"<< endl<< endl;
    cout << "Player 1 :X Player 2 :O" << endl << endl;
    cout << endl;
    cout << "  " << board[1] << "   " << board[2] << "   " << board[3] << endl;
    cout << "  " << board[4] << "   " << board[5] << "   " << board[6] << endl;
    cout << "  " << board[7] << "   " << board[8] << "   " << board[9] << endl;
}
