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
  // Function to remove duplicates from unsorted linked list.
  Node *removeDuplicates(Node *head)
  {
    unordered_set<int> st;
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    st.insert(head->data);

    Node *prev = head;
    Node *temp = head->next;

    while (temp != NULL)
    {
      int x = temp->data;
      if (st.find(x) != st.end())
      {
        prev->next = temp->next;
        temp = temp->next;
      }
      else
      {
        st.insert(x);
        prev = temp;
      }
    }
    return head;
  }
};

int main()
{
  Solution s;
  Node *head = new Node(10);
  head->next = new Node(10);
  head->next->next = new Node(20);
  head->next->next->next = new Node(20);
  head->next->next->next->next = new Node(30);
  head->next->next->next->next->next = new Node(30);
  head->next->next->next->next->next->next = new Node(30);

  cout << s.removeDuplicates(head);
  return 0;
}