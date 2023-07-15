#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to delete middle element of a stack.
  void deleteMid(stack<int> &s, int sizeOfStack)
  {
    stack<int> temp;
    int mid = sizeOfStack / 2;
    for (int i = 0; i < mid; i++)
    {
      temp.push(s.top());
      s.pop();
    }
    s.pop();

    while (!temp.empty())
    {
      s.push(temp.top());
      temp.pop();
    }
  }
};

int main()
{
  Solution sol;
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  sol.deleteMid(s, 5);
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}