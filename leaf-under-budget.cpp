#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  void traversal(Node *root, int steps, vector<int> &res)
  {

    if (!root)
      return;

    if (!root->left && !root->right)
      res.push_back(steps);

    traversal(root->left, steps + 1, res);
    traversal(root->right, steps + 1, res);
  }

public:
  int getCount(Node *root, int k)
  {
    vector<int> res;
    traversal(root, 1, res);

    sort(res.begin(), res.end());
    int cnt = 0;

    for (auto cost : res)
    {
      if (cost <= k)
      {
        cnt += 1;
        k -= cost;
      }
    }
    return cnt;
  }
};

int main()
{
  Solution sol;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  cout << sol.getCount(root, 2) << endl;
  return 0;
}