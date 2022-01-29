#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int revert = 0;
        if (x < 0 || (!(x % 10) && x != 0))
        {
            return false;
        }
        while (x > revert)
        {
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        return x == revert || (revert / 10) == x;
    }
};

int main()
{
    Solution sol;
    int input = 10;
    cout << (sol.isPalindrome(input) ? "true" : "false");
    return 0;
}