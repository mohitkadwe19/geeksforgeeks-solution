#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countOfSubstrings(string S, int K)
  {
    // code here
    unordered_map<char, int> mp;
    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < S.size())
    {
      mp[S[j]]++;
      if (j - i + 1 == K)
      {
        if (mp.size() == K - 1)
        {
          ans++;
        }
        mp[S[i]]--;
        if (mp[S[i]] == 0)
        {
          mp.erase(S[i]);
        }
        i++;
      }
      j++;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  string S = "abcc";
  int K = 2;
  cout << sol.countOfSubstrings(S, K) << endl;
  return 0;
}