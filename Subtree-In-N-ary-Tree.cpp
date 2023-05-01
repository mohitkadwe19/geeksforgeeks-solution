#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  vector<Node *> children;
  Node(int x)
  {
    data = x;
  }
};

class Solution
{
public:
  string dfs(Node *root, unordered_map<string, int> &ump, int &ans)
  {
    if (!root)
    {
      return "#";
    }
    string str = "";
    for (auto x : root->children)
    {
      str += dfs(x, ump, ans) + ',';
    }
    string s = str + to_string(root->data);
    if (ump[s] == 1)
    {
      ans++;
    }
    ump[s]++;
    return s;
  }
  int duplicateSubtreeNaryTree(Node *root)
  {
    // Code here
    int ans = 0;
    unordered_map<string, int> ump;
    dfs(root, ump, ans);
    return ans;
  }
};

int main()
{
  Node *root = new Node(1);
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(4));
  root->children[0]->children.push_back(new Node(5));

  Solution s;
  cout << s.duplicateSubtreeNaryTree(root) << endl;
  return 0;
}