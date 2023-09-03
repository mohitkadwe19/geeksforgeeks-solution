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

class Solution
{
public:
  // Return True if the given trees are isomotphic. Else return False.
  bool isIsomorphic(Node *root1, Node *root2)
  {
    if (root1 == NULL && root2 == NULL)
    {
      return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
      return false;
    }
    if (root1->data != root2->data)
    {
      return false;
    }
    if (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left))
    {
      return true;
    }
    if (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right))
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Node *root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);

  root1->left->left = new Node(4);
  root1->left->right = new Node(5);

  root1->right->left = new Node(6);
  root1->right->right = new Node(7);

  Solution obj;
  cout << obj.isIsomorphic(root1, root1) << endl;
  return 0;
}