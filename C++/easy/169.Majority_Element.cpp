#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

void traverse(vector<int> input){
    vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
}

int main()
{
    Solution sol;
    int array[3] = {3,2,3};
    vector<int> input(array, array+3);
    cout << sol.majorityElement(input) << endl;
    return 0;
}