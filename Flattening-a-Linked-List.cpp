#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x)
  {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

class Solution
{
public:
  Node *merge(Node *a, Node *b)
  {
    if (a == NULL)
      return b;
    if (b == NULL)
      return a;

    Node *result;
    if (a->data < b->data)
    {
      result = a;
      result->bottom = merge(a->bottom, b);
    }
    else
    {
      result = b;
      result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
  }
  Node *flatten(Node *root)
  {
    if (root == NULL || root->next == NULL)
      return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
  }
};

int main()
{
  Solution obj;
  struct Node *root = new Node(5);
  root->next = new Node(10);
  root->next->next = new Node(19);
  root->next->next->next = new Node(28);
  root->next->next->next->next = new Node(35);
  root->next->next->next->next->next = new Node(40);
  root->next->next->next->next->next->next = new Node(45);
  root->next->next->next->next->next->next->next = new Node(50);
  root->next->next->next->next->next->next->next->next = new Node(55);
  root->next->next->next->next->next->next->next->next->next = new Node(60);
  root->next->next->next->next->next->next->next->next->next->next = new Node(65);
  root->bottom = new Node(7);
  root->bottom->bottom = new Node(8);
  root->bottom->bottom->bottom = new Node(30);
  root->bottom->bottom->bottom->bottom = new Node(40);
  root->bottom->bottom->bottom->bottom->bottom = new Node(45);
  root->bottom->bottom->bottom->bottom->bottom->bottom = new Node(60);
  root->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(70);
  root->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(80);
  root->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(90);
  root->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(100);

  root->next->bottom = new Node(20);
  root->next->bottom->bottom = new Node(22);
  root->next->bottom->bottom->bottom = new Node(50);
  root->next->bottom->bottom->bottom->bottom = new Node(55);
  root->next->bottom->bottom->bottom->bottom->bottom = new Node(57);
  root->next->bottom->bottom->bottom->bottom->bottom->bottom = new Node(58);
  root->next->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(60);
  root->next->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(62);
  root->next->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(63);

  cout << "Flattened Linked List is: ";
  Node *head = obj.flatten(root);
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->bottom;
  }
  return 0;
}