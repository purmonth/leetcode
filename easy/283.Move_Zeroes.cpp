#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> output;
        output.reserve(nums.size());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count++;
            if (nums[i])
                output.push_back(nums[i]);
        }
        for (int i = 0; i < count; i++)
            output.push_back(0);
        nums = output;
    }
};

int main()
{
    Solution sol;
    int array[5] = {0, 1, 0, 3, 12};
    vector<int> input(array, array + 5);
    vector<int>::iterator it;
    sol.moveZeroes(input);
    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";

    return 0;
}