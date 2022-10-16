#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int data;
  ListNode *next;
};

class Solution
{
public:
  ListNode *moveToFront(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *secondLast = NULL;
    ListNode *last = head;

    while (last->next != NULL)
    {
      secondLast = last;
      last = last->next;
    }

    secondLast->next = NULL;
    last->next = head;
    head = last;

    return head;
  }
};

int main()
{
  Solution *sol = new Solution();
  ListNode *head = new ListNode();
  head->data = 2;
  head->next = new ListNode();
  head->next->data = 5;
  head->next->next = new ListNode();
  head->next->next->data = 6;
  head->next->next->next = new ListNode();
  head->next->next->next->data = 2;
  head->next->next->next->next = new ListNode();
  head->next->next->next->next->data = 1;
  head->next->next->next->next->next = NULL;
  ListNode *res = sol->moveToFront(head);
  while (res != NULL)
  {
    cout << res->data << " ";
    res = res->next;
  }
  cout << endl;
}