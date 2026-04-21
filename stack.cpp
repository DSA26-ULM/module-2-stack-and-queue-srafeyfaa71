#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    s->top = &(s->data[-1]); 
}

bool isEmpty(const Stack* s) {
    return (s->top == &(s->data[-1]));
}

bool isFull(const Stack* s) {
    return (s->top == &(s->data[MAX - 1]));
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        throw std::runtime_error("Stack Penuh!");
    }
    s->top++;
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        throw std::runtime_error("Stack Kosong!");
    }
    s->top--;
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw std::runtime_error("Stack Kosong!");
    }
    return *(s->top);
}
