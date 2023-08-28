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

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    if (temp->data == temp->next->data)
    {
      temp->next = temp->next->next;
    }
    else
    {
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(20);
  head->next->next->next->next = new Node(40);
  head->next->next->next->next->next = new Node(50);

  head = removeDuplicates(head);
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  return 0;
}