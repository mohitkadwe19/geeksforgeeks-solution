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
  int intersectPoint(Node *head1, Node *head2)
  {
    Node *temp1 = head1;
    Node *temp2 = head2;
    int count1 = 0, count2 = 0;
    while (temp1 != NULL)
    {
      count1++;
      temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
      count2++;
      temp2 = temp2->next;
    }
    int diff = abs(count1 - count2);
    if (count1 > count2)
    {
      while (diff--)
      {
        head1 = head1->next;
      }
    }
    else
    {
      while (diff--)
      {
        head2 = head2->next;
      }
    }
    while (head1 != NULL && head2 != NULL)
    {
      if (head1 == head2)
      {
        return head1->data;
      }
      head1 = head1->next;
      head2 = head2->next;
    }
    return -1;
  }
};

int main()
{
  Node *head1 = new Node(10);
  head1->next = new Node(20);
  head1->next->next = new Node(30);
  head1->next->next->next = new Node(40);
  head1->next->next->next->next = new Node(50);
  head1->next->next->next->next->next = new Node(60);

  Node *head2 = new Node(5);
  head2->next = new Node(15);
  head2->next->next = head1->next->next->next;

  Solution ob;
  cout << ob.intersectPoint(head1, head2) << endl;
  return 0;
}