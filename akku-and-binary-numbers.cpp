#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void precompute()
  {
  }

  long long solve(long long l, long long r)
  {
    long long ans = 0;

    for (int i = 0; i < 63; i++)
    {

      for (int j = i + 1; j < 63; j++)
      {

        for (int k = j + 1; k < 63; k++)
        {

          long long curr = 0;

          curr |= (1l << i);

          curr |= (1l << j);

          curr |= (1l << k);

          if (curr >= l and curr <= r)

            ans++;
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  int L = 11, R = 19;
  cout << s.solve(L, R) << endl;
  return 0;
}