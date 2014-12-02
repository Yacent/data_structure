#include<iostream>
using namespace std;

#define max_size 10
enum Error_code {success, overflow, underflow};
typedef int Stack_entry;

class Stack {
  public:
    Stack();
    ~Stack();
    bool empty() const;
    Error_code pop();
    Error_code push(const Stack_entry & item);
    Error_code top(Stack_entry &item) const;
  private:
    int count;
    Stack_entry entry[max_size];
};
