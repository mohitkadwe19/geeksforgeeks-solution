#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> leafNodes(int arr[], int N)
  {
    vector<int> v;

    stack<int> st;

    st.push(arr[0]);

    for (int i = 1; i < N; i++)
    {
      if (st.top() > arr[i])
      {
        st.push(arr[i]);
      }
      else
      {
        int flag = 0;
        int temp = st.top();
        while (st.empty() == false && st.top() < arr[i])
        {
          st.pop();
          flag++;
        }
        st.push(arr[i]);
        if (flag >= 2)
        {
          v.push_back(temp);
        }
      }
    }
    v.push_back(arr[N - 1]);
    return v;
  }
};

int main()
{
  Solution sol;
  int arr[] = {3, 2, 4};
  int N = 3;
  vector<int> ans = sol.leafNodes(arr, N);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}