#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] == nums[i])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int array[1] = {1};
    vector<int> input(array, array +1);
    vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << (sol.containsDuplicate(input) ? "true" : "false") << endl;
    return 0;
}