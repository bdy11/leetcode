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
 leaf node的定义是，左右子树都为空
 */
class Solution {
private:
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        //当一个节点的左子树为空，右子树不为空时，不是leaf node
        if(node->left == nullptr && node->right != nullptr) return (1 + right);
        //当一个节点的左子树不为空，右子树为空，该节点不是leaf node
        if(node->left != nullptr && node->right == nullptr) return (1 + left);

        return min(left, right) + 1;
    }
public:
    int minDepth(TreeNode* root) { 
        return getDepth(root);
    }
};