#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
  stack<int> stack_q;
  stack<int> buffer_q;

 public:
  void push(int x) { stack_q.push(x); }
  int pop() {
    if (buffer_q.empty()) {
      while (!stack_q.empty()) {
        buffer_q.push(stack_q.top());
        stack_q.pop();
      }
    }
    int temp = buffer_q.top();
    buffer_q.pop();
    return temp;
  }
  int peek() {
    int temp = 0;
    if (!buffer_q.empty()) {
      temp = buffer_q.top();
    } else {
      while (!stack_q.empty()) {
        buffer_q.push(stack_q.top());
        stack_q.pop();
      }
      temp = buffer_q.top();
    }
    return temp;
  }
  bool empty() {
    if (buffer_q.empty() && stack_q.empty())
      return true;
    else
      return false;
  }
};

int main() {
  MyQueue* q = new MyQueue();
  q->push(1);
  q->push(2);
  cout << q->peek() << endl;
  cout << q->pop() << endl;
  cout << (q->empty() ? "true" : "false");

  return 0;
}