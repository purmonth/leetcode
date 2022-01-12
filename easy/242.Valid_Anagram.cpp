#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s.compare(t) == 0)
      return true;
    else
      return false;
  }
};
int main() {
  Solution sol;
  string s1 = "anagram";
  string s2 = "nagaram";
  cout << (sol.isAnagram(s1, s2) ? "true" : "false") << endl;
  return 0;
}