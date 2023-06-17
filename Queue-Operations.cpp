#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // map<int,int>um;
  void insert(queue<int> &q, int k)
  {
    // Your code here
    q.push(k);
  }

  // Function to find frequency of an element
  // return the frequency of k
  int findFrequency(queue<int> &q, int k)
  {
    queue<int> temp = q;
    int count = 0;
    while (temp.size() != 0)
    {
      int x = temp.front();
      temp.pop();
      if (x == k)
      {
        count++;
      }
    }
    if (count == 0)
    {
      return -1;
    }
    else
    {
      return count;
    }
  }
};

int main()
{
  int N = 8;
  int arr[] = {1, 2, 3, 4, 5, 2, 3, 1};
  int k = 4;

  queue<int> q;
  Solution obj;
  for (int i = 0; i < N; i++)
  {
    obj.insert(q, arr[i]);
  }
  cout << obj.findFrequency(q, k) << endl;
  return 0;
}