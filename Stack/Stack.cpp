#include "Stack.h"

Stack::Stack() {
    count = 0;
}

Stack::~Stack() {
}

bool Stack::empty() const {
    return count;
}

Error_code Stack::pop() {
    if (count <= 0) {
        return underflow;
    } else {
        --count;
        return success;
    }
}

Error_code Stack::push(const Stack_entry &item) {
    if (count >= max_size) {
        return overflow;
    } else {
        entry[count++] = item;
        return success;
    }
}

Error_code Stack::top(Stack_entry &item) const {
    if (count == 0) {
        return underflow;
    } else {
        item = entry[count-1];
        return success;
    }
}

