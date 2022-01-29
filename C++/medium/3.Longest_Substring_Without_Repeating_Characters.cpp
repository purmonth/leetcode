#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*brute force
class Solution {
  bool checkRepetition(string& s, int start, int end) {
    vector<int> chars(128);
    for (int i = start; i <= end; i++) {
      char c = s[i];
      chars[c]++;
      if (chars[c] > 1) {
        return false;
      }
    }
    return true;
  }

 public:
  int lengthOfLongestSubstring(string s) {
    int output = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j < s.length(); j++) {
        if (checkRepetition(s, i, j)) {
          output = max(output, j - i + 1);
        }
      }
    }
    return output;
  }
};
*/
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> chars(128);
    int left = 0, right = 0, res = 0;
    while (right < s.length()) {
      chars[s[right]]++;
      while (chars[s[right]] > 1) {
        chars[s[left]]--;
        left++;
      }
      res = max(res, right - left + 1);
      right++;
    }
    return res;
  }
};

int main() {
  string s = "abcabcbb";
  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
  }
  cout << endl;
  Solution sol;
  cout << sol.lengthOfLongestSubstring(s);
  return 0;
}