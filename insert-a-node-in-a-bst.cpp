#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  Node *insert(Node *node, int data)
  {
    if (node == NULL)
    {
      return new Node(data);
    }
    if (data < node->data)
    {
      node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
      node->right = insert(node->right, data);
    }
    return node;
  }
};

int main()
{
  Node *root = new Node(3);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(4);
  root->right->left = new Node(6);

  Solution obj;
  Node *res = obj.insert(root, 7);
  cout << res->data << endl;
  return 0;
}