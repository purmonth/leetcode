#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> newMatrix(r, vector<int>(c, 0));
        int originalRaw = nums.size();
        int originalColumn = nums[0].size();
        if(originalRaw * originalColumn != r * c)
            return nums;

        int newRaw = 0, newColumn = 0;
        for(int i = 0; i < originalRaw; i++)
        {
            for(int j = 0; j < originalColumn; j++)
            {
                newMatrix[newRaw][newColumn] = nums[i][j];
                newColumn++;
                if(newColumn == c)
                {
                    newColumn = 0;
                    newRaw++;
                }
            }
        }
        return newMatrix; 
    }
};



int main()
{
    Solution sol;
    int row = 2;
    int col = 4;
    vector<vector<int> > vect;
    vect.resize(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> vect[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int> > ans;
    ans = sol.matrixReshape(vect, row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}