class Solution {
    static int isPossible(int N, int arr[]) {
           long sum=0;
       for(int i=0;i<N;i++)sum+=arr[i];
       return sum%3==0?1:0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int arr[] = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(isPossible(N, arr));
    }
}