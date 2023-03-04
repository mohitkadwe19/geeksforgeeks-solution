#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long int> minimumSquares(long long int L, long long int B)
  {
    long long int n = 1;
    long long int k = 1;
    k = __gcd(L, B);
    n = (L * B) / (k * k);
    return {n, k};
  }
};

int main()
{
  long long L = 2, B = 4;
  Solution ob;
  vector<long long int> ans = ob.minimumSquares(L, B);
  return 0;
}