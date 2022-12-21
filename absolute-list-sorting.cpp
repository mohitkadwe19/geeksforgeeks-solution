#include <bits/stdc++.h>
using namespace std;
// The structure of the Linked list Node is as follows:

struct Node
{
  Node *next;
  int data;
};

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution
{

public:
  Node *sortList(Node *head)
  {
    // your code here
    Node *temp = head;
    vector<int> v;
    while (temp != NULL)
    {
      v.push_back(temp->data);
      temp = temp->next;
    }
    sort(v.begin(), v.end());
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
      temp->data = v[i];
      temp = temp->next;
      i++;
    }
    return head;
  }
};

int main()
{
  Solution obj;
  // List: 1, -2, -3, 4, -5
  Node *head = new Node();
  head->data = 1;
  head->next = new Node();
  head->next->data = -2;
  head->next->next = new Node();
  head->next->next->data = -3;
  head->next->next->next = new Node();
  head->next->next->next->data = 4;
  head->next->next->next->next = new Node();
  head->next->next->next->next->data = -5;
  head->next->next->next->next->next = NULL;
  head = obj.sortList(head);
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}