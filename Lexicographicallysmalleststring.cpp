#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string lexicographicallySmallest(string S, int k)
  {
    int n = S.size();
    if ((n & (n - 1)))
    {
      k *= 2;
    }
    else
    {
      k /= 2;
    }

    if (k >= n)
    {
      return "-1";
    }

    string ans;
    for (int i = 0; i < n; i++)
    {
      while (k && !ans.empty() && ans.back() > S[i])
      {
        k--;
        ans.pop_back();
      }
      ans += S[i];
    }

    while (k--)
    {
      ans.pop_back();
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  string S = "fooland";
  int k = 2;
  cout << sol.lexicographicallySmallest(S, k) << endl;
  return 0;
}