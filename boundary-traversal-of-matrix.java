class Solution
{
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    static ArrayList<Integer> boundaryTraversal(int matrix[][], int n, int m)
    {
        ArrayList<Integer> ans=new ArrayList<>();
        
        if(n==1) {
            for(int i=0;i<m;i++) {
                ans.add(matrix[0][i]);
            }
            return ans;
        }
        
        if(m==1) {
            for(int i=0;i<n;i++) {
                ans.add(matrix[i][0]);
            }
            return ans;
        }
        
        for(int i=0;i<m;i++) {
            ans.add(matrix[0][i]);
        }
        
        for(int i=1;i<n-1;i++) {
            ans.add(matrix[i][m-1]);
        }
        
        for(int i=m-1;i>=0;i--) {
            ans.add(matrix[n-1][i]);
        }
        
        for(int i=n-2;i>0;i--) {
            ans.add(matrix[i][0]);
        }
        
        return ans;
    }
    public static void main(String[] args){
        int matrix[][] = {{1,2,3},{4,5,6},{7,8,9}};
        int n = 3;
        int m = 3;
        ArrayList<Integer> ans = boundaryTraversal(matrix, n, m);
        System.out.println(ans);
    }
}