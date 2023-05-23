#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

class Solution
{
public:
  Node *solve(int pre[], int preMirror[], int &size, unordered_map<int, int> &m, int &index, int start, int end)
  {
    if (start > end || index > size)
    {
      return NULL;
    }
    if (index == size || start == end)
    {
      Node *temp = new Node(pre[index]);
      index++;
      return temp;
    }
    Node *temp = new Node(pre[index]);
    index++;
    int i = m[pre[index]];
    temp->left = solve(pre, preMirror, size, m, index, i, end);
    temp->right = solve(pre, preMirror, size, m, index, start + 1, i - 1);
    return temp;
  }
  Node *constructBinaryTree(int pre[], int preMirror[], int size)
  {
    // Code here
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
      m[preMirror[i]] = i;
    }
    int i = 0;
    size = size - 1;
    return solve(pre, preMirror, size, m, i, 0, size);
  }
};

int main()
{
  Node *root = NULL;
  int pre[] = {1, 2, 4, 5, 3, 6, 7};
  int preMirror[] = {1, 3, 7, 6, 2, 5, 4};
  int size = sizeof(pre) / sizeof(pre[0]);
  Solution obj;
  root = obj.constructBinaryTree(pre, preMirror, size);
  return 0;
}