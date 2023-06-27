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
  struct Node *makeUnion(struct Node *head1, struct Node *head2)
  {
    set<int> st; // define set
    Node *curr = head1;
    while (curr)
    {
      st.insert(curr->data); // insert in set
      curr = curr->next;
    }
    curr = head2;
    while (curr)
    {
      st.insert(curr->data); // insert in set
      curr = curr->next;
    }
    Node *temp = new Node(-1);
    Node *head3 = temp;
    for (auto it : st)
    {
      temp->next = new Node(it);
      temp = temp->next;
    }
    return head3->next;
  }
};

int main()
{
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);

  Node *head2 = new Node(1);
  head2->next = new Node(2);
  head2->next->next = new Node(3);

  Solution obj;
  Node *res = obj.makeUnion(head1, head2);
  while (res != NULL)
  {
    cout << res->data << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}