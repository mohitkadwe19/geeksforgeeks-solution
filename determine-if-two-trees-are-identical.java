class Solution {
  // Function to check if two trees are identical.
  boolean checkIdentical(Node root1, Node root2) {

    if (root1 == null && root2 == null) {
      return true;
    }
    if (root1 == null || root2 == null) {
      return false;
    }

    if (root1.data != root2.data) {
      return false;
    }
    return checkIdentical(root1.left, root2.left) && checkIdentical(root1.right, root2.right);
  }

  // Function to check if two trees are identical.
  boolean isIdentical(Node root1, Node root2) {
    // Code Here

    return checkIdentical(root1, root2);
  }

}