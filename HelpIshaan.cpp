#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPrime(int n)
  {
    if (n < 2)
    {
      return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0)
      {
        return false;
      }
    }
    return true;
  }
  int NthTerm(int N)
  {

    if (isPrime(N))
    {
      return 0;
    }
    int i = 1;
    while (true)
    {
      if (isPrime(N - i) || isPrime(N + i))
      {
        return i;
      }
      i++;
    }
  }
};

int main()
{
  Solution sol;
  int n = 10;
  cout << sol.NthTerm(n) << endl;
  return 0;
}