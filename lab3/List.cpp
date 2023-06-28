#include "List.h"
#include <iostream>


bool List::isListEmpty() {
    return first == nullptr;
}

void List::pushToBack(MyString _val) {
    Node* newNode = new Node(_val);
    if (!last) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = last->next;
    }
}

void List::print() {
    if (isListEmpty()) return;
    Node* l = first;
    while (l) {
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout << std::endl;
}

void List::replaceValue(MyString oldValue, MyString newValue) {
    if (isListEmpty()) return;
    Node* l = first;
    while (l) {
        if (l->val == oldValue) {
            l->val = newValue;
        }
        l = l->next;
    }
}

void List::destructList() {
    if (isListEmpty()) return;
    Node* current = first;
    while (current) {
        Node* next = current->next;  // Сохраняем указатель на следующий узел
        delete current;              // Удаляем текущий узел
        current = next;              // Перемещаемся к следующему узлу
    }
    first = nullptr;
    last = nullptr;
}