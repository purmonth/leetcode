#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans = nums;
        for(int i = 0;i < nums.size();i ++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    //int array[] = {0, 2, 1, 5, 3, 4};
    int array[] = {5, 0, 1, 2, 3, 4};
    vector<int> input(array, array + 6);
    vector<int> output = sol.buildArray(input);
    vector<int>::iterator it_i;
    for (it_i = output.begin(); it_i != output.end(); ++it_i)
        cout << *it_i << " ";
    return 0;
}