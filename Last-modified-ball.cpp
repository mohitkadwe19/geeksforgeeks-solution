#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int N, vector<int> A)
  {
    for (int i = N - 1; i >= 0; i--)
    {

      if (A[i] < 9)
      {

        return i + 1;
      }
    }
  }
};

int main()
{
  Solution sol;
  int N = 4;
  vector<int> A = {3, 1, 4, 5};
  cout << sol.solve(N, A);
  return 0;
}