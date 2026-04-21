#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(const Queue* q) {
    return (q->front == NULL);
}

bool isFull(const Queue* q) {
    if (q->rear == &(q->data[MAX - 1])) return true;
    return false;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) throw std::runtime_error("Queue Penuh!");
    
    if (isEmpty(q)) {
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        q->rear++;
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) throw std::runtime_error("Queue Kosong!");                
    
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    return *(q->front);
}

int back(const Queue* q) {
    return *(q->rear);
}
