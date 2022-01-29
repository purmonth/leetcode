#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
};

void traverse_string(string s) {
  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
  }
}

int main() {
  string s = "abcabcbb";
  traverse_string(s);
  return 0;
}