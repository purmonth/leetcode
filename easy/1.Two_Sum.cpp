#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        map<int, int> dict;
        map<int, int>::iterator iter;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {

            iter = dict.find(target - nums[i]);
            // cout << iter->first << " " << iter->second;
            //  printf("(%d,%d)", iter->first, iter->second);
            if (iter != dict.end())
            {                                // num found
                ans.push_back(iter->second); // nums find in dict (smaller)
                ans.push_back(i);            // current index (bigger)
                return ans;
            }
            else
            { // iter == dict.end(), not found
                dict[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int a[4] = {2, 7, 11, 15};
    int target = 9;
    vector<int> v(a, a + 4);

    // 1. 使用足標運算子 function member - at
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;

    // 2. 使用 iterator
    vector<int>::iterator it_i;
    for (it_i = v.begin(); it_i != v.end(); ++it_i)
        cout << *it_i << " ";
    cout << endl;

    for (int i = 0; i < sol.twoSum(v, target).size(); i++)
        cout << sol.twoSum(v, target)[i] << " ";
        
    return 0;
}
