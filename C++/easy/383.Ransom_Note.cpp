#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int map[26] = {0};
    for (int i = 0; i < magazine.length(); i++) {
      map[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.length(); i++) {
      int value = map[ransomNote[i] - 'a'];
      if (value <= 0) return false;
      map[ransomNote[i] - 'a']--;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s1 = "aa";
  string s2 = "aab";
  cout << (sol.canConstruct(s1, s2) ? "true" : "false") << endl;
  return 0;
}