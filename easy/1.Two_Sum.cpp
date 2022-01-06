#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> ret;
        int size = nums.size();
        int diff;
        map<int, int> m;
        for (int i = 0; i < size; i++)
        {
            diff = target - nums[i];
            if (m.find(diff) != m.end() && m.find(diff)->second != i)
            {
                ret.push_back(i);
                ret.push_back(m.find(diff)->second);
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
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
