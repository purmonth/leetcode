#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> output;
    output.push_back("");

    for (int i = 0; i < S.length(); i++) {
      if (isalpha(S[i])) {
        vector<string> temp;
        for (auto o : output) {
          temp.push_back(o + (char)toupper(S[i]));
          temp.push_back(o + (char)tolower(S[i]));
        }
        output = temp;
      } else {
        for (auto &o : output) {
          o += S[i];
        }
      }
    }
    return output;
  }
};

void traverse(vector<string> input) {
  vector<string>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

void traverse_string(string s) {
  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  string s = "a1b2";
  traverse_string(s);

  traverse(sol.letterCasePermutation(s));
  return 0;
}