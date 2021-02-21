#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "HEADER.H"
using namespace std;
string chooseFile();

int main(int j) {	
	setlocale(LC_ALL, "ru");
	openChoosedFile();
	system("cls");
	system("pause>NUL");
	return 0;
}
string chooseFile() {
	int Puncts = countOfTopic();
	
	string drawnPoint = "-> ";
	fstream allPuncts("qList.txt");
	string jLocation;

	string* punctsList = new string[Puncts];

	for (int i = 0; i < Puncts; i++) {
		getline(allPuncts, punctsList[i]);
	}
	

	for (int i = 0; i < Puncts; i++) {
		if (i == j) {
			cout << setw(5) << drawnPoint + punctsList[i] << endl;
		}
		else {
			cout << setw(5) << punctsList[i] << endl;
		}
	}

	char selectingFile = 'a';

	while (selectingFile != 13) {
		selectingFile = _getch();
		system("cls");
		if (selectingFile == 's') {
			j++;
			if (j >= Puncts) {
				j = 0;
			}
		}
		if (selectingFile == 'w') {
			j--;
			if (j < 0) {
				j = Puncts;
			}
		}
		for (int i = 0; i < Puncts; i++) {
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

	char enterWaiting = 'a';
	while (enterWaiting != 13) {
		enterWaiting = _getch();
	}

	system("pause>NUL");
	system("cls");
	main(j);
}
int countOfTopic() {
	int count = 0;
	char fileStream;

	fstream allPuncts("qList.txt");
	while (allPuncts.get(fileStream)) {
		if (fileStream == '\n')
			count++;
	}
	allPuncts.close();

	return count+1;
}