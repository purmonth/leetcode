#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = -100000;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < nums[i])
            {
                sum = nums[i];
            }
            max = (max > sum ? max : sum);
        }
        return max;
    }
};

int main()
{
    Solution sol;
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> input(array, array + 9);
    // int array[2] = {-2, 1};
    // vector<int> input(array, array + 2);
    // int array[1] = {1};
    // vector<int> input(array, array + 1);
    vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl
         << sol.maxSubArray(input) << endl;

    return 0;
}