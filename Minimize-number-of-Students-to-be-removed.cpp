#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeStudents(int H[], int N)
  {
    vector<int> dp;

    dp.push_back(H[0]);

    for (int i = 1; i < N; i++)
    {
      if (H[i] > dp.back())
      {
        dp.push_back(H[i]);
      }

      int in = lower_bound(dp.begin(), dp.end(), H[i]) - dp.begin();
      dp[in] = H[i];
    }

    return N - dp.size();
  }
};

int main()
{

  int N = 6, arr[] = {9, 1, 2, 3, 1, 5};

  Solution ob;
  cout << ob.removeStudents(arr, N) << endl;

  return 0;
}