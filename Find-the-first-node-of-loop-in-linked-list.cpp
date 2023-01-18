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
  // Function to find first node if the linked list has a loop.
  int findFirstNode(Node *head)
  {
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        break;
      }
    }
    if (slow != fast)
    {
      return -1;
    }
    slow = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow->data;
  }
};

int main()
{
  Solution sol;
  struct Node *head = new Node(50);
  head->next = new Node(20);
  head->next->next = new Node(15);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(10);

  cout << sol.findFirstNode(head) << endl;
  return 0;
}