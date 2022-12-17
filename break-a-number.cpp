#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int waysToBreakNumber(int N)
  {
    long long int x = N;

    return (int)((3 * x + (x - 1) * (x - 2) / 2) % 1000000007);
  }
};

int main()
{
  int N = 2;
  Solution mySolution;
  cout << mySolution.waysToBreakNumber(N) << endl;
  return 0;
}