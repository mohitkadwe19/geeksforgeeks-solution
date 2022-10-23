#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int m)
  {
    queue<int> q;
    int ans = 1;

    if (m < 0)
    {
      return 0;
    }
    if (m < 10)
    {
      return m + 1;
    }

    for (int i = 1; i <= 9; i++)
    {
      q.push(i);
    }

    while (!q.empty())
    {
      int digit = q.front();

      q.pop();

      ans++;

      int rem = digit % 10;

      int num1 = digit * 10 + rem - 1;

      int num2 = digit * 10 + rem + 1;

      if (rem == 0)
      {
        if (num2 <= m)
          q.push(num2);
      }
      else if (rem == 9)
      {
        if (num1 <= m)
          q.push(num1);
      }
      else
      {
        if (num1 <= m)

          q.push(num1);

        if (num2 <= m)

          q.push(num2);
      }
    }
    return ans;
  }

  int steppingNumbers(int n, int m)
  {
    return solve(m) - solve(n - 1);
  }
};

int main()
{
  Solution ob;
  int n = 0, m = 21;
  cout << ob.steppingNumbers(n, m) << endl;
  return 0;
}