#include<iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack st;
    if (!st.empty()) {
        cout << "There is no element here" << endl;
    }
    for (int i = 0; i < 5; i++) {
        int test;
        cin >> test;
        st.push(test);
    }
    int j;
    st.top(j);
    cout << j << endl;
    for (int i = 0; i < 3; i++) {
        st.pop();
    }
    for (int i = 0; i < 2; i++) {
        int k;
        st.top(k);
        cout << k << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
