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
这道题难点是如果按前中后顺序遍历，并且记住上一个节点的值。
这种写法应该记住，在其他的题目中也会用到。
首先判断节点是否为空，空的话返回true
然后遍历左子树
如果前一个节点不为空，并且大于等于当前节点，那么可知不满足BST，返回false
将pre赋值为当前节点
然后遍历右子树。
左右子树都返回true，函数才返回true
*/

class Solution {
private: 
    TreeNode* pre = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        bool left = isValidBST(root->left);
        if(pre != nullptr && pre->val >= root->val) return false;

        pre = root;

        bool right = isValidBST(root->right);
        return left && right;
        
    }
};