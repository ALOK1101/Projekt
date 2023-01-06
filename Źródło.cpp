#include<iostream>
#include <conio.h>

#include <windows.h>

void sleep(unsigned milliseconds)
{
	Sleep(milliseconds);
}

using namespace std;

void intro();
void boardOut(char tab[8][8]);
void gameplay(char tab[8][8], int counter);
int* coordinatesConverter(string word);
bool coordinatesChecker(int coordinates[2], char tab[8][8], char Player);
void moves(int coordinates[2], char tab[8][8], char Player);

bool win();
int main() {
	char board[8][8] = { {' ','O',' ','O',' ','O', ' ', 'O'},
						{'O',' ','O',' ','O',' ', 'O', ' '},
						{' ','O',' ','O',' ','O', ' ', 'O'},
						{' ',' ',' ',' ',' ',' ', ' ', ' '},
						{' ',' ',' ',' ',' ',' ', ' ', ' '},
						{'X',' ','X',' ','X',' ', 'X', ' '},
						{' ','X',' ','X',' ','X', ' ', 'X'},
						{'X',' ','X',' ','X',' ', 'X', ' '} };
	//intro();
	int RoundCounter = 0;
	while (win) {
		gameplay(board, RoundCounter);
		RoundCounter++;
		system("cls");
	}
	return 0;
}
void intro() {
	cout << "Witaj w grze w warcaby!" << endl;
	sleep(1200);
	system("cls");
	cout << "POWODZENIA!!";
	sleep(1200);
	system("cls");
}
void boardOut(char tab[8][8]) {
	string coordinates;
	char x = 'A';
	int y = 1;
	cout << "    ";
	for (int i = 0; i < 8; i++)
	{
		cout << x << "   ";
		x += 1;
	}cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
	for (int i = 0; i < 8; i++) {
		cout << y;
		for (int j = 0; j < 8; j++) {
			cout << " " << "| " << tab[i][j];
			sleep(1);
		}
		y += 1;

		cout << " |" << endl;
		cout << "  +---+---+---+---+---+---+---+---+";
		cout << endl;


	}
}
void gameplay(char tab[8][8], int counter) {
	char Player;
	if (counter % 2 == 0) {
		Player = 'X';
		cout << "\t    Tura gracza X\n" << endl;
	}
	else {
		Player = 'O';
		cout << "\t    Tura gracza O\n" << endl;
	}
	boardOut(tab);
	string coordinates;
	cout << "Podaj koordynaty pionka, ktorym chcesz sie poruszyc: ";
	cin >> coordinates;
	
	while (!coordinatesChecker(coordinatesConverter(coordinates), tab, Player)) {
		cout << "Podaj ponownie koordynaty: ";
		cin >> coordinates;
	}
	
	moves(coordinatesConverter(coordinates), tab, Player);
	
	
}
int* coordinatesConverter(string coordinates) {
	int tab[2];
	int letter, number;
	if (coordinates[0] >= 65 && coordinates[0] <= 72) letter = coordinates[0] - 65;
	else if (coordinates[0] >= 97 && coordinates[0] <= 104) letter = coordinates[0] - 97;
	else cout << "Nieprawidlowe koordynaty\n";
	if (coordinates[1] >= 49 && coordinates[1] <= 56) number = coordinates[1] - 49;
	else cout << "Nieprawidlowe koordynaty\n";
	//cout << endl << number << "\t" << letter;
	tab[0] = letter;
	tab[1] = number;
	return tab;
}
bool coordinatesChecker(int coordinates[2], char tab[8][8], char Player) {
	int x = coordinates[0], y = coordinates[1];
	bool flag = false;
	if (tab[y][x] != Player) return false;
	if (Player == 'X') {
		if (y - 1 >= 0 && x + 1 < 8) {
			if (tab[y - 1][x + 1] == ' ') {
				flag = true;
			}
		}
		if (y - 1 >= 0 && x - 1 >= 0) {
			if (tab[y - 1][x - 1] == ' ') {
				flag = true;
			}
		}


	}

	else {
		if (y + 1 < 8 && x + 1 < 8) {
			if (tab[y + 1][x + 1] == ' ') {
				flag = true;
			}
		}
		if (y + 1 < 8 && x - 1 >= 0) {
			if (tab[y + 1][x - 1] == ' ') {
				flag = true;
			}
		}

	}
	return flag;
	
}
void moves(int coordinates[2], char tab[8][8], char Player) {

	int y = coordinates[1], x = coordinates[0], counter=1;
	bool flag=false;
	int moveX, moveY, moveX2, moveY2;
	cout << "Wybierz opcje ruchu: \n";
	if (Player == 'X') {
		if (y - 1 >= 0 && x + 1 < 8) {
			char x1 = x + 66, y1 = y + 48;
			if (tab[y - 1][x + 1] == ' ') {
				cout << endl << counter << ". mozliwosc ruchu w prawo na pole: " << x1 << y1 << endl;
				moveX = x + 1;
				moveY = y - 1;
				counter++;
			}
		}
		if (y - 1 >= 0 && x - 1 >= 0) {
			char x2 = x + 64, y2 = y + 48;
			if (tab[y - 1][x - 1] == ' '){
				cout << counter << ". mozliwosc ruchu w lewo na pole: " << x2 << y2 << endl;
				moveX2 = x - 1;
				moveY2 = y - 1;
			}
		}


	}

	else {
		if (y + 1 < 8 && x + 1 < 8) {
			char x1 = x + 66, y1 = y + 50;
			if (tab[y + 1][x + 1] == ' ') {
				cout <<endl<<counter<< ". mozliwosc ruchu w prawo na pole: " << x1 << y1 << endl;
				moveX = x + 1;
				moveY = y + 1;
				counter++;
			}
		}
		if (y + 1 < 8 && x - 1 >= 0) {
			char x2 = x + 64, y2 = y + 50;
			if (tab[y + 1][x - 1] == ' ') {
				cout << counter << ". mozliwosc ruchu w lewo na pole: " << x2 << y2 << endl;
				moveX2 = x - 1;
				moveY2 = y + 1;
			}
		}

	}
	int move;
	cin >> move;
	while (move != 1 && move != 2) {
		cout << "Nieprawidłowy ruch!\n" << "Podaj ponowanie: ";
		cin >> move;
	}
	if (move == counter-1) {
		tab[y][x] = ' ';
		tab[moveY][moveX] = Player;
	}
	else {
		tab[y][x] = ' ';
		tab[moveY2][moveX2] = Player;
	}
	
}
bool win() {

	return false;
}
