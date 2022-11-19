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
  bool areAnagrams(Node *root1, Node *root2)
  {
    if (!root1 && !root2)
      return true;
    if (!root1 || !root2)
      return false;
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
      int n1 = q1.size();
      int n2 = q2.size();
      if (n1 != n2)
        return false;
      vector<int> v1, v2;
      while (n1--)
      {
        Node *temp1 = q1.front();
        q1.pop();
        if (temp1->left)
          q1.push(temp1->left);
        if (temp1->right)
          q1.push(temp1->right);
        v1.push_back(temp1->data);
      }
      while (n2--)
      {
        Node *temp2 = q2.front();
        q2.pop();
        if (temp2->left)
          q2.push(temp2->left);
        if (temp2->right)
          q2.push(temp2->right);
        v2.push_back(temp2->data);
      }
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      if (v1 != v2)
        return false;
    }
    return true;
  }
};

int main()
{
  Solution sol;
  Node *root1 = new Node();
  root1->data = 1;
  root1->left = new Node();
  root1->left->data = 3;
  root1->right = new Node();
  root1->right->data = 2;
  root1->left->left = new Node();
  root1->left->left->data = 5;
  root1->left->right = new Node();
  root1->left->right->data = 4;
  root1->right->left = new Node();
  root1->right->left->data = 6;
  root1->right->right = new Node();
  root1->right->right->data = 7;
  Node *root2 = new Node();
  root2->data = 1;
  root2->left = new Node();
  root2->left->data = 2;
  root2->right = new Node();
  root2->right->data = 3;
  root2->left->left = new Node();
  root2->left->left->data = 4;
  root2->left->right = new Node();
  root2->left->right->data = 5;
  root2->right->left = new Node();
  root2->right->left->data = 6;
  root2->right->right = new Node();
  root2->right->right->data = 7;
  cout << sol.areAnagrams(root1, root2) << endl;
  return 0;
}