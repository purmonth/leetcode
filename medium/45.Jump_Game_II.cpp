#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int jumps = 0, currentJumpEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      farthest = max(farthest, i + nums[i]);
      if (i == currentJumpEnd) {
        jumps++;
        currentJumpEnd = farthest;
      }
    }
    return jumps;
  }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  int array[5] = {2, 3, 1, 1, 4};
  vector<int> input(array, array + 5);
  cout << sol.jump(input) << endl;

  return 0;
}