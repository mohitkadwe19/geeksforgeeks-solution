class Solution {
    int transitionPoint(int arr[], int n) {
      int left = 0, right = n-1;
        int mid;
        
        int ans = -1;
        
        while(left <= right) {
            mid = left + (right-left)/2;
            
            if(arr[mid] == 0)
                left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
      return ans; 
    }
}