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
  long long int ans = 0;

  Node *find(Node *root, int target)
  {

    if (root == NULL)
    {
      return NULL;
    }
    if (root->data == target)
    {
      return root;
    }

    if (root->data > target)
    {
      return find(root->left, target);
    }
    else if (root->data < target)
    {
      return find(root->right, target);
    }
  }

  void solve(Node *root, int c)
  {
    if (root == NULL)
    {
      return;
    }

    if (c == 0)
    {
      ans += root->data;
    }

    solve(root->left, c - 1);
    solve(root->right, c + 1);
  }

  long long int verticallyDownBST(Node *root, int target)
  {
    Node *tar = find(root, target);

    if (tar == NULL)
    {
      return -1;
    }
    solve(tar, 0);

    return ans - tar->data;
  }
};

int main()
{
  Node *root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(7);
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->right->left = new Node(6);
  root->right->right = new Node(8);

  Solution obj;
  cout << obj.verticallyDownBST(root, 35) << endl;
  return 0;
}