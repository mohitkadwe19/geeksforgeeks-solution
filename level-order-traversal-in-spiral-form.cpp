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

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
  int rev = 1;
  vector<int> ans;
  deque<Node *> q;
  q.push_back(root);
  while (!q.empty())
  {
    int sz = q.size();
    while (sz--)
    {
      Node *curr;
      if (rev)
      {
        curr = q.back();
        q.pop_back();
        if (curr->right)
        {
          q.push_front(curr->right);
        }
        if (curr->left)
        {
          q.push_front(curr->left);
        }
      }
      else
      {
        curr = q.front();
        q.pop_front();
        if (curr->left)
        {
          q.push_back(curr->left);
        }
        if (curr->right)
        {
          q.push_back(curr->right);
        }
      }
      ans.push_back(curr->data);
    }
    rev = !rev;
  }
  return ans;
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(8);
  root->left->right = new Node(7);
  root->right->left = new Node(9);

  vector<int> ans = findSpiral(root);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}