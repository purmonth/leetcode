#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = 10000;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
            }
            else
            {
                max_profit = max(max_profit, prices[i] - min);
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution sol;
    int array[6] = {7, 1, 5, 3, 2, 1};
    vector<int> input(array, array + 6);
    vector<int>::iterator it;

    for (it = input.begin(); it != input.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl
         << sol.maxProfit(input) << endl;

    return 0;
}