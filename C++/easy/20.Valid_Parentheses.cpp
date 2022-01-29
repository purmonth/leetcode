#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int stack_top = 10;
        char stack[10000];
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                stack[stack_top] = s[i];
                stack_top++;
                sum++;
                break;
            case ')':
                if (stack[stack_top - 1] == '(')
                {
                    stack[stack_top] = '\0';
                    stack_top--;
                    sum--;
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (stack[stack_top - 1] == '[')
                {
                    stack[stack_top] = '\0';
                    stack_top--;
                    sum--;
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (stack[stack_top - 1] == '{')
                {
                    stack[stack_top] = '\0';
                    stack_top--;
                    sum--;
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        if (sum != 0)
            return false;
        return true;
    }
};

int main()
{
    Solution sol;
    string input = "([])]{}";
    cout << (sol.isValid(input) ? "true" : "false") << endl;
    return 0;
}
