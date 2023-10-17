/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
用递归法解题。
当前节点深度等于，取左右两个节点，比较大的深度，加一
*/

class Solution {
private:
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        return max(left, right) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

