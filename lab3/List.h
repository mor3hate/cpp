#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include "MyString.h"
#include "Node.h"



struct List {
    Node* first;
    Node* last;

    List(): first(nullptr), last(nullptr) {}

    bool isListEmpty();

    void pushToBack(MyString _val);

    void print();

    void replaceValue(MyString oldValue, MyString newValue);

    void destructList();

    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.first;
        while (current) {
            os << current->val << " ";
            current = current->next;
        }
        return os;
    }
};


#endif //LAB3_LIST_H
