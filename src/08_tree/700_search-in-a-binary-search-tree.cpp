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
二叉搜索树的基础题目。
首先判断节点是否是空，如果是空则返回空
然后比较节点的值与目标值的大小，如果目标值大于节点的值，那么就去节点的右侧继续搜索，
如果目标值小于节点的值，那么去左侧继续搜索。
否则，目标值等于节点的值，那么返回该节点。
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val > val){
            return searchBST(root->left, val);
        }else if(root->val < val){
            return searchBST(root->right, val);
        }else{
            return root;
        }
    }
};