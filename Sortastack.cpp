#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
  stack<int> s;
  void sort();
};

void SortedStack::sort()
{
  // Your code goes here
  stack<int> temp;
  while (!s.empty())
  {
    int top = s.top();
    s.pop();
    while (!temp.empty() && temp.top() > top)
    {
      s.push(temp.top());
      temp.pop();
    }
    temp.push(top);
  }
  s = temp;
}

void print_stack(stack<int> s)
{
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main()
{
  SortedStack stack;
  stack.s.push(1);
  stack.s.push(2);
  stack.s.push(3);
  stack.sort();
  print_stack(stack.s);
  return 0;
}