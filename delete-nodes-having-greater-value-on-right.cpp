#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  Node *compute(Node *head)
  {
    if (!head || !head->next)
      return head;
    Node *temp = head;

    while (temp->next != NULL)
    {
      if (temp->next->data > temp->data)
      {
        temp->data = temp->next->data;
        temp->next = temp->next->next;
        temp = head;
      }
      else
        temp = temp->next;
    }
    return head;
  }
};

int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  head->next->next->next->next = new Node(50);

  Solution ob;
  head = ob.compute(head);
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}