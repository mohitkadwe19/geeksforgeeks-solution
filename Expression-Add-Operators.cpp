#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void find(int ind, string s, int target, vector<string> &ans, string tmp, long long prev, long long res)
  {
    if (ind == s.size())
    {
      if (res == target)
      {
        ans.push_back(tmp);
      }

      return;
    }
    string st = "";
    long long curr = 0;
    for (int i = ind; i < s.size(); i++)
    {
      if (i > ind && s[ind] == '0')
      {
        break;
      }
      st += s[i];
      curr = curr * 10 + s[i] - '0';
      if (ind == 0)
      {
        find(i + 1, s, target, ans, tmp + st, curr, curr);
      }
      else
      {
        find(i + 1, s, target, ans, tmp + "+" + st, curr, res + curr);
        find(i + 1, s, target, ans, tmp + "-" + st, -curr, res - curr);
        find(i + 1, s, target, ans, tmp + "*" + st, prev * curr, res - prev + prev * curr);
      }
    }
    return;
  }

  vector<string> addOperators(string s, int target)
  {
    vector<string> ans;
    string tmp = "";
    long long prev = 0;
    find(0, s, target, ans, tmp, prev, 0);
    return ans;
  }
};

int main()
{
  string S = "123";
  int target = 6;
  Solution obj;
  vector<string> res = obj.addOperators(S, target);
  for (auto i : res)
    cout << i << " ";
  cout << endl;
}