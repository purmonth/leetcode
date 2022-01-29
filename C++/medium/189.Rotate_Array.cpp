#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> a = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            a[(k + i) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = a[i];
        }
    }
};

int main()
{
    Solution sol;
    int array[] = {};
    vector<int> input(array, array);
    vector<int>::iterator it;

    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}