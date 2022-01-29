#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> curr, prev = {1};

    for (int i = 1; i <= rowIndex; i++) {
      curr.assign(i + 1, 1);

      for (int j = 1; j < i; j++)
        curr[j] = prev[j - 1] + prev[j];

      prev = move(curr);  // This is O(1)
    }

    return prev;
  }
};

int main()
{
    Solution sol;
    int numRows = 3;
    vector<int> input;
    input = sol.getRow(numRows);
    for(int i = 0;i < input.size();i ++){
        cout << input[i] << " ";
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