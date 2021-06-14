#include "Menu.h"
#include "Main.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

int main() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    bool cotRunCheck = false;

    if (!cotRunCheck) {
        txtFilesCreator();
    }
    openChoosedFile();
    system("cls");
    std::cin.get();
    return 0;
}
