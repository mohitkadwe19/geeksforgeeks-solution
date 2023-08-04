#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void Reverse(stack<int> &St)
  {
    queue<int> q;
    while (!St.empty())
    {
      int top = St.top();
      St.pop();
      q.push(top);
    }
    while (!q.empty())
    {
      int top = q.front();
      q.pop();
      St.push(top);
    }
  }
};

int main()
{
  stack<int> St;
  St.push(1);
  St.push(2);
  St.push(3);
  St.push(4);
  St.push(5);

  Solution S;
  S.Reverse(St);
  return 0;
}