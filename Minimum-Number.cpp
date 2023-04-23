#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int gcd(int a, int b)
  {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  };
  int minimumNumber(int n, vector<int> &arr)
  {
    // code here
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = gcd(ans, arr[i]);
    }
    return ans;
  };
};

int main()
{
  int n = 3;
  vector<int> arr = {1, 2, 3};
  Solution ob;
  cout << ob.minimumNumber(n, arr) << endl;
  return 0;
}