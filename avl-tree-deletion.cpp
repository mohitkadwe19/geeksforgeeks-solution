#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data, height;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    height = 1;
    left = right = NULL;
  }
};

void storeAllNodes(Node *root, vector<int> &nodes, int &key)
{
  // using dfs
  if (root == NULL)
    return;
  // calling recursion
  if (root->left)
  {
    storeAllNodes(root->left, nodes, key);
  }
  if (root->data != key)
    nodes.push_back(root->data);
  if (root->right)
  {
    storeAllNodes(root->right, nodes, key);
  }
}

Node *constructAVLTree(vector<int> &nodes, int l, int r)
{
  // base case
  if (l > r)
  {
    return NULL;
  }
  // calling recursion
  int m = (r + l) / 2;
  Node *ret = new Node(nodes[m]);
  ret->left = constructAVLTree(nodes, l, m - 1);
  ret->right = constructAVLTree(nodes, m + 1, r);
  return ret;
}

Node *deleteNode(Node *root, int key)
{
  vector<int> nodes;
  // using preorder dfs to store all nodes in sorted order
  storeAllNodes(root, nodes, key);
  Node *ret = constructAVLTree(nodes, 0, nodes.size() - 1);
  return ret;
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);

  root = deleteNode(root, 20);
  return 0;
}