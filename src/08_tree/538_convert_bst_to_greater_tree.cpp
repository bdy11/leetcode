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
这道题使用双指针法，用pre记录前一个节点的值，然后按后中左的顺序递归即可
*/
class Solution {
private:
    int pre = 0;
    void traversal( TreeNode* node){
        if(node == nullptr) return;
        traversal(node->right);
        node->val += pre;
        pre = node->val;
        traversal(node->left);

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};