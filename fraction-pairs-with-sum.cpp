#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countFractions(int n, int numerator[], int denominator[])
  {

    unordered_map<double, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      int gcd = __gcd(numerator[i], denominator[i]);

      double nm = numerator[i] / gcd;
      double dm = denominator[i] / gcd;

      double x = (dm - nm) / dm;
      double y = (nm / dm);

      if (mp[x] > 0)
        count = count + mp[x];

      mp[y]++;
    }

    return count;
  }
};

int main()
{
  int N = 4;
  int numerator[N] = {1, 2, 3, 4};
  int denominator[N] = {2, 4, 6, 8};
  Solution ob;
  cout << ob.countFractions(N, numerator, denominator) << endl;
  return 0;
}