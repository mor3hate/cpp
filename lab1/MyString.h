#ifndef LAB1_MYSTRING_H
#define LAB1_MYSTRING_H


class MyString {
    static const char MARK = '*';
public:
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

    ~MyString() {
        delete[] this->str;
    }

    int strLen(const char *str, const char MARK);

    void Print();

    void CountAxisSpaces();

private:
    // only dynamic arrays due to unknown str length in future
    char *str;
};


#endif //LAB1_MYSTRING_H
