//User function Template for javascript


class Node {
  constructor(x) {
    this.data = x;
    this.left = null;
    this.right = null;
  }
}


/**
 * @param {Node} root
*/

class Solution {
  toSumTree(root) {
    if (root === null) {
      return 0;
    }
    let oldVal = root.data;
    root.data = this.toSumTree(root.left) + this.toSumTree(root.right);
    return root.data + oldVal;
  }
}

let root = new Node(10);
let left = new Node(-2);
let right = new Node(6);
root.left = left;
root.right = right;
left.left = new Node(8);
left.right = new Node(-4);

console.log(new Solution().toSumTree(root));