#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimizeSum(int N, vector<int> arr)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0, su = 0, fs = 0, sc = 0;

    for (int i = 0; i < N; i++)
    {
      pq.push(arr[i]);
    }

    while (pq.size() > 1)
    {
      fs = pq.top();
      pq.pop();
      sc = pq.top();
      pq.pop();
      su = fs + sc;
      pq.push(su);
      ans += su;
    }
    return ans;
  }
};

int main()
{
  Solution obj;
  int N = 4;
  vector<int> arr = {1, 4, 7, 10};
  cout << obj.minimizeSum(N, arr) << endl;
  return 0;
}