#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

class Solution
{
public:
  /*You are required to complete this method*/
  int maxDepth(Node *root)
  {
    if (root == NULL)
      return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};

int main()
{

  Node *root = new Node;
  root->data = 1;
  root->left = new Node;
  root->left->data = 2;
  root->right = new Node;
  root->right->data = 3;
  root->left->left = new Node;
  root->left->left->data = 4;
  root->left->right = new Node;
  root->left->right->data = 5;

  Solution obj;
  cout << obj.maxDepth(root) << endl;
  return 0;
}