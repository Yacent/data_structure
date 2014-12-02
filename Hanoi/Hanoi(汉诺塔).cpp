//  HanoiÓÃµİ¹éÊµÏÖººÅµËş 

#include<iostream>
using namespace std;

void move(int count, int start, int finish, int tmp);

int main() {
    int disk_all;
    cin >> disk_all;
    move(disk_all, 1, 3, 2);
    return 0;
}

void move(int count, int start, int finish, int tmp) {
    if (count > 0) {
        move(count-1, start, tmp, finish);
        cout << "Move disk" << count << " from " << start << " to " << finish
        << "." << endl;
        move(count-1, tmp, finish, start);
    }
}
