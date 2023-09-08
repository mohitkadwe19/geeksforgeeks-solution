#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  void preorder(Node *root, vector<int> &vec, int &i, bool check)
  {
    if (root == NULL)
      return;
    preorder(root->left, vec, i, check);
    if (check)
      root->data = vec[i++];
    else
      vec.push_back(root->data);
    preorder(root->right, vec, i, check);
  }
  // The given root is the root of the Binary Tree
  // Return the root of the generated BST
  Node *binaryTreeToBST(Node *root)
  {
    // Your code goes here
    vector<int> vec;
    int i = 0;
    preorder(root, vec, i, false);
    sort(vec.begin(), vec.end());
    preorder(root, vec, i, true);
    return root;
  }
};

int main()
{
  Solution obj;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  Node *ans = obj.binaryTreeToBST(root);
  for (int i = 0; i < 5; i++)
  {
    cout << ans->data << " ";
    ans = ans->right;
  }
  return 0;
}