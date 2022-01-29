#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
};

void traverse(vector<int> input){
    vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
}

int main()
{
    Solution sol;
    int array[] = {};
    vector<int> input(array, array);
    traverse(input);

    return 0;
}