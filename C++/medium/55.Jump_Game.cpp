#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) { 
      int last_pos = nums.size()-1;
      for(int i = nums.size()-1;i >=0;i --){
          if(nums[i] + i >= last_pos){
              last_pos = i;
          }
      }
      return last_pos == 0; 
    }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  int array[2] = {2,0};
  vector<int> input(array, array + 2);
  cout << (sol.canJump(input) ? "true" : "false") << endl;

  return 0;
}