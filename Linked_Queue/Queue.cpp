#include "Queue.h"

Queue::Queue() {
    front = rear = NULL;
}

Queue::~Queue() {
    while(!empty()) {
        serve();
    }
}

bool Queue::empty() const {
    if (front == NULL && rear == NULL) {
        return true;
    }
    return false;
}

Error_code Queue::append(const Queue_entry & item) {
    Node *new_rear = new Node(item);
    if (new_rear == NULL) {
        return overflow;
    }
    if (rear == NULL) {
        front = rear = new_rear;
    } else {
        rear -> next = new_rear;
        rear = new_rear;
    }
    return success;
}

Error_code Queue::serve() {
    if (front == NULL) {
        return underflow;
    }
    Node *old_front = front;
    front = front -> next;
    if (front == NULL) {
        rear = NULL;
    }
    delete old_front;
    return success;
}

Error_code Queue::retrieve(Queue_entry & item) const {
    if (front == NULL) {
        return underflow;
    } else {
        item = front -> entry;
        return success;
    }
}

Queue::Queue(const Queue & original) {
    Node *original_front = original.front;
    if (original_front == NULL) {
        front = rear = NULL;
    } else {
        front = rear = new Node(original_front -> entry);
        while (original_front -> next != NULL) {
            original_front = original_front -> next;
            rear -> next = new Node(original_front -> entry);
            rear = rear -> next;
        }
    }
}

void Queue::operator=(const Queue & original) {
    Node *new_front, *new_rear, *original_front = original.front;
    if (original_front == NULL) {
        new_front = new_rear = NULL;
    } else {
        new_front = new_rear = new Node(original_front -> entry);
        while (original_front -> next != NULL) {
            original_front = original_front -> next;
            new_rear -> next = new Node(original_front -> entry);
            new_rear = new_rear -> next;
        }
    }
    while (!empty()) {
        serve();
    }
    front = new_front;
}
