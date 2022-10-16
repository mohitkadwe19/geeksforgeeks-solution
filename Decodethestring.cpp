#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string decodedString(string s)
  {
    stack<int> num;
    stack<string> str;
    string res = "";
    int i = 0;
    while (i < s.length())
    {
      if (isdigit(s[i]))
      {
        int count = 0;
        while (isdigit(s[i]))
        {
          count = count * 10 + (s[i] - '0');
          i++;
        }
        num.push(count);
      }
      else if (s[i] == '[')
      {
        str.push(res);
        res = "";
        i++;
      }
      else if (s[i] == ']')
      {
        string temp = str.top();
        str.pop();
        int count = num.top();
        num.pop();
        for (int j = 0; j < count; j++)
        {
          temp += res;
        }
        res = temp;
        i++;
      }
      else
      {
        res += s[i];
        i++;
      }
    }
    return res;
  }
};

int main()
{
  Solution sol;
  string s = "3[b2[ca]]";
  cout << sol.decodedString(s) << endl;
  return 0;
}