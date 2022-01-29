#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals) {
      if (merged.empty() || merged.back()[1] < interval[0]) {
        merged.push_back(interval);
      } else {
        merged.back()[1] = max(merged.back()[1], interval[1]);
      }
    }
    return merged;
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
  vector<vector<int>> input{{1, 4}, {0, 1}};
  traverse(sol.merge(input));
  return 0;
}