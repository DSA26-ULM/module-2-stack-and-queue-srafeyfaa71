#include "queue.h"
#include <stdexcept>
#include <iostream>

void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(const Queue* q) {
    return (q->front == NULL);
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    
    int* nextRear;
    if (q->rear == &(q->data[MAX - 1])) {
        nextRear = &(q->data[0]);
    } else {
        nextRear = q->rear + 1;
    }
    return (nextRear == q->front);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::runtime_error("Queue Penuh!");
    }
    
    if (isEmpty(q)) {
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        if (q->rear == &(q->data[MAX - 1])) {
            q->rear = &(q->data[0]);
        } else {
            q->rear++;
        }
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::runtime_error("Queue Kosong!");
    }
    
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        if (q->front == &(q->data[MAX - 1])) {
            q->front = &(q->data[0]);
        } else {
            q->front++;
        }
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) throw std::runtime_error("Queue Kosong!");
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) throw std::runtime_error("Queue Kosong!");
    return *(q->rear);
}
