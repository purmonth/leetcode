#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return matrix;
    int col = matrix[0].size();
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
      pair<int, int> curr;
      curr = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int new_r = curr.first + dir[i][0];
        int new_c = curr.second + dir[i][1];
        if (new_r >= 0 && new_c >= 0 && new_r < row && new_c < col) {
          if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
            dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
            q.push({new_r, new_c});
          }
        }
      }
    }
    return dist;
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
  vector<vector<int>> input{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> output;
  output = sol.updateMatrix(input);
  traverse(output);
  return 0;
}