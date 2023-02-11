#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getMinimumDays(int N, string S, vector<int> &P)
  {
    int j = 0;
    for (int i = 0; i < N; i++)
    {
      while (S[i] == S[i + 1] && S[i] != '?')
      {
        S[P[j]] = '?';
        j++;
      }
    }
    return j;
  }
};

int main()
{
  int N = 4;
  string S = "aabb";
  vector<int> P = {2, 1, 3, 0};
  Solution ob;
  cout << ob.getMinimumDays(N, S, P) << endl;
  return 0;
}