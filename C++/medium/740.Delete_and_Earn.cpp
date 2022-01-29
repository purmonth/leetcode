#include <iostream>
#include <vector>
using namespace std;

class Solution {
  int count(vector<int> nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target - 1) {
        nums.erase(nums.begin() + i);
        i--;
      }
      if (nums[i] == target + 1) {
        nums.erase(nums.begin() + i);
        i--;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    return sum;
  }

 public:
  int deleteAndEarn(vector<int>& nums) {
    int max_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      max_sum = max(max_sum, count(nums, nums[i]));
    }
    return max_sum;
  }
};

int main() {
  Solution sol;
  int array[3] = {3, 4, 2};
  vector<int> input(array, array + 3);
  // traverse(input);
  cout << sol.deleteAndEarn(input);
  return 0;
}