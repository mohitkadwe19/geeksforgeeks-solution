#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> displayContacts(int n, string contact[], string s)
  {
    set<string> input;
    for (int i = 0; i < n; i++)
    {
      input.insert(contact[i]);
    }
    n = input.size();
    int s_size = s.size();
    vector<vector<string>> ans(s.size(), vector<string>());
    for (int j = s_size - 1; j >= 0; j--)
    {
      bool value = true;
      set<string>::iterator itr;
      for (itr = input.begin(); itr != input.end(); itr++)
      {
        string cur = *(itr);
        if (cur.find(s) == 0)
        {
          value = false;
          ans[j].push_back(cur);
        }
      }
      if (value)
      {
        ans[j].push_back("0");
      }
      s.pop_back();
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 3;
  string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
  string s = "geeips";
  vector<vector<string>> ans = sol.displayContacts(n, contact, s);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}