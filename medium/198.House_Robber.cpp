#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int total = nums.size();
    if (total == 0) return 0;
    vector<int> maxRobbedAmount(total + 1, 0);
    maxRobbedAmount[total] = 0;
    maxRobbedAmount[total - 1] = nums[total - 1];
    for (int i = total - 2; i >= 0; i--) {
      maxRobbedAmount[i] =
          max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i]);
    }
    return maxRobbedAmount[0];
  }
};


int main() {
  Solution sol;
  int array[4] = {1, 2, 3, 1};
  vector<int> input(array, array + 4);
  cout << sol.rob(input);
  return 0;
}