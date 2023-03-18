#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long solveMap(vector<int> &A, int N, int M)
  {
    unordered_map<int, int> map;
    int cur = 0;
    long tot = 0, ans = 0;
    map[cur] = 1;

    for (int i = 0; i < N; i++)
    {
      int x;
      if (A[i] >= M)
        x = 1;
      else
        x = -1;

      if (x == -1)
        tot -= map[cur - 1];
      else
        tot += map[cur];

      cur += x;
      ans += tot;
      map[cur] = map[cur] + 1;
    }

    return ans;
  }

  long countSubarray(int N, vector<int> &A, int M)
  {
    long v1 = solveMap(A, N, M);
    long v2 = solveMap(A, N, M + 1);
    return (v1 - v2);
  }
};

int main()
{
  int N = 5, M = 2;
  vector<int> A = {2, 1, 3, 5, 4};
  Solution ob;
  cout << ob.countSubarray(N, A, M) << endl;
  return 0;
}