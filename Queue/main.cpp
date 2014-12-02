#include "Queue.h"
using namespace std;

int main() {
    Queue qu;
    if (!qu.empty()) {
        cout << "FUCK YOU, there is no element" << endl;
    }
    for (int i = 0; i < 10; i++) {
        int test;
        cin >> test;
        qu.append(test);
    }
    int j;
    qu.retrieve(j);
    cout << j << endl;
    for (int i = 0; i < 5; i++) {
        qu.serve();
    }
    for (int i = 0; i < 3; i++) {
        int test;
        cin >> test;
        qu.append(test);
    }
    for (int i = 0; i < 8; i++) {
        int k;
        qu.retrieve(k);
        cout << k << " ";
        qu.serve();
    }
    cout << endl;
    return 0;
}
