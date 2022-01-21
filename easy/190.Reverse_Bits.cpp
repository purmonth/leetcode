#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
  }
};

int main() {
  uint32_t intput = 43261596;
  Solution sol;
  cout << sol.reverseBits(intput) << endl;
  return 0;
}