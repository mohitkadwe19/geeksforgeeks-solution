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
    left = right = NULL;
  }
};

class Solution
{
public:
  int maxGCD(Node *root)
  {
    int maxGcd = 0;

    queue<Node *> q;

    if (root == NULL)
    {
      return 0;
    }

    q.push(root);

    int ans = 0;

    while (q.size())
    {

      auto curr = q.front();

      q.pop();

      int flag1 = 0, flag2 = 0;

      if (curr->left)
      {
        q.push(curr->left);
        flag1 = 1;
      }

      if (curr->right)
      {
        q.push(curr->right);
        flag2 = 1;
      }

      if (flag1 && flag2)
      {
        int currentGcd = __gcd(curr->left->data, curr->right->data);

        if (currentGcd >= maxGcd)
        {
          maxGcd = currentGcd;
          ans = curr->data;
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout << sol.maxGCD(root) << endl;
}