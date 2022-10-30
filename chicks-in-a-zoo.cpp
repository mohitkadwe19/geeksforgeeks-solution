#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int NoOfChicks(int n)
  {
    long long total = 1;

    vector<long long> chick(n, 0);

    chick[0] = 1;

    for (int i = 1; i < n; i++)
    {
      if (i >= 6)
      {
        total -= chick[i - 6];
      }
      chick[i] = total * 2;
      total += total * 2;
    }

    return total;
  }
};

int main()
{
  Solution sol;
  int n = 3;
  cout << sol.NoOfChicks(n) << endl;
  return 0;
}