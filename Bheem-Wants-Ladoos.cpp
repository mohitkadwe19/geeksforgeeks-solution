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
  int ladoos(Node *root, int home, int k)
  {
    unordered_map<Node *, Node *> mp;

    queue<Node *> q;
    q.push(root);
    Node *findd;
    while (!q.empty())
    {
      int t = q.size();
      while (t--)
      {
        Node *temp = q.front();
        q.pop();
        if (temp->data == home)
        {
          findd = temp;
        }

        if (temp->left)
        {
          q.push(temp->left);
          mp[temp->left] = temp;
        }
        if (temp->right)
        {
          q.push(temp->right);
          mp[temp->right] = temp;
        }
      }
    }
    queue<pair<Node *, int>> qp;
    qp.push({findd, 0});

    map<Node *, bool> vis;
    int sum = 0;

    while (!qp.empty())
    {
      int t = qp.size();

      while (t--)
      {
        Node *temp = qp.front().first;
        int steps = qp.front().second;
        qp.pop();
        if (steps > k)
          continue;

        sum += temp->data;
        //   cout<<temp->data<<" ";

        if (mp.find(temp) != mp.end() and vis.find(temp) == vis.end())
        {
          Node *extra = mp[temp];
          if (vis.find(extra) == vis.end())
            qp.push({extra, steps + 1});
        }

        if (temp->left and vis.find(temp) == vis.end() and vis.find(temp->left) == vis.end())
        {
          qp.push({temp->left, steps + 1});
        }

        if (temp->right and vis.find(temp) == vis.end() and vis.find(temp->right) == vis.end())
        {
          qp.push({temp->right, steps + 1});
        }

        vis[temp] = true;
      }
      // cout<<endl;
    }

    return sum;
  }
};

int main()
{
  Node *root = new Node();
  root->data = 1;
  root->left = new Node();
  root->left->data = 2;
  root->right = new Node();
  root->right->data = 3;

  Solution s;
  cout << s.ladoos(root, 3, 0) << endl;
  return 0;
}