#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
  queue<Node *> q;
  unordered_map<int, int> mp;
  unordered_map<int, int>::iterator ans;
  q.push(root);
  mp.insert({root->data, -1});

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    if (temp->left != NULL)
    {
      q.push(temp->left);
      mp.insert({temp->left->data, temp->data});
    }
    if (temp->right != NULL)
    {
      q.push(temp->right);
      mp.insert({temp->right->data, temp->data});
    }
  }

  for (int i = 0; i < k; i++)
  {
    auto it = mp.find(node);
    if (it != mp.end())
    {
      node = it->second; // Update 'node' with its parent's value
    }
    else
    {
      // If the node is not found in the map, it means the k-th ancestor doesn't exist
      return -1;
    }
  }

  return node;
}

int main()
{
  Node *head;
  Node *one = NULL;
  one->data = 1;
  Node *two = NULL;
  one->data = 2;
  Node *three = NULL;
  one->data = 3;

  head->left = one;
  head->right = two;

  one->left = three;
  one->right = NULL;

  two->left = NULL;
  two->right = NULL;

  three->left = NULL;
  three->right = NULL;

  cout << kthAncestor(head, 1, 3) << endl;
  return 0;
}