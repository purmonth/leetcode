#include <iostream>
#include <vector>
using namespace std;

/*
move right: (row, col + 1)
move downwards: (row + 1, col)
move left: (row, col - 1)
move upwards: (row - 1, col)
*/

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int cnt = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
      // direction 1 - traverse from left to right
      for (int ptr = layer; ptr < n - layer; ptr++) {
        result[layer][ptr] = cnt++;
      }
      // direction 2 - traverse from top to bottom
      for (int ptr = layer + 1; ptr < n - layer; ptr++) {
        result[ptr][n - layer - 1] = cnt++;
      }
      // direction 3 - traverse from right to left
      for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
        result[n - layer - 1][ptr] = cnt++;
      }
      // direction 4 - traverse from bottom to top
      for (int ptr = n - layer - 2; ptr > layer; ptr--) {
        result[ptr][layer] = cnt++;
      }
    }
    return result;
  }
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
  int number = 5;
  vector<vector<int>> input = sol.generateMatrix(number);
  traverse(input);
  return 0;
}