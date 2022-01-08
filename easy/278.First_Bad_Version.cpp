#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int version)
{
    int bad = 4;
    if (version == bad)
        return true;
    return false;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << sol.firstBadVersion(n) << endl;

    return 0;
}