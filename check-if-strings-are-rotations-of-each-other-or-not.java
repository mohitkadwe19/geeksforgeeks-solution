class Solution
{
    //Function to check if two strings are rotations of each other or not.
    public static boolean areRotations(String s1, String s2 )
    {
        if(s1.length()!=s2.length())
        {
            return false;
        }
        String temp = s1+s1;
        return temp.contains(s2);
    }
    
}