#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int largestPrimeFactor(int N)
  {
    int i = 2;
    while (i < N)
    {
      if (N % i == 0)
      {
        N = N / i;
      }
      else
      {
        i++;
      }
    }
    return N;
  }
};

int main()
{
  Solution obj;
  int N = 8;
  cout << obj.largestPrimeFactor(N) << endl;
  return 0;
}