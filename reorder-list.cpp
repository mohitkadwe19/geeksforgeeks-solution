#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  void reorderList(Node *head)
  {
    vector<int> temp;
    Node *ptr = head;
    int i = 0, j = 0, l = 0;
    while (ptr != NULL)
    {
      temp.push_back(ptr->data);
      ptr = ptr->next;
      i++;
    }
    while (j < i)
    {
      if (j % 2 == 0)
      {
        head->data = temp[l];
        l++;
      }
      else
      {
        head->data = temp[i - l];
      }
      j++;
      head = head->next;
    }
  }
};

int main()
{
  Solution sol;
  Node *head = NULL;
  head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  sol.reorderList(head);
  for (int i = 0; i < 5; i++)
  {
    cout << head->data << " ";
    head = head->next;
  };
  return 0;
}