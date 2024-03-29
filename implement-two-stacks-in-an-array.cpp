#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
  int *arr;
  int size;
  int top1, top2;

public:
  twoStacks(int n = 100)
  {
    size = n;
    arr = new int[n];
    top1 = -1;
    top2 = size;
  }

  // Function to push an integer into the stack1.
  void push1(int x)
  {
    top1++;
    arr[top1] = x;
  }

  // Function to push an integer into the stack2.
  void push2(int x)
  {
    top2--;
    arr[top2] = x;
  }

  // Function to remove an element from top of the stack1.
  int pop1()
  {
    if (top1 == -1)
    {
      return -1;
    }
    else
    {
      int val = arr[top1];
      top1--;
      return val;
    }
  }

  // Function to remove an element from top of the stack2.
  int pop2()
  {
    if (top2 == size)
    {
      return -1;
    }
    else
    {
      int val = arr[top2];
      top2++;
      return val;
    }
  }
};

int main()
{
  twoStacks obj;
  int q, queryType, value;
  cin >> q;
  while (q--)
  {
    cin >> queryType >> value;
  }
  return 0;
}