#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int nextHappy(int N)
  {
    unordered_set<int> s;
    int n = N + 1, i = N + 1;
    s.insert(n);

    while (1)
    {
      int sum = 0;
      while (n > 0)
      {
        sum += ((n % 10) * (n % 10));
        n /= 10;
      }
      n = sum;

      if (n == 1)
        break;
      else if (s.find(n) != s.end())
        n = ++i;
      else
        s.insert(n);
    }
    return i;
  }
};

int main()
{
  int N = 8;
  Solution ob;
  cout << ob.nextHappy(N) << endl;
  return 0;
}