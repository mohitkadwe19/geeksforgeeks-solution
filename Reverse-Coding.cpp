#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumOfNaturals(int n)
  {
    long ans = ((long)n * (long)(n + 1));
    ans /= 2;
    return ans % 1000000007;
  }
};

int main()
{
  int n = 6;
  Solution ob;
  cout << ob.sumOfNaturals(n) << endl;
  return 0;
}