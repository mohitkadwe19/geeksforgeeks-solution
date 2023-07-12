#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // You need to complete this fucntion

  long long power(int N, int R)
  {
    if (R == 0)
      return 1;
    if (R == 1)
      return N;
    long long temp = power(N, R / 2);
    if (R % 2 == 0)
      return (temp * temp) % 1000000007;
    else
      return (((temp * temp) % 1000000007) * N) % 1000000007;
  }
};

int main()
{
  Solution sol;
  int N = 2, R = 2;
  cout << sol.power(N, R) << endl;
  return 0;
}