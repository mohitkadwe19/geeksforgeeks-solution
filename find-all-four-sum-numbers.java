class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int k) {
      
      ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        Arrays.sort(arr);
        for(int s=0;s<arr.length-3;s++){
            if(s>0&&arr[s]==arr[s-1]){
                continue;
            }
            for(int s2=s+1;s2<arr.length-2;s2++){
                if(s2>s+1&&arr[s2]==arr[s2-1]){
                    continue;
                }
                int s3=s2+1;
                int s4=arr.length-1;
                while(s3<s4){
                    int sum=arr[s]+arr[s2]+arr[s3]+arr[s4];
                    if(sum==k){
                        ArrayList<Integer> ls = new ArrayList<>();
                        ls.add(arr[s]);
                        ls.add(arr[s2]);
                        ls.add(arr[s3]);
                        ls.add(arr[s4]);
                        list.add(ls);
                        while(s3<s4&&arr[s3]==arr[s3+1]){
                            s3++;
                        }
                        while(s3<s4&arr[s4]==arr[s4-1]){
                            s4--;
                        }
                        s3++;
                        s4--;
                    }
                    if(sum<k){
                         while(s3<s4&&arr[s3]==arr[s3+1]){
                            s3++;
                        }
                        s3++;
                    }
                    if(sum>k){
                        while(s3<s4&arr[s4]==arr[s4-1]){
                            s4--;
                        }
                        s4--;
                    }
                }
            }
        }
        return list;


    }
    public static void main(String[] args){
        int[] arr = {10, 2, 3, 4, 5, 7, 8};
        int k = 23;
        System.out.println(fourSum(arr, k));
    }
}