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
  int minDiff(Node *root, int K)
  {
    int minDiff = INT_MAX;
    Node *curr = root;
    while (curr)
    {
      if (curr->data == K)
        return 0;
      else if (curr->data > K)
      {
        minDiff = min(minDiff, abs(curr->data - K));
        curr = curr->left;
      }
      else
      {
        minDiff = min(minDiff, abs(curr->data - K));
        curr = curr->right;
      }
    }
    return minDiff;
  }
};

int main()
{
  Solution sol;
  Node *root = new Node(9);
  root->left = new Node(4);
  root->right = new Node(17);
  root->left->left = new Node(3);
  root->left->right = new Node(6);
  root->left->right->left = new Node(5);
  root->left->right->right = new Node(7);

  root->right->right = new Node(22);
  root->right->right->left = new Node(20);

  int K = 18;
  cout << sol.minDiff(root, K) << endl;
  return 0;
}