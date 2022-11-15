#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubsequences(string S, string W)
  {
    int i = 0;
    int count = 0;
    while (i < S.size())
    {
      int k = 0;
      for (int j = i; j < S.size(); j++)
      {
        if (W[k] == S[j])
        {
          if (k == 0)
            i = j + 1;
          k++;
          S[j] = '1';
        }
        if (k == W.size())
        {
          break;
        }
      }

      if (k == W.size())
      {
        count++;
      }
      else
      {
        break;
      }
    }

    return count;
  }
};

int main()
{

  Solution sol;
  string S = "abcdrtbwerrcokokokd", W = "bcd";
  cout << sol.numberOfSubsequences(S, W) << endl;
}