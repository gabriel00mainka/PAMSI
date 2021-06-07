#include <iostream>
#include "game.hh"


/*========================================
Plik ten zawiera implementacje funkcji
dla gry kolko i krzyzyk.
========================================*/

// tworzenie planszy
void draw_board(char** board, int n)
{
    cout << endl << endl;
   
    for(int i=0;i<n;i++)
        for(int j=1;j<=n;j++)
        {
            cout << " " << board[i][j-1] << " ";
            if(j % n)
                cout << "|";

            else if(j % n == 0 && i != (n-1))
            {
                cout << endl;
                for(int k=1;k<=n;k++)
                {
                    if(k % n != 0)
                        cout << "---+";
                    
                    else 
                        cout << "---";
                }

                cout << endl;
            }

            else cout << endl;
        }
}



bool win(char** board, int n, int max, char mark)
{
    int ind = 0;

    for(int i=0;i<n;i++)    // sprawdzenie wierszy
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] == mark)
                ind++;

            else
                ind = 0;

            if(ind == max)
                return true;
        }

        ind = 0;
    }

    ind = 0;

    for(int i=0;i<n;i++)    // sprawdzenie kolumn
    {
        for(int j=0;j<n;j++)
        {
            if(board[j][i] == mark)
                ind++;

            else
                ind = 0;
        }

        if(ind == max)
            return true;

        ind = 0;
    }

    ind = 0;

    for(int i=0;i<n;i++)    // sprawdzanie pierwszej przekatnej
    {
        if(board[i][i] == mark)
            ind++;

        else
            ind = 0;
    }

    if(ind == max)
        return true;

    int i = 0;
    int j = n-1;
    ind = 0;

    while(i < n)        // sprawdzanie drugiej przekatnej
    {
        if(board[i][j] == mark)
            ind++;

        else
            ind = 0;

        if(ind == max)
            return true;

        i++;
        j--;
    }

    return false;
}




void gamer_signal()
{
    cout << endl << endl;
    cout << "===========================" << endl;
    cout << "   GRATULACJE! WYGRALES!   " << endl;
    cout << "===========================" << endl << endl;
}


void computer_signal()
{
    cout << endl << endl;
    cout << "===========================================" << endl;
    cout << "   NASTEPNYM RAZEM WYGRASZ! POWODZENIA!    " << endl;
    cout << "===========================================" << endl << endl;
}


void draw_signal()
{
    cout << endl << endl;
    cout << "===========" << endl;
    cout << "   REMIS!  " << endl;
    cout << "===========" << endl << endl;
}


bool free_space(char** board, int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(board[i][j] == ' ')
                return true;

    return false;
}



int minimax(char gamer, int level, char** &board, int n, int max)
{
    int counter = 0;
    int x = 0;
    int y = 0;

    for(int i=0;i<n;i++)        // sprawdzenie czy ktos wygral
        for(int j=0;j<n;j++)
            if(board[i][j] == ' ')
            {
                board[i][j] = gamer;
                x = i;
                y = j;
                counter++;  // jesli bylby remis zliczamy wolne pola
                
                bool check_win = win(board,n,max,gamer);
                board[i][j] = ' ';

                if(check_win)
                {
                    if(level == 0)
                        board[i][j] = gamer;

                    if(gamer == 'O')
                        return -1;

                    else
                        return 1;
                }
            }

    if(counter == 1)
    {
        if(level == 0)      // sprawdzamy czy nastapil remis
            board[x][y] = gamer;
        
        return 0;
    }

    int step = 0;           // ruch gracza
    int step_max = 0;       // najlepszy ruch dla gracza
    
    if(gamer == 'O')
        step_max = 2;

    else 
        step_max = -2;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(board[i][j] == ' ')
            {
                board[i][j] = gamer;
                if(gamer == 'O')
                    step = minimax('X',level+1,board,n,max);

                else 
                    step = minimax('O',level+1,board,n,max);

                board[i][j] = ' ';

                if(((gamer == 'O') && (step < step_max)) || ((gamer == 'X') && (step > step_max)))
                {
                    step_max = step;
                    x = i;
                    y = j;
                }
            }

    if(level == 0)
        board[x][y] = gamer;

    return step_max;

}