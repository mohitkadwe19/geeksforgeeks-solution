#include <bits/stdc++.h>
using namespace std;

// Definition for singly Link List Node
struct Node
{
  char data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// You can also use the following for printing the link list.
// printList(Node *node);

class Solution
{
public:
  vector<Node *> findAnagrams(struct Node *head, string s)
  {
    // Code here
    vector<Node *> res;
    int n = s.length();
    Node *temp = head;
    while (temp != NULL)
    {
      string str = "";
      Node *t = temp;
      int i = 0;
      while (t != NULL && i < n)
      {
        str += t->data;
        t = t->next;
        i++;
      }
      if (str.length() == n)
      {
        sort(str.begin(), str.end());
        sort(s.begin(), s.end());
        if (str == s)
        {
          res.push_back(temp);
        }
      }
      temp = temp->next;
    }
    return res;
  }
};

int main()
{
  Node *N;
  N = new Node('a');
  N->next = new Node('b');
  N->next->next = new Node('c');
  N->next->next->next = new Node('d');
  N->next->next->next->next = new Node('e');
  N->next->next->next->next->next = new Node('f');

  string s = "abc";
  Solution ob;
  vector<Node *> res = ob.findAnagrams(N, s);
  for (int i = 0; i < res.size(); i++)
  {
    Node *temp = res[i];
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  return 0;
}
