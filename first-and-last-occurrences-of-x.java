class GFG
{
    ArrayList<Integer> find(int arr[], int n, int x)
    {
        int s=-1,e=-1;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==x && s==-1)  s=i;
            if(arr[arr.length-i-1]==x && e==-1)  e=arr.length-i-1;
        }
        ArrayList<Integer> a=new ArrayList<>();
        a.add(s);
        a.add(e);
        return a;
    }
    public static void main(String[] args)
    {
      int n=9, x=5;
      int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
      GFG g = new GFG();
      ArrayList<Integer> ans = g.find(arr, n, x);
      System.out.println(ans);

    }
}
