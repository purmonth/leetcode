#include <iostream>
using namespace std;

class Solution {
 public:
  int fib(int n) {
      if(n == 0)return 0;
      if(n == 1)return 1;
      return fib(n-1)+fib(n-2);
  }
};

int main(){
  Solution sol;
  int input = 5;
  cout << sol.fib(input) << endl;
  return 0;
}