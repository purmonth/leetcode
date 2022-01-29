#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
};

void traverse(vector<vector<int>> input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  Solution sol;
  vector<vector<int>> input{{}};
  traverse(input);
  return 0;
}