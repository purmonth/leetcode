#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
      for(int i = 0;i < grid.size();i ++){
          for(int j = 0;j < grid[0].size();j ++){
              
          }
      }
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
  vector<vector<int>> input{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  traverse(input);
  return 0;
}