#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

class Solution
{
public:
  long int ans = INT_MIN;
  int get(Node *root)
  {
    if (root == NULL)
      return 0;

    long int left = get(root->left);
    long int right = get(root->right);
    long int cur = root->data;
    ans = max(ans, cur + left + right);
    return left + right + cur;
  }

  // Function to find largest subtree sum.
  int findLargestSubtreeSum(Node *root)
  {
    get(root);
    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 7;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  cout << sol.findLargestSubtreeSum(root) << endl;
}