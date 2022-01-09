#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        nums1.erase(set_intersection(begin(nums1), end(nums1),
                                     begin(nums2), end(nums2), begin(nums1)),
                    end(nums1));
        return nums1;
    }
};

int main()
{
    Solution sol;
    int a1[4] = {1, 2, 2, 1};
    int a2[2] = {2, 2};
    vector<int> v1(a1, a1 + 4);
    vector<int> v2(a2, a2 + 2);
    vector<int>::iterator it;

    for (it = v1.begin(); it != v1.end(); ++it)
        cout << *it << " ";
    cout << endl;
    for (it = v2.begin(); it != v2.end(); ++it)
        cout << *it << " ";
    cout << endl;
    for (it = sol.intersect(v1, v2).begin(); it != sol.intersect(v1, v2).end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}