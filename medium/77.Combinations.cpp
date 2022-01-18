#include <iostream>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> ans;
  // n = 4;k = 2;
  int N, K;
  void findCombination(int start, vector<int> &row) {
    if (row.size() == K) {
      ans.push_back(row);
      return;
    }

    if (N - start + 1 + row.size() >= K) {
      for (int i = start; i <= N; i++) {
        row.push_back(i);
        findCombination(i + 1, row);
        row.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> row = vector<int>();
    N = n;
    K = k;
    findCombination(1, row);
    return ans;
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
  int n = 4;
  int k = 2;
  vector<vector<int>> input{{}};
  traverse(sol.combine(n, k));
  return 0;
}