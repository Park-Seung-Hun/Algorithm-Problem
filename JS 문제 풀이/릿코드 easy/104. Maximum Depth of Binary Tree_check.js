/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {

    let max = 0;
    const MDepth = function(node,depth){
        if(node === null) {
            if(max<depth) max=depth;
            return;
        }

        MDepth(node.left,depth+1);
        MDepth(node.right,depth+1);
    }

   MDepth(root,0);

    console.log(max);
    return max;
};
