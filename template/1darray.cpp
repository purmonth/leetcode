#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
};

int main()
{
    Solution sol;
    int array[] = {};
    vector<int> input(array, array);
    vector<int>::iterator it;

    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";

    return 0;
}