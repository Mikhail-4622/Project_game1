#include <iostream>

using namespace std;

bool checkWinH(char table[][3], char player) {
	for (int y = 0; y < 3; y++) {
		bool win = true;
		for (int x = 0; x < 3; x++) {
			if (table[y][x] != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return true;
		}
	}
	return false;
}

bool checkWinV(char table[][3], char player) {
	for (int y = 0; y < 3; y++) {
		bool win = true;
		for (int x = 0; x < 3; x++) {
			if (table[x][y] != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return true;
		}
	}
	return false;
}

bool checkWinD1(char table[][3], char player) {
	for (int i = 0; i < 3; i++) {
		if (table[i][i] != player) {
			return false;
		}
	}
	return true;
}

bool checkWinD2(char table[][3], char player) {
	bool win = true;
	for (int i = 0; i < 3; i++) {
		if (table[i][2 - i] != player) {
			win = false;
			break;
		}
	}
	return win;
}

bool checkWin(char table[][3], char player) {
	return checkWinH(table, player) ||
		checkWinV(table, player) ||
		checkWinD1(table, player) ||
		checkWinD2(table, player);
}

void inputCoords(int& x, int& y) {
	while (true) {
		cout << "Введите координаты: ";
		cin >> x >> y;
		if (x < 0 || x > 2 || y < 0 || y > 2) {
			cout << "Некорректные координаты" << endl;
		}
		else {
			return;
		}
	}
}

void showTable(char table[][3]) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << table[y][x] << ' ';
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "");
	char table[][3] = {
		{'_', '_', '_'},
		{'_', '_', '_'},
		{'_', '_', '_'}
	};
	showTable(table);

	while (true) {
		int point_y;
		int point_x;
		inputCoords(point_x, point_y);
		table[point_y][point_x] = 'X';

		if (checkWin(table, 'X')) {
			cout << "'X' win" << endl;
			break;
		}
		showTable(table);
	}

	return 0;
}