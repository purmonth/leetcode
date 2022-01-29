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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> list;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    while (list.size() < rows * cols) {
      for (int i = left; i <= right; i++) {
        list.push_back(matrix[top][i]);
      }
      for (int i = top + 1; i <= bottom; i++) {
        list.push_back(matrix[i][right]);
      }
      if (top != bottom) {
        for (int i = right - 1; i >= left; i--) {
          list.push_back(matrix[bottom][i]);
        }
      }
      if (left != right) {
        for (int i = bottom - 1; i > top; i--) {
          list.push_back(matrix[i][left]);
        }
      }
      left++;
      top++;
      right--;
      bottom--;
    }

    return list;
  }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  traverse(sol.spiralOrder(input));
  return 0;
}