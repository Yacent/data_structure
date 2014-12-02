#include<iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack st;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        st.push(num);
    }
    int tmp;
    st.top(tmp);
    cout << tmp << endl;
    for (int i = 0; i < 5; i++) {
        int j;
        st.top(j);
        cout << j << " ";
        st.pop();
    }
    return 0;
}
