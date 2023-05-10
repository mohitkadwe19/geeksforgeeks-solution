#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalCuts(int N, int K, vector<int> &A)
  {
    vector<int> pref(N, 0);
    pref[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
      pref[i] = min(pref[i + 1], A[i]);
    }
    int maxi = A[0];
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
      if (maxi + pref[i] >= K)
        ans++;
      maxi = max(maxi, A[i]);
    }
    return ans;
  }
};

int main()
{
  int N = 5, K = 3;
  vector<int> A = {4, 2, 1, 3, 5};
  Solution obj;
  cout << obj.totalCuts(N, K, A) << endl;
  return 0;
}