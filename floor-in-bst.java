class Solution {
    static int info;
    Solution(){
        info = Integer.MIN_VALUE;
    }
    public static int floor(Node root, int x) {
        inorder(root,x);
        if(info == Integer.MIN_VALUE ){
            return -1;
        }
        return info;
    }

    public static void inorder(Node root,int x){
        if(root == null){
            return;
        }
        if(root.data == x){
            info = x;
        }
        if(root.data<x){
            info = Math.max(root.data,info);
        }
        inorder(root.left,x);
        inorder(root.right,x);
    }

}