#include <iostream>
#include <fstream>
#include "MyString.h"
#include "List.h"



int main() {
    std::ifstream readFile("entry.txt");
    std::ofstream pr("protocol.txt");
    std::ofstream res("result.txt");


    if (!readFile.is_open()) {
        std::cout << "Произошла ошибка в чтении файла" << std::endl;
    }

    List list;

    while (!readFile.eof()) {
        char buffer[256];
        readFile.getline(buffer, 256);
        MyString line(buffer);
        list.pushToBack(line);
    }
    readFile.close();

    if (pr.is_open()) {
        pr << list;
        std::cout << "Протокол записан" << std::endl;
    } else {
        std::cout << "Произошла ошибка в записи данных в протокол" << std::endl;
    }
    pr.close();

    MyString oldValue("Первая строка*");
    MyString newValue("Hello world!");


    list.replaceValue(oldValue, newValue);

    std::cout << "Список после замены значений:" << std::endl;
    list.print();

    if (res.is_open()) {
        res << list;
        std::cout << "Результат записан" << std::endl;
    } else {
        std::cout << "Произошла ошибка в записи данных" << std::endl;
    }
    res.close();

    list.destructList();

    std::cout << "Список после удаления:" << std::endl;
    list.print();

    return 0;
}