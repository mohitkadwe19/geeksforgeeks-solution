import java.util.*;

class Solution
{
    //Function to return sum of upper and lower triangles of a matrix.
    static ArrayList<Integer> sumTriangles(int matrix[][], int n)
    {
        // code here
        ArrayList<Integer> res = new ArrayList<>();
        int upper = 0, lower = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<=j){
                    upper += matrix[i][j];
                }
                if(i>=j){
                    lower += matrix[i][j];
                }
            }
        }
        res.add(upper);
        res.add(lower);
        return res;
    }
}