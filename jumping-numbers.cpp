#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long jumpingNums(long long X)
  {
    queue<long long> q;

    for (int i = 1; i < 10; i++)
    {
      q.push(i);
    }

    long long ans = INT_MIN;

    while (!q.empty())
    {
      long long front = q.front();

      q.pop();

      if (front > X)
      {
        continue;
      }

      ans = max(ans, front);

      int rem = front % 10;

      if (rem != 0)
      {
        q.push(front * 10 + (rem - 1));
      }
      if (rem != 9)
      {
        q.push(front * 10 + (rem + 1));
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  long long X = 10;
  cout << sol.jumpingNums(X) << endl;
  return 0;
}