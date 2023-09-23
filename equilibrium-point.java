class Solution {

    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {
        long sum=0,x=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        for(int i=0;i<n;i++){
            x+=arr[i];
            if(sum==x)return i+1;
            sum-=arr[i];
        }
        return -1;
    }
    public static void main(String[] args){
        long arr[] = {1, 3, 5, 2, 2};
        int n = arr.length;
        System.out.println(equilibriumPoint(arr, n));
    }
}
