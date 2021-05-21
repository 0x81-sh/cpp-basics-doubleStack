#include "Stack.h"
#include <iostream>
#include <exception>

Stack::Stack(int size) {
    stack = new double[size];
    this->size = size;
    this->at = -1;
}

Stack::~Stack() {
    delete[] stack;
}


int Stack::getSize() const {
    return size;
}

int Stack::getEleCnt() const {
    return at;
}

bool Stack::isFull() const {
    return at + 1 >= size;
}

bool Stack::isEmpty() const {
    return at == -1;
}

void Stack::show() const {
    std::cout << "[ ";
    for (int i = at; i > -1; i--) std::cout << stack[i] << "; ";
    std::cout << "]";
}

double Stack::peek() const {
    if (at == -1) throw std::out_of_range("Cannot peak at empty stack (-1).");
    return stack[at];
}

void Stack::push(double v) {
    if (size <= at + 1) throw std::out_of_range("Cannot push to full stack.");
    stack[++at] = v;
}

double Stack::pop() {
    if (at == -1) throw std::out_of_range("Cannot pop from empty stack (-1).");
    return stack[at--];
}
