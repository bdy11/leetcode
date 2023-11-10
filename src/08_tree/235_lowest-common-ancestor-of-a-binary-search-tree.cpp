/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
这道题解题要利用二叉搜索树的性质。从根节点开始，向叶子节点递归，如果某个叶子节点的值位于[p,q]范围内，那么该节点就是lowest commen ancestor
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val ){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};