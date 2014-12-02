#include<iostream>
using namespace std;

#define maxqueue 10
enum Error_code {success, overflow, underflow};
typedef int Queue_entry;

class Queue {
  public:
    Queue();
    ~Queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;
  private:
    int front;
    int rear;
    int count;
    Queue_entry entry[maxqueue];
};
