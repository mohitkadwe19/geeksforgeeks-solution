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
  int count = 0;

  unordered_set<int> func(Node *root, int k)
  {
    unordered_set<int> s;
    if (!root)
      return s;

    auto l = func(root->left, k);

    auto r = func(root->right, k);

    // if any of the left sub tree or right sub tree has more than k elements, then
    // no need to combine them because even after combining the result will be same.
    if (r.size() > k)
      return r;
    if (l.size() > k)
      return l;

    for (auto x : l)
    {
      s.insert(x);
    }
    for (auto x : r)
      s.insert(x);

    s.insert(root->data);

    if (s.size() <= k)
    {
      count++;
    }

    return s;
  }

  int goodSubtrees(Node *root, int k)
  {
    func(root, k);
    return count;
  }
};

int main()
{
  int k = 2;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  Solution obj;
  cout << obj.goodSubtrees(root, k) << endl;
  return 0;
}