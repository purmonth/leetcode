#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int row = 1; row < triangle.size(); row++) {
      for (int col = 0; col < triangle[row].size(); col++) {
        int min_sum = INT_MAX;
        if (col > 0) {
          min_sum = triangle[row - 1][col - 1];
        }
        if (col < row) {
          min_sum = min(min_sum, triangle[row - 1][col]);
        }
        int path = min_sum + triangle[row][col];
        triangle[row][col] = path;
      }
    }
    int smallest = INT_MAX;
    int row_amount = triangle.size();
    for (int j = 0; j < triangle[row_amount - 1].size(); j++) {
      smallest = min(triangle[row_amount - 1][j], smallest);
    }
    return smallest;
  }
};

void traverse(vector<vector<int>> input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  Solution sol;
  vector<vector<int>> input{{-1}, {2, 3}, {1, -1, -3}};
  cout << sol.minimumTotal(input);
  return 0;
}