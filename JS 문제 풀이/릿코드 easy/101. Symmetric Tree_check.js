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
 * @return {boolean}
 */
var isSymmetric = function(root) {

    const treeSymmetric = function(p,q){
        if(p === null && q === null) return true;

        if((p!==null&&q===null)||(p===null&&q!==null))return false;

        if(p.val!=q.val) return false;

        return treeSymmetric(p.right,q.left) && treeSymmetric(p.left,q.right);
    }

    let check = treeSymmetric(root.left,root.right);

    if(check) return true;
    return false;
};
