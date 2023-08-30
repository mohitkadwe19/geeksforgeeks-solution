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

/*You are required to complete below method*/
Node *deleteNode(Node *head, int x)
{
  int k = 1;
  if (x == 1)
    return head->next;
  Node *temp = head;
  while (temp != NULL)
  {
    k++;
    if (k == x)
    {
      Node *x = temp->next;
      temp->next = temp->next->next;
      delete x;
    }
    else
      temp = temp->next;
  }
  return head;
}

int main()
{
  Node *head = NULL;
  head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(5);
  deleteNode(head, 3);
  cout << head->next->next->data << endl;
  return 0;
}