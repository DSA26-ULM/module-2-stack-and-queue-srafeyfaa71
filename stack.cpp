#include "stack.h"
#include <stdexcept>
#include <iostream>

void init(Stack* s) {
    s->top = NULL;
}

bool isEmpty(const Stack* s) {
    return (s->top == NULL);
}

bool isFull(const Stack* s) {
    return (s->top == &(s->data[MAX - 1]));
}

void push(Stack* s, int value) {
    if (isFull(s)) throw std::runtime_error("Stack Penuh!");
    
    if (isEmpty(s)) {
        s->top = &(s->data[0]);
    } else {
        s->top++;
    }
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) throw std::runtime_error("Stack Kosong!");
    
    if (s->top == &(s->data[0])) {
        s->top = NULL;
    } else {
        s->top--;
    }
}

int peek(const Stack* s) {
    if (isEmpty(s)) throw std::runtime_error("Stack Kosong!");
    return *(s->top);
}
