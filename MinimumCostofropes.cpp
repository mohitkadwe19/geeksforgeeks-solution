#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to return the minimum cost of connecting the ropes.
  long long minCost(long long arr[], long long n)
  {
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
      pq.push(arr[i]);
    }
    long long cost = 0;
    while (pq.size() > 1)
    {
      long long first = pq.top();
      pq.pop();
      long long second = pq.top();
      pq.pop();
      cost += first + second;
      pq.push(first + second);
    }
    return cost;
  }
};

int main()
{
  Solution ob;
  int n = 4;
  long long arr[] = {4, 3, 2, 6};
  cout << ob.minCost(arr, n) << endl;
  return 0;
}