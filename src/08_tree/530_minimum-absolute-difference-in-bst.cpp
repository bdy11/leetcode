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
二叉搜索树的特性是，将二叉搜索树按左中右顺序遍历，二叉搜索树中元素按递增排列。
依据这个性质，按中序遍历二叉搜索树。
定义一个全局变量pre保存前一个节点，初始为空。
按中序遍历每个节点，比较当前节点和前一个节点的差值，记录最小值。
*/

class Solution {
private:
    int result = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        traversal(cur->left);
        if(pre != nullptr) {
            result = min(result, cur->val - pre->val );
        }
        pre = cur;
        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};