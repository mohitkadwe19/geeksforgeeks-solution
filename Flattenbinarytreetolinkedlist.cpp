#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

class Solution
{
public:
  void flatten(Node *root)
  {
    if (root == NULL || (root->left == NULL && root->right == NULL))
      return;

    if (root->left != NULL)
    {
      flatten(root->left);

      Node *tmpRight = root->right;
      root->right = root->left;
      root->left = NULL;

      Node *t = root->right;
      while (t->right != NULL)
        t = t->right;

      t->right = tmpRight;
    }

    flatten(root->right);
  }
  void printTree(Node *root)
  {
    if (root == NULL)
      return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
  }
};

int main()
{
  Solution sol;
  Node *root = new Node();
  root->data = 1;
  root->left = new Node();
  root->left->data = 2;
  root->right = new Node();
  root->right->data = 5;
  root->left->left = new Node();
  root->left->left->data = 3;
  root->left->right = new Node();
  root->left->right->data = 4;
  root->right->right = new Node();
  root->right->right->data = 6;
  sol.flatten(root);
  sol.printTree(root);
  return 0;
}