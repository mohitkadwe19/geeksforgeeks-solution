class Solution
{
    //Function to find the maximum money the thief can get.
    public int FindMaxSum(int arr[], int n)
    {
        int prevMax = 0; // Maximum money stolen from the previous house
        int currMax = arr[0]; // Maximum money stolen from the current house
        
        for (int i = 1; i < n; i++)
        {
            int temp = currMax;
            currMax = Math.max(currMax, prevMax + arr[i]);
            prevMax = temp;
        }
        
        return currMax;
    }
    public static void main(String[] args){
        int[] arr = {5, 5, 10, 100, 10, 5};
        int n = arr.length;
        System.out.println(FindMaxSum(arr, n));
    }
}
