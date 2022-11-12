#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPrime(int num)
  {
    if (num == 1)
      return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
        return false;
    }
    return true;
  }

  string isSumOfTwo(int N)
  {
    // code here
    int i = 2;
    while (i <= N / 2)
    {
      if (isPrime(i) && isPrime(N - i))
      {
        return "Yes";
      }
      i++;
    }
    return "No";
  }
};

int main()
{
  Solution sol;
  int N = 34;
  cout << sol.isSumOfTwo(N) << endl;
  return 0;
}