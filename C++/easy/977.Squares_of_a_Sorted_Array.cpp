#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = nums[i] * nums[i];
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    int array[5] = {-4, -1, 0, 3, 10};
    vector<int> input(array, array + 5);
    vector<int>::iterator it;

    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";

    cout << endl;
    for (int i = 0; i < sol.sortedSquares(input).size(); i++)
        cout << sol.sortedSquares(input)[i] << " ";

    return 0;
}