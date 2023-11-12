class Solution
{
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    public static boolean isRotated(String str1, String str2)
    {
       
      if(str1.equals(str2))
      return false;
      
      StringBuffer s=new StringBuffer(str1);
       
       if((s.reverse().toString()).equals(str2))
       return false;

       str1=str1+str1;

       return str1.contains(str2);

    }
    
}