#pragma once

const int DEFAULT_SIZE = 100;

class Stack {
private:
    double *stack;
    int size;
    int at;

public:
    Stack(int size = DEFAULT_SIZE);
    ~Stack();

    int getSize() const;
    int getEleCnt() const;
    bool isFull() const;
    bool isEmpty() const;
    double peek() const;
    void show() const;

    void push(double v);
    double pop();
};