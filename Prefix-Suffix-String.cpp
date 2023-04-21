#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  struct Trie
  {
    unordered_map<char, Trie *> m;
    bool flag;
  };

  Trie *gen()
  {
    Trie *temp = new Trie;
    temp->flag = false;
    return temp;
  }

  void insert(Trie **root, string s)
  {
    if (*root == NULL)
    {
      *root = gen();
    }
    Trie *temp = *root;
    for (auto i : s)
    {
      if (temp->m.find(i) == temp->m.end())
      {
        temp->m[i] = gen();
      }
      temp = temp->m[i];
    }
    temp->flag = true;
    temp = *root;
    for (int i = s.length() - 1; i >= 0; i--)
    {
      if (temp->m.find(s[i]) == temp->m.end())
      {
        temp->m[s[i]] = gen();
      }
      temp = temp->m[s[i]];
    }
    temp->flag = true;
  }

  int search(Trie *root, string s)
  {
    for (auto i : s)
    {
      if (root->m.find(i) != root->m.end())
      {
        root = root->m[i];
      }
      else
      {
        return 0;
      }
    }
    return 1;
  }

  int prefixSuffixString(vector<string> &s1, vector<string> s2)
  {
    Trie *root = NULL;
    for (auto i : s1)
    {
      insert(&root, i);
    }
    int c = 0;
    for (auto i : s2)
    {
      string s = i;
      reverse(s.begin(), s.end());
      c += (search(root, i) || search(root, s));
    }
    return c;
  }
};

int main()
{
  vector<string> s1 = {"ab", "cd", "ef"};
  vector<string> s2 = {"ab", "cd", "ef"};
  Solution ob;
  cout << ob.prefixSuffixString(s1, s2) << endl;
  return 0;
}