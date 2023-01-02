#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

class Solution
{
public:
  vector<int> maximumValue(Node *node)
  {
    vector<int> ans;
    if (node == NULL)
    {
      return ans;
    }

    queue<Node *> q;

    q.push(node);

    while (!q.empty())
    {

      int n = q.size();
      int max = INT_MIN;
      for (int i = 0; i < n; i++)
      {
        Node *temp = q.front();
        q.pop();
        if (temp->data > max)
        {
          max = temp->data;
        }
        if (temp->left != NULL)
        {
          q.push(temp->left);
        }
        if (temp->right != NULL)
        {
          q.push(temp->right);
        }
      }
      ans.push_back(max);
    }
    return ans;
  }
};

int main()
{
  struct Node *node = new Node;
  node->data = 1;
  node->left = new Node;
  node->left->data = 2;
  node->right = new Node;
  node->right->data = 3;

  Solution ob;

  vector<int> ans = ob.maximumValue(node);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}