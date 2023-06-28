#ifndef LAB3_MYSTRING_H
#define LAB3_MYSTRING_H

#include <iostream>


class MyString {
    static const char MARK = '*';
public:
    bool operator==(const MyString &other) {
        return strcmp(this->str, other.str) == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.str;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, MyString& str) {
        char buffer[256];
        is.getline(buffer, 256);
        str = buffer;
        return is;
    }

    MyString() {
        str = nullptr;
    }

    MyString(const char *str) {
        int strLength = strLen(str, MARK);
        // due to *char in constructor
        this->str = new char[strLength + 1];

        for (int i = 0; i < strLength; ++i) {
            // store all our symbols in dynamic arr
            this->str[i] = str[i];
        }
        // to show the end of the str
        this->str[strLength] = MARK;
    }

//    ~MyString() {
//        if (this->str != nullptr) {
//            delete[] this->str;
//            this->str = nullptr;
//        }
//    }


    int strcmp(const char* s1, const char* s2);

    int strLen(const char *str, const char MARK);

    void Print();

    void CountAxisSpaces();

private:
    // only dynamic arrays due to unknown str length in future
    char *str;
};


#endif //LAB3_MYSTRING_H
