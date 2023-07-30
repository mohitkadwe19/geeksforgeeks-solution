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
  // returns the inorder successor of the Node x in BST (rooted at 'root')
  void solve(Node *root, vector<Node *> &v)
  {
    if (root == NULL)
      return;
    solve(root->left, v);
    v.push_back(root);
    solve(root->right, v);
  }
  Node *inOrderSuccessor(Node *root, Node *x)
  {
    // Your code here
    vector<Node *> v;
    solve(root, v);
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] == x && i + 1 < v.size())
      {
        return v[i + 1];
      }
    }
    return NULL;
  }
};

int main()
{
  Solution sol;
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(4);
  root->left->right = new Node(12);

  Node *ans = sol.inOrderSuccessor(root, root->left->right);
  cout << ans->data << endl;
  return 0;
}