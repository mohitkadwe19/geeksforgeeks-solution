class Solution {

   static void dfs(int [][]grid,int i,int j,int row,int col){
          int dx[]={-1,0,0,1};
          int dy[]={0,-1,1,0};
        grid[i][j]=2;  //mark as visited
        for(int d=0;d<4;d++){
            int x=i+dx[d];
            int y=j+dy[d];
            if(x>=0 && x<row && y>=0 && y<col&& grid[x][y]==1){
                dfs(grid,x,y,row,col);
            }
        }
        
    }

    int numberOfEnclaves(int[][] grid) {
        
        int row=grid.length;
        if(row<=0){
            return 0;
        }
        int col=grid[0].length;
      
        for(int i=0;i<col;i++){
           
                if(grid[0][i]==1 ){
                   dfs(grid,0,i,row,col);
                }
                if(grid[row-1][i]==1){
                    dfs(grid,row-1,i,row,col);
                }
            
        }
         for(int i=0;i<row;i++){
           
                if(grid[i][0]==1 ){
                   dfs(grid,i,0,row,col);
                }
                if(grid[i][col-1]==1){
                    dfs(grid,i,col-1,row,col);
                }
            
        }
        
        
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 ){
                     
                     count++;
                }
            }
        }
        return count;
        
    }
}