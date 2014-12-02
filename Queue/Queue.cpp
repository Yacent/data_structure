#include "Queue.h"

Queue::Queue() {
    count = 0;
    front = 0;
    rear = maxqueue - 1;
}

Queue::~Queue() {
}

bool Queue::empty() const {
    return count;
}

Error_code Queue::serve() {
    if (count <= 0) {
        return underflow;
    } else {
        --count;
        front = ((front + 1) == maxqueue)?0:(front + 1);
        return success;
    }
}

Error_code Queue::append(const Queue_entry &item) {
    if (count >= maxqueue) {
        return overflow;
    } else {
        count++;
        rear = ((rear + 1) == maxqueue)?0:(rear + 1);
        entry[rear] = item;
        return success;
    }
}

Error_code Queue::retrieve(Queue_entry &item) const {
    if (count <= 0) {
        return underflow;
    } else {
        item = entry[front];
        return success;
    }
}
