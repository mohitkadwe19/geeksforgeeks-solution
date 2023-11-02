class Solution {
    int minDist(int a[], int n, int x, int y) {
      int dx=-1,dy=-1,ans=Integer.MAX_VALUE;
        
        for(int i=0;i<n;i++){
            
            if(a[i]==x) dx=i;
            if(a[i]==y) dy=i;
            
            if(dx!=-1 && dy!=-1) ans= Math.min(ans,(int)Math.abs(dx-dy));
            
        }
        
        return ans==Integer.MAX_VALUE ? -1 : ans;
    }
}