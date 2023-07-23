#include <bits/stdc++.h>
using namespace std;

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
  // Function to sort a linked list of 0s, 1s and 2s.
  Node *segregate(Node *head)
  {

    int count[3] = {0, 0, 0};
    Node *ptr = head;
    while (ptr != NULL)
    {
      count[ptr->data] += 1;
      ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
      if (count[i] == 0)
        ++i;
      else
      {
        ptr->data = i;
        --count[i];
        ptr = ptr->next;
      }
    }
    return head;
  }
};
int main()
{
  Solution ob;
  Node *head = new Node(2);
  head->next = new Node(2);
  head->next->next = new Node(1);
  head->next->next->next = new Node(2);

  cout << ob.segregate(head);
  return 0;
}