#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumInteger(int N, vector<int> &A)
  {
    if (N == 1)
    {
      return A[0];
    }

    long s = 0;

    for (int i = 0; i < N; i++)
    {
      s += A[i];
    }

    sort(A.begin(), A.end());

    long val = INT_MAX;

    for (int i = 0; i < N; i++)
    {
      long x = A[i];
      if (s <= N * x)
      {
        val = min(val, x);
      }
    }
    return val;
  }
};

int main()
{
  int N = 3;
  vector<int> A = {1, 3, 2};
  Solution ob;
  cout << ob.minimumInteger(N, A) << endl;
  return 0;
}