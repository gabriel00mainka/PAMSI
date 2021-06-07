#include <iostream>
#include "game.hh"

using namespace std;



int main()
{
    char** board; 
    int x = 0;
    int y = 0;
    int n = 0;
    int max = 0;
    bool gamer_result = false;
    bool computer_result = false;
    bool draw_result = false;

    cout << "Podaj liczbe wierszy planszy: ";
    cin >> n;

    cout << "Podaj liczbe znakow do zwyciestwa: ";
    cin >> max;

    board = new char* [n];

    for(int i=0;i<n;i++)
        board[i] = new char [n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j] = ' ';

    system("clear");

    cout << endl << endl;
    cout << "=========================" << endl;
    cout << "   GRA KOLKO I KRZYZYK" << endl << endl;
    cout << "   GRACZ = X" << endl << "   KOMPUTER = O" << endl;
    cout << "=========================" << endl;
    draw_board(board,n);

    

//===================================================================
    while(1)
    {
        do
        {
            cout << endl;
            cout << "Podaj indeksy pola(wiersz_kolumna) (np. 1 2): ";
            cin >> x >> y;
        } while (x < 0 || x > n || y < 0 || y > n || board[x-1][y-1] == 'X' || board[x-1][y-1] == 'O');

        board[x-1][y-1] = 'X';
        system("clear");
        draw_board(board,n);

        if(win(board,n,max,'X'))
        {
            gamer_result = true;
            break;
        }

        usleep(1000000);    // przerwa, aby zasymulowac "myslenie" komputera

        if(free_space(board,n))
        {
            minimax('O',0,board,n,max); // algorytm wywolany dla komputera
            system("clear");
            draw_board(board,n);

            if(win(board,n,max,'O'))
            {
                computer_result = true;
                break;
            }
        }

        else
        {
            draw_result = true;
            break;
        }
    }

    if(gamer_result)
        gamer_signal(); // wygrał gracz

    if(computer_result)
        computer_signal();  // wygrał komputer

    if(draw_result)
        draw_signal();  // remis

    for(int i=0;i<n;i++)
        delete [] board[i];

    delete [] board;

    return 0;
}