#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
            nums1[i + m] = nums2[i];
        sort(nums1.begin(), nums1.end());
        for (int i = 0; i < m + n; i++)
            cout << nums1[i] << " ";
    }
};

int main()
{
    Solution sol;
    int a[6] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int b[3] = {2, 5, 6};
    int n = 3;
    vector<int> av(a, a + 6);
    vector<int> bv(b, b + 3);
    vector<int>::iterator it;
    sol.merge(av, m, bv, n);
    return 0;
}