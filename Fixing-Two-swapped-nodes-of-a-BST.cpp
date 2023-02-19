#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

class Solution
{
public:
  void inorder(struct Node *root, struct Node *&first, struct Node *&second, struct Node *&prev)
  {
    if (root == NULL)
      return;
    inorder(root->left, first, second, prev);
    if (prev != NULL && root->data < prev->data)
    {
      if (first == NULL)
        first = prev;
      second = root;
    }
    prev = root;
    inorder(root->right, first, second, prev);
  }
  struct Node *correctBST(struct Node *root)
  {
    struct Node *first = NULL, *second = NULL, *prev = NULL;
    inorder(root, first, second, prev);
    swap(first->data, second->data);
    return root;
  }
};

int main()
{
  struct Node root = {10, NULL, NULL};
  struct Node n1 = {5, NULL, NULL};
  struct Node n2 = {8, NULL, NULL};
  struct Node n3 = {2, NULL, NULL};
  struct Node n4 = {20, NULL, NULL};

  root.left = &n1;
  root.right = &n2;
  n1.left = &n3;
  n2.right = &n4;

  Solution ob;
  struct Node *res = ob.correctBST(&root);
  cout << res->data << " " << res->left->data << " " << res->right->data << " " << res->left->left->data << " " << res->right->right->data << endl;
  return 0;
}