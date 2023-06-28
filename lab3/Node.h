#ifndef LAB3_NODE_H
#define LAB3_NODE_H

#include "MyString.h"

struct Node {
    MyString val;
    Node* next;

    Node(MyString _val) : val(_val), next(nullptr){}
};


#endif //LAB3_NODE_H
