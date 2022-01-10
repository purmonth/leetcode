#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ret;
        ret.reserve(numRows);
        for (int n = 0; n < numRows; n++)
        {
            vector<int> row;
            row.push_back(1); 
            row.reserve(n + 1);
            for (int k = 1; k <= n; k++)
            {
                row.push_back(row.back() * (n + 1 - k) / k);
            }
            ret.push_back(row);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    int numRows = 10;
    vector<vector<int> > input;
    input = sol.generate(numRows);
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            cout << (input[i][j] ? input[i][j] : 'x') << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
1
1 1
1 2 1
1 3 3 1
1 3 6 3 1
*/