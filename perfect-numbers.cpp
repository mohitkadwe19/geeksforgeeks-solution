#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPerfectNumber(long long N)
  {
    long long sum = 0;

    if (N == 1)
    {
      return 0;
    }
    for (int i = 1; i <= sqrt(N); i++)
    {
      if (N % i == 0)
      {
        sum = sum + i;
        if (i * i != N && N / i != N)
        {

          sum = sum + N / i;
        }
      }
    }
    if (sum == N)
    {
      return 1;
    }

    return 0;
  }
};

int main()
{
  int N = 6;
  Solution ob;
  cout << ob.isPerfectNumber(N) << endl;
  return 0;
}