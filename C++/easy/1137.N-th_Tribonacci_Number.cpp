#include <iostream>
using namespace std;

class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int temp = 0, a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; i++) {
      temp = a + b + c;
      a = b;
      b = c;
      c = temp;
    }
    return c;
  }
};

int main() {
  Solution sol;
  int input = 35;
  cout << sol.tribonacci(input) << endl;
  return 0;
}