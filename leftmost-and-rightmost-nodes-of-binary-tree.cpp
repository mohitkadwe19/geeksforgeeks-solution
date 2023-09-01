#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

void printCorner(Node *root)
{
  queue<Node *> q;
  q.push(root);
  int k = 0;
  Node *curr = NULL;
  while (!q.empty())
  {
    k = q.size();
    for (int i = 0; i < k; i++)
    {
      curr = q.front();
      q.pop();
      if (i == 0 || i == k - 1)
      {
        cout << curr->data << " ";
      }
      if (curr->left)
      {
        q.push(curr->left);
      }
      if (curr->right)
      {
        q.push(curr->right);
      }
    }
  }
}

int main()
{
  struct Node *root = new Node();
  root->data = 1;
  root->left = new Node();
  root->left->data = 2;
  root->right = new Node();
  root->right->data = 3;

  printCorner(root);
  return 0;
}