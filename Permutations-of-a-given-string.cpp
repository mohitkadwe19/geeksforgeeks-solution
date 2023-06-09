#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> find_permutation(string S)
  {
    vector<string> res;
    sort(S.begin(), S.end());
    do
    {
      res.push_back(S);
    } while (next_permutation(S.begin(), S.end()));
    return res;
  }
};

int main()
{
  string s = "ABC";
  Solution obj;
  vector<string> res = obj.find_permutation(s);
  for (auto x : res)
    cout << x << " ";
  cout << endl;
  return 0;
}