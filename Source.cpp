#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "HEADER.H"
using namespace std;

int main() {	
	setlocale(LC_ALL, "ru");

	string punctsList[PUNCTS];
	string drawnPoint = "-> ";
	fstream allPuncts("qList.txt");
	string jLocation;

	for (int i = 0; i < PUNCTS; i++) {
		getline(allPuncts, punctsList[i]);
	}

	cout << setw(5) << drawnPoint + punctsList[0] << endl; //вывод первой строки с указателем
	for (int i = 1; i < PUNCTS; i++) { //вывод оставшихся
		cout << setw(5) << punctsList[i] << endl;
	}

	char _ch = 'a';

	while (_ch != 13) {
		_ch = _getch();
		system("cls");
		if (_ch == 's') {
			j++;
			if (j >= PUNCTS) {
				j = 0;
			}
		}
		if (_ch == 'w') {
			j--;
			if (j < 0) {
				j = PUNCTS;
			}
		}
		for (int i = 0; i < PUNCTS; i++) {
			if (i == j) {
				cout << drawnPoint + punctsList[i] << endl;
			}
			else {
				cout << setw(5) << punctsList[i] << endl;
			}
		}
		jLocation = to_string(j);
	}

	system("cls");
	allPuncts.close();
	system("pause>NUL");
	return 0;
}

