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
  Node *LCA(Node *root, int n1, int n2)
  {
    if (root->data > n1 && root->data > n2)
      return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
      return LCA(root->right, n1, n2);
    else
      return root;
  }
};

int main()
{
  Solution s;
  Node *root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(7);
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->right->left = new Node(6);

  int K = 3;
  Node *ans = s.LCA(root, 3, 5);
  cout << ans->data << endl;

  return 0;
}