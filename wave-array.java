class Solution {
    public static void convertToWave(int n, int[] a) {
        int temp=0;
        int i=0;
        while(i<n-1)
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            i+=2;
        }
    }
    public static void main(String[] args){
        int n=n = 5;
        int[] a= {1,2,3,4,5};
        convertToWave(n,a);
    }
}