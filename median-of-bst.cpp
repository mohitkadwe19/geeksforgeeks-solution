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

// your task is to complete the Function
// Function should return median of the BST
void inorder(Node *root, vector<int> &res)
{
  if (root == NULL)
    return;
  inorder(root->left, res);
  res.push_back(root->data);
  inorder(root->right, res);
}
float findMedian(struct Node *root)
{
  // Code here
  vector<int> res;
  inorder(root, res);
  int n = res.size();
  float sum = 0;
  if (n % 2 == 0)
  {
    return (res[n / 2 - 1] + res[(n / 2)]) / 2.0;
  }
  return res[n / 2];
}

int main()
{
  Node *root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(7);
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->right->left = new Node(6);
  root->right->right = new Node(8);

  cout << findMedian(root);
  return 0;
}