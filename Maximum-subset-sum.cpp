#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
  long long solve(int n, vector<int> &A, int i, vector<int> &dp)
  {
    if (i >= n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    long long include = A[i] + solve(n, A, i + 1, dp);
    long long exclude = 0;
    if ((i + 1) < n)
    {
      exclude = A[i + 1] + solve(n, A, i + 2, dp);
    }
    return dp[i] = max(include, exclude);
  }
  long long findMaxSubsetSum(int N, vector<int> &A)
  {
    // code here
    vector<int> dp(N + 1, -1);
    return solve(N, A, 0, dp);
  }
};

int main()
{
  int N = 4;
  vector<int> A = {1, 2, 3, 4};
  Solution ob;
  cout << ob.findMaxSubsetSum(N, A) << endl;
  return 0;
}