#include <iostream>
#include <fstream>
#include "MyString.h"


int main() {
    char buff[50];

    std::ifstream readFile("textWithSpaces.txt");
    std::ofstream pr("protocol.txt");


    if (readFile.is_open()) {
        readFile.getline(buff, 50);
        readFile.close();
    } else {
        std::cout << "Произошла ошибка в чтении файла" << std::endl;
    }

    MyString str(buff);

    if (pr.is_open()) {
        pr << buff;
        std::cout << "Протокол записан" << std::endl;
    } else {
        std::cout << "Произошла ошибка в записи данных в протокол" << std::endl;

    }
    pr.close();

    // calculate our axis
    str.CountAxisSpaces();

    return 0;
}