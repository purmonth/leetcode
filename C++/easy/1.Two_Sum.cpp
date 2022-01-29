#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> twoSum;
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum == target)
            {
                twoSum.push_back(low);
                twoSum.push_back(high);
                return twoSum;
            }
            if (sum > target)
                --high;
            if (sum < target)
                ++low;
        }
        twoSum.push_back(-1);
        twoSum.push_back(-1);
        return twoSum;
    }
};

int main()
{
    Solution sol;
    int a[4] = {2, 7, 11, 15};
    int target = 9;
    vector<int> v(a, a + 4);
    vector<int>::iterator it_i;
    for (it_i = v.begin(); it_i != v.end(); ++it_i)
        cout << *it_i << " ";
    cout << endl;

    for (int i = 0; i < sol.twoSum(v, target).size(); i++)
        cout << sol.twoSum(v, target)[i] << " ";

    return 0;
}
