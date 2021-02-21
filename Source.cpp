#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "HEADER.H"
using namespace std;
string chooseFile();

int main() {	
	setlocale(LC_ALL, "ru");
	openChoosedFile();
	system("cls");
	system("pause>NUL");
	return 0;
}
string chooseFile() {
	string punctsList[PUNCTS];
	string drawnPoint = "-> ";
	fstream allPuncts("qList.txt");
	string jLocation;

	for (int i = 0; i < PUNCTS; i++) {
		getline(allPuncts, punctsList[i]);
	}

	cout << setw(5) << drawnPoint + punctsList[0] << endl;
	for (int i = 1; i < PUNCTS; i++) {
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
		jLocation = to_string(j+1);
	}
	allPuncts.close();

	return jLocation;
}
void openChoosedFile() {
	string txtFilesFolder = "txtFiles\\";
	string choose = chooseFile();
	string fileExtension = ".txt";

	choose = txtFilesFolder + choose + fileExtension; // (j+1)+.txt
	fstream task(choose);

	system("cls"); //clear window

	char fileStream;

	while (task.get(fileStream))
		cout << fileStream;
	task.close();
	system("pause>NUL");
}