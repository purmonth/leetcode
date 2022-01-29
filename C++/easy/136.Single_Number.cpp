#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int output = 0;
    for(int i = 0;i < nums.size();i ++){
        output = output ^ nums[i];
    }
    return output;
  }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  int array[3] = {2, 2, 1};
  vector<int> input(array, array + 3);
  cout << sol.singleNumber(input) << endl;

  return 0;
}