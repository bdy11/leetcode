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
 按照中左右的顺序处理
 节点处理逻辑如下:
 如果该节点为空，那么返回空
 如果该节点的值小于low，那么进入节点的右子树，剪枝并返回。
 如果该节点的值大于high，那么进入节点的左子树，剪枝并返回。

 否则，分别对左右子树进行剪枝，并返回
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return root;
        if(root->val < low){
            root = trimBST(root->right, low, high);
            return root;
        }
        if(root->val > high){
            root = trimBST(root->left, low, high);
            return root;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
