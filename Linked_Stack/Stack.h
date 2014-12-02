#include<iostream>
#include "Node.h"

using namespace std;

typedef int Stack_entry;
enum Error_code {overflow, success, underflow};

class Stack {
  public:
    Stack();
    Stack(const Stack & original);
    ~Stack();
    bool empty() const;
    Error_code push(const Stack_entry & item);
    Error_code pop();
    Error_code top(Stack_entry & item) const;
    void operator=(const Stack & original);
  private:
    Node* top_node; 
};
