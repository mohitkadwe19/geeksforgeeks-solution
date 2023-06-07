#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> leastPrimeFactor(int n)
  {
    vector<int> lpf(n + 1, 0);
    lpf[1] = 1;
    for (int i = 2; i <= n; i++)
    {
      if (lpf[i] == 0)
      {
        lpf[i] = i;
        for (int j = i * i; j <= n; j += i)
        {
          if (lpf[j] == 0)
            lpf[j] = i;
        }
      }
    }
    return lpf;
  }
};

int main()
{
  int N = 6;
  Solution ob;
  vector<int> ans = ob.leastPrimeFactor(N);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}