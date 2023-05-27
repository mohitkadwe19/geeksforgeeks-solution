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
  void modifier(Node *fst, Node *&slo)
  {
    if (fst == NULL)
    {
      return;
    }
    modifier(fst->next, slo);
    int data = slo->data;
    slo->data = fst->data - slo->data;
    fst->data = data;
    slo = slo->next;
  }

  struct Node *modifyTheList(struct Node *head)
  {
    Node *fast = head, *slow = head;
    while (fast)
    {
      fast = fast->next;
      if (fast)
      {
        fast = fast->next;
      }
      if (fast && fast->next)
      {
        slow = slow->next;
      }
    }
    if (fast == NULL)
    {
      fast = slow->next;
    }
    else
    {
      fast = slow->next->next;
    }
    slow = head;
    modifier(fast, slow);
    return head;
  }
};

int main()
{
  int N = 5;
  int arr[] = {1, 2, 3, 4, 5};
  struct Node *head = NULL;
  struct Node *temp = head;
  for (int i = 0; i < N; i++)
  {
    if (head == NULL)
    {
      head = temp = new Node(arr[i]);
    }
    else
    {
      temp->next = new Node(arr[i]);
      temp = temp->next;
    }
  }
  Solution ob;
  head = ob.modifyTheList(head);
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}
