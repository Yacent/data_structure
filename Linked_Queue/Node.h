#include<iostream>

using namespace std;

typedef int Node_entry;

struct Node {
    Node_entry entry;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(Node_entry item, Node *add_on = NULL) {
        entry = item;
        next = add_on;
    }
};
