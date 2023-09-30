class Solution
{
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(int matrix[][])
    {
        int r=matrix.length,c=matrix[0].length;
        int[] row=new int[r];
        int[] col=new int[c];
        Arrays.fill(row,-1);
        Arrays.fill(col,-1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=1;
                }
            }
        }

    }
    public static void main(String[] args){
        int matrix[][] = {{1,1,1,1,0},{1,1,1,1,0},{1,1,1,1,0},{1,1,1,1,0},{0,0,0,0,0}};
        Solution s = new Solution();
        s.booleanMatrix(matrix);
    }
}