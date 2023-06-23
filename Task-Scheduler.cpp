#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int leastInterval(int N, int K, vector<char> &tasks)
  {
    vector<int> freq(26, 0);
    for (auto task : tasks)
      freq[task - 'A']++;
    sort(freq.begin(), freq.end());
    int maxFreq = freq[25] - 1;
    int idleSlots = maxFreq * K;
    for (int i = 24; i >= 0; i--)
      idleSlots -= min(freq[i], maxFreq);
    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
  }
};

int main()
{
  int N = 6, K = 2;
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  Solution obj;
  cout << obj.leastInterval(N, K, tasks) << endl;
  return 0;
}