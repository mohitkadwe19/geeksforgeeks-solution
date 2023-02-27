#include <bits/stdc++.h>
using namespace std;

// Definition for singly Link List Node
struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  Node *reverse(Node *head, int k)
  {
    Node *prev1 = NULL;
    Node *curr1 = head;

    int i = 0;
    while (i < k)
    {
      Node *forward = curr1->next;

      curr1->next = prev1;
      prev1 = curr1;
      curr1 = forward;
      i++;
    }

    Node *curr2 = curr1;
    Node *prev2 = NULL;

    while (curr2 != NULL)
    {
      Node *forward = curr2->next;

      curr2->next = prev2;
      prev2 = curr2;
      curr2 = forward;
    }

    Node *temp = prev1;

    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = prev2;

    return prev1;
  }
};

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  Solution ob;
  Node *res = ob.reverse(head, 2);
  while (res != NULL)
  {
    cout << res->data << " ";
    res = res->next;
  }
  return 0;
}