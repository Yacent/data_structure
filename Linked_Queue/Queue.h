#include<iostream>
#include "Node.h"
using namespace std;

typedef int Queue_entry;
enum Error_code {success, overflow, underflow};

class Queue {
  public:
    Queue();
    ~Queue();
    bool empty() const;
    Error_code append(const Queue_entry & item);
    Error_code serve();
    Error_code retrieve(Queue_entry & item) const;
    Queue(const Queue & original);
    void operator=(const Queue & original);
  protected:
    Node *front, *rear;
};
