#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;

  Node(int x)
  {
    key = x;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
  {
    if (root == NULL)
      return;

    if (root->key == key)
    {
      if (root->left != NULL)
      {
        Node *temp = root->left;
        while (temp->right)
          temp = temp->right;
        pre = temp;
      }

      if (root->right != NULL)
      {
        Node *temp = root->right;
        while (temp->left)
          temp = temp->left;
        suc = temp;
      }
      return;
    }

    if (root->key > key)
    {
      suc = root;
      findPreSuc(root->left, pre, suc, key);
    }
    else
    {
      pre = root;
      findPreSuc(root->right, pre, suc, key);
    }
  }
};

int main()
{
  Node *root = new Node(15);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->left = new Node(8);
  root->left->right = new Node(12);
  root->right->left = new Node(16);

  int key = 16;

  Solution obj;
  Node *pre = NULL, *suc = NULL;

  obj.findPreSuc(root, pre, suc, key);

  if (pre != NULL)
    cout << "Predecessor is " << pre->key << endl;
  else
    cout << "No Predecessor";

  if (suc != NULL)
    cout << "Successor is " << suc->key;
  else
    cout << "No Successor";

  return 0;
}