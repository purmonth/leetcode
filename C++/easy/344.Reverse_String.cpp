#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    char temp = '\0';
    for (int i = 0; i < (s.size() / 2); i++) {
      temp = s[i];
      s[i] = s[s.size() - i - 1];
      s[s.size() - i - 1] = temp;
    }
  }
};

int main() {
  Solution sol;
  char array[5] = {'h', 'e', 'l', 'l', 'o'};
  vector<char> input(array, array + 5);
  vector<char>::iterator it;
  sol.reverseString(input);
  for (it = input.begin(); it != input.end(); ++it) cout << *it << ' ';

  return 0;
}