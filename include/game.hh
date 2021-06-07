#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

/*========================================
Plik ten zawiera definicje funkcji
dla gry kolko i krzyzyk.
========================================*/


/*====================================================
Funkcja ta rysuje plansze do gry w konsoli.
Input: podwojny wskaznik na tablice znakow i liczba 
jej wierszy/kolumn
Output: funkcja typu void
====================================================*/
void draw_board(char** board, int n);


/*====================================================
Funkcja ta sprawdza, ktory gracz wygral.
Input: podwojny wskaznik na tablice znakow,liczba 
jej wierszy/kolumn, max liczba znakow do zwyciestwa
oraz znak = 'X' lub 'O'
Output: true = wygrana, false = brak wygranej
====================================================*/
bool win(char** board, int n, int max, char mark);

/*====================================================
Funkcja ta wyswietla odpowiedni komunikat, gry 
wygra czlowiek.
Input: brak
Output: funkcja typu void
====================================================*/
void gamer_signal();

/*====================================================
Funkcja ta wyswietla odpowiedni komunikat, gry 
wygra komputer.
Input: brak
Output: funkcja typu void
====================================================*/
void computer_signal();

/*====================================================
Funkcja ta wyswietla odpowiedni komunikat, gry 
dojdzie do remisu.
Input: brak
Output: funkcja typu void
====================================================*/
void draw_signal();

/*====================================================
Funkcja ta sprawdza, czy sa jeszcze jakies wolne pola
do postawienia znaku przez komputer.
Input: podwojny wskaznik na tablice znakow i liczba 
jej wierszy/kolumn
Output: true = sa wolne pola, false = brak wolnych pol
====================================================*/
bool free_space(char** board, int n);

/*====================================================
Funkcja ta jest realizacja algorytmu minimax, ktory 
znajduje najkorzystniejszy ruch dla komputera.
Input: znak typu 'X' lub 'O', zalezny dla kogo 
prowadzona jest symulacja, poziom rozgrywki, zawsze 
zaczynajacy sie od 0, podwojny wskaznik na tablice 
znakow,liczba jej wierszy/kolumn, max liczba znakow 
do zwyciestwa.
Output: wartosc typu int
====================================================*/
int minimax(char gamer, int level, char** &board, int n, int max);