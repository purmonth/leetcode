#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> min_sum(cost.size() + 1);
    for (int i = 2; i < min_sum.size(); i++) {
      min_sum[i] =
          min(min_sum[i - 1] + cost[i - 1], min_sum[i - 2] + cost[i - 2]);
    }
    return min_sum[min_sum.size() - 1];
  }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  int array[3] = {10, 15, 20};
  vector<int> input(array, array + 3);
  cout << sol.minCostClimbingStairs(input) << endl;
  return 0;
}