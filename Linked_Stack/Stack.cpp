#include "Node.h"
#include "Stack.h"

Stack::Stack() {
    top_node = NULL;
}

Stack::Stack(const Stack & original) {
    Node * new_copy, *original_node = original.top_node;
    if (original_node == NULL) {
        top_node = NULL;
    } else {
        top_node = new_copy = new Node(original_node -> entry);
        while (original_node -> next != NULL) {
            original_node = original_node -> next;
            new_copy -> next = new Node(original_node -> entry);
            new_copy = new_copy -> next;
        }
    }
}

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

bool Stack::empty() const {
    if (top_node == NULL) {
        return true;
    }
    return false;
}

Error_code Stack::push(const Stack_entry & item) {
    Node * new_top = new Node(item, top_node);
    if (new_top == NULL) {
        return overflow;
    } else {
        top_node = new_top;
        return success;
    }
}

Error_code Stack::pop() {
    Node * old_top = top_node;
    if (top_node == NULL) {
        return underflow;
    } else {
        top_node = top_node -> next;
        delete old_top;
        return success;
    }
}

Error_code Stack::top(Stack_entry & item) const {
    if (top_node == NULL) {
        return underflow;
    } else {
        item = top_node -> entry;
        return success;
    }
}

void Stack::operator=(const Stack & original) {
    Node * new_top, *new_copy, *original_node = original.top_node;
    if (original_node == NULL) {
        new_top = new_copy = NULL;
    } else {
        new_copy = new_top = new Node(original_node -> entry);
        while(original_node -> next != NULL) {
            original_node = original_node -> next;
            new_copy -> next = new Node(original_node -> entry);
            new_copy = new_copy -> next;
        }
    }
    while (!empty()) {
        pop();
    }
    top_node = new_top;
}

