#include "MyString.h"
#include <iostream>
#include <fstream>


int MyString::strLen(const char *str, const char MARK) {
    int counter = 0;

    while (str[counter] != MARK) {
        counter++;
    };

    return counter;
}

void MyString::Print() {
    std::cout << str;
}

void MyString::CountAxisSpaces() {
    std::ofstream out("result.txt");
    int currentSpaceStart = 0;

    int maxSpacesEnd = 0;
    int currentSpaceEnd = 0;
    int strLength = strLen(str, MARK);

    for (int i = 0; i < strLength; ++i) {
        if (str[i] == ' ') {
            currentSpaceEnd++;
        } else {
            if (currentSpaceEnd > maxSpacesEnd) {
                maxSpacesEnd = currentSpaceEnd;
                currentSpaceStart = i - currentSpaceEnd;
            }
            currentSpaceEnd = 0;
        }
    }
    if (currentSpaceEnd > maxSpacesEnd) {
        maxSpacesEnd = currentSpaceEnd;
    }

    if (out.is_open()) {
        out << "Старт:" << currentSpaceStart << std::endl << "Конец:" << currentSpaceStart + maxSpacesEnd - 1;
        std::cout << "Файл записан" << std::endl;
    } else {
        std::cout << "Произошла ошибка в записи данных в файл" << std::endl;

    }
    out.close();
}