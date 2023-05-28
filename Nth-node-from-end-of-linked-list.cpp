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
  int getNthFromLast(Node *head, int n)
  {
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    if (count < n)
      return -1;
    temp = head;
    for (int i = 0; i < count - n; i++)
    {
      temp = temp->next;
    }
    return temp->data;
  }
};

int main()
{
  int n = 2;
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(4);
  head->next->next->next = new Node(5);
  head->next->next->next->next = new Node(6);
  head->next->next->next->next->next = new Node(7);

  Solution ob;
  cout << ob.getNthFromLast(head, n) << endl;
  return 0;
}