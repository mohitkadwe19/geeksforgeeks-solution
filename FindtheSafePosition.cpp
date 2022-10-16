#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int safePos(int n, int k)
  {
    // code here
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
      ans = (ans + k) % i;
    }
    return ans + 1;
  }
};

int main()
{
  int n = 2, k = 1;
  Solution ob;
  cout << ob.safePos(n, k) << endl;
  return 0;
}