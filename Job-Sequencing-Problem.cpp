#include <bits/stdc++.h>
using namespace std;

struct Job
{
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
  // Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n)
  {
    // your code here
    sort(arr, arr + n, [](Job a, Job b)
         { return a.profit > b.profit; });
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
    {
      max_deadline = max(max_deadline, arr[i].dead);
    }
    vector<int> ans(max_deadline + 1, -1);
    int count = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = arr[i].dead; j > 0; j--)
      {
        if (ans[j] == -1)
        {
          ans[j] = arr[i].id;
          count++;
          profit += arr[i].profit;
          break;
        }
      }
    }
    return {count, profit};
  }
};

int main()
{
  int N = 4;
  Job arr[N];
  arr[0].id = 1;
  arr[0].dead = 4;
  arr[0].profit = 20;
  arr[1].id = 2;
  arr[1].dead = 1;
  arr[1].profit = 10;

  arr[2].id = 3;
  arr[2].dead = 1;
  arr[2].profit = 40;
  arr[3].id = 4;
  arr[3].dead = 1;
  arr[3].profit = 30;

  Solution ob;
  vector<int> ans = ob.JobScheduling(arr, N);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
