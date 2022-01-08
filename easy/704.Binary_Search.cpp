#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0,mid;
        int right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int target = 2;
    int array[6] = {-1, 0, 3, 5, 9, 12};
    vector<int> input(array, array);
    cout << sol.search(input, target) << endl;

    return 0;
}