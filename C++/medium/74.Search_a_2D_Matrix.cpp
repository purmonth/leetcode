#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();
    int left = 0;
    int right = row * col - 1;
    int pivot, pivot_element;
    while (left <= right) {
      pivot = (left + right) / 2;
      pivot_element = matrix[pivot / col][pivot % col];
      if (target == pivot_element) {
        return true;
      }
      if (target < pivot_element) {
        right = pivot - 1;
      } else {
        left = pivot + 1;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  bool result;
  int target = 3;
  vector<vector<int>> input{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  result = sol.searchMatrix(input, target);
  cout << (result ? "true" : "false") << endl;
  return 0;
}