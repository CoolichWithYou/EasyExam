#include "Menu.h"
#include "Main.h"


int main() {
    setlocale(LC_ALL, "ru");

    bool cotRunCheck = false;

    if (!cotRunCheck) {
        txtFilesCreator();
    }
    openChoosedFile();
    system("cls");
    std::cin.get();
    return 0;
}
