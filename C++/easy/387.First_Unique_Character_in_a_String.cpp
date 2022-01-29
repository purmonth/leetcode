#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int count[26] = {0};
    int n = s.length();
    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      count[index]++;
    }
    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      if (count[index] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  string array = "leetcode";
  for (int i = 0; i < array.size(); i++) {
    cout << array[i] << " ";
  }
  cout << '\n' << sol.firstUniqChar(array);
  return 0;
}