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
涉及二叉树的高度，采用后序遍历，右叶子节点的高度累积出根节点的高度。涉及二叉树的深度，使用前序遍历，从根节点累积出叶子节点的深度。
本题涉及高度，采用后序遍历。
 */
class Solution {
private:
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if(left == -1 || right == -1) return -1;

        if(abs(left - right) > 1) return -1;
        return max(left, right) + 1; 
    }
public:
    bool isBalanced(TreeNode* root) {
        int res = getHeight(root);
        if(res == -1){
            return false;
        }else{
            return true;
        }
    }
};