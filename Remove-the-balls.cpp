#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int finLength(int N, vector<int> color, vector<int> radius)
  {
    stack<int> st1, st2;

    for (int i = 0; i < N; i++)
    {
      if (!st1.empty() && !st2.empty())
      {
        if (st1.top() != color[i] || st2.top() != radius[i])
        {
          st1.push(color[i]);
          st2.push(radius[i]);
        }
        else
        {
          st1.pop();
          st2.pop();
        }
      }
      else
      {
        st1.push(color[i]);
        st2.push(radius[i]);
      }
    }
    return st1.size();
  }
};

int main()
{
  int N = 3;
  vector<int> color = {1, 2, 3};
  vector<int> radius = {1, 2, 3};
  Solution obj;
  cout << obj.finLength(N, color, radius);
  return 0;
}