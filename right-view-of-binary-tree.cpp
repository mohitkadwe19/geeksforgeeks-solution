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

// Should return  right view of tree
class Solution
{
public:
  // Function to return list containing elements of right view of binary tree.
  vector<int> rightView(Node *root)
  {
    vector<int> ans;
    if (root == NULL)
      return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        Node *temp = q.front();
        q.pop();
        if (i == size - 1)
          ans.push_back(temp->data);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }
    return ans;
  }
};

int main()
{
  Solution obj;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<int> ans = obj.rightView(root);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}