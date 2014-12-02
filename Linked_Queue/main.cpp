#include<iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue qu;
    if (qu.empty()) {
        cout << "The queue is empty\n";
    }
    for (int i = 0; i < 10; i++) {
        int test;
        cin >> test;
        qu.append(test);
    }
    for (int i = 0; i < 3; i++) {
        qu.serve();
    }
    for (int i = 0; i < 4; i++) {
        int test;
        cin >> test;
        qu.append(test);
    }
    for (int i = 0; i < 11; i++) {
        int j;
        qu.retrieve(j);
        cout << j << " ";
        qu.serve();
    }
    cout << endl;
    if (qu.serve() == underflow) {
        cout << "The queue is empty\n";
    }
    return 0;
}
