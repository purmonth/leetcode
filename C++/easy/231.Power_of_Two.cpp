#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    while (n % 2 == 0) n /= 2;
    return n == 1;
  }
};

int main() {
  int intput = 3;
  Solution sol;
  cout << (sol.isPowerOfTwo(intput) ? "true" : "false") << endl;
  return 0;
}