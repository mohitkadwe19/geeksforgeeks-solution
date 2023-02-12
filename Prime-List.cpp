#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node(int num)
  {
    val = num;
    next = NULL;
  }
};

class Solution
{
public:
  bool check(int n)
  {
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0)
        return false;

    return n >= 2;
  }
  int getVal(int n)
  {
    if (check(n))
      return n;
    int x = n;
    while (x >= 2 && !check(x))
    {
      x--;
    }
    int y = n;
    while (!check(y))
    {
      y++;
    }
    return x > 1 ? n - x <= y - n ? x : y : y;
  }
  Node *primeList(Node *head)
  {
    Node *curr = head;
    while (curr)
    {
      curr->val = getVal(curr->val);
      curr = curr->next;
    }
    return head;
  }
};

int main()
{
  Node *head = new Node(2);
  head->next = new Node(6);
  head->next->next = new Node(10);
  Solution obj;
  Node *res = obj.primeList(head);
  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}