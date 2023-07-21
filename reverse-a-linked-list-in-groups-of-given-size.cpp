#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  struct node *reverse(struct node *head, int k)
  {
    node *prev = NULL;
    node *curr = head;
    node *forward;
    int count = 0;
    while (curr and count < k)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
      count++;
    }
    if (forward)
    {
      head->next = reverse(forward, k);
    }
    return prev;
  }
};

int main()
{
  Solution sol;
  node *head = new node(50);
  head->next = new node(20);
  head->next->next = new node(15);
  head->next->next->next = new node(4);
  head->next->next->next->next = new node(10);
  head->next->next->next->next->next = new node(32);

  cout << sol.reverse(head, 3) << endl;
  return 0;
}