#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;
  Node(int data)
  {
    this->data = data;
    this->left = this->right = NULL;
  }
};

class Solution
{
public:
  Node *solve(string &s, int &i)
  {
    int n = s.size();
    int num = 0;
    for (; i < n && (s[i] >= '0' && s[i] <= '9'); i++)
      num = num * 10 + (s[i] - '0');
    Node *root = new Node(num);
    if (s[i] == '(')
    {
      // skip opening bracket
      i++;
      root->left = solve(s, i);
    }
    if (s[i] == '(')
    {
      // skip opening bracket
      i++;
      root->right = solve(s, i);
    }
    // skip closing bracket
    i++;
    return root;
  }

  // function to construct tree from string
  Node *treeFromString(string str)
  {
    int i = 0;
    return solve(str, i);
  }
};

int main()
{

  Solution sol;
  string str = "1(2)(3)";
  Node *root = sol.treeFromString(str);
  cout << root->data << " " << root->left->data << " " << root->right->data << endl;
  return 0;
}