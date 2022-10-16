#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPrime(int n)
  {
    bool flag = false;

    for (int i = 2; i <= n / 2; ++i)

    {

      if (n % i == 0)

      {

        flag = true;

        break;
      }
    }

    if (!flag)
    {
      return true;
    }

    else
    {
      return false;
    }
  }

  int primeNumber(int n)

  {
    int sum = 0;

    for (int i = 2; i <= n / 2; i++)
    {
      if (n % i == 0)
      {

        bool p = isPrime(i);

        if (p == true)

          sum += i;
      }
    }
    return sum;
  }

  int sumOfAll(int l, int r)
  {
    int sum = 0;

    for (int i = l; i <= r; i++)

    {

      if (i == 1)

        sum += 1;

      else

      {

        bool p = isPrime(i);

        if (p == true)

        {

          sum += i;
        }

        else

        {

          int sumOfPrimeNumber = primeNumber(i);

          sum += sumOfPrimeNumber;
        }
      }
    }

    return sum;
  }
};

int main()
{
  Solution sol;
  int l = 1, r = 6;
  cout << sol.sumOfAll(l, r) << endl;
  return 0;
}