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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
  void inorder(Node *root, vector<int> &res)
  {
    if (root == NULL)
      return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
  }
  int kthLargest(Node *root, int k)
  {
    // Your code here
    vector<int> res;
    inorder(root, res);

    int n = res.size();
    return res[n - k];
  }
};

int main()
{
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);

  Solution obj;
  cout << obj.kthLargest(root, 3) << endl;
  return 0;
}