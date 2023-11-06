import java.util.ArrayList;
import java.util.List;

class Solution{
List<Integer> matrixSum(int n, int m, int mat[][], int q, int queries[][])
    {
      int ind;
        ind=0;
        int i,j;
        int sum;
        ArrayList<Integer> list=new ArrayList<>();
        while(q>0)
        {
            sum=0;
            int d=queries[ind][0];
            i=queries[ind][1];
            j=queries[ind][2];
           
            if((i-d)>=0) sum=sum+mat[i-d][j];
            if((i+d)<n) sum=sum+mat[i+d][j];
            if((j-d)>=0 ) sum=sum+mat[i][j-d];
            if((j+d)<m ) sum=sum+mat[i][j+d];
            if((i-d>=0) && (j-d>=0 )) sum=sum+mat[i-d][j-d];
            if((i-d>=0) && (j+d<m  )) sum=sum+mat[i-d][j+d];
            if((i+d<n) && (j-d>=0 )) sum=sum+mat[i+d][j-d];
            if((i+d<n) && (j+d<m )) sum=sum+mat[i+d][j+d];
            if(d==2)
            {
                if((i-d)>=0 && (j-1)>=0) sum=sum+mat[i-d][j-1];
                if((i-d)>=0 && (j+1)<m) sum=sum+mat[i-d][j+1];
                if((i-1)>=0 && (j+d)<m) sum=sum+mat[i-1][j+d];
                if((i+1)<n && (j+d)<m) sum=sum+mat[i+1][j+d];
                if((i+d)<n && (j+1)<m) sum=sum+mat[i+d][j+1];
                if((i+d)<n && (j-1)>=0) sum=sum+mat[i+d][j-1];
                if((i+1)<n && (j-d)>=0) sum=sum+mat[i+1][j-d];
                if((i-1)>=0 && (j-d)>=0) sum=sum+mat[i-1][j-d];
            }
            
            ind++;
            list.add(sum);
            q--;
            
        }
        
        return list;
    }
}