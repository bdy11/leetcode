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
本题依然使用了二叉树的递归加回溯，采用了二叉树的前序遍历。
首先将root节点的值保存到sum中，遍历叶子节点时，每个叶子节点的值都加到sum上，每次结束对叶子节点的递归时，都把叶子节点的值从sum中减去。
递归函数要有一个返回值，为bool类型。当左右节点返回有一个为true，整个函数就返回true。
递归结束的条件是节点为空节点。
当当前节点的左右节点都为空，且sum的值和target相等时，函数返回true.
 */
class Solution {
private:
    int sum = 0;
    bool traversal(TreeNode* node, int target){
        if(node == nullptr) return false;
        sum += node->val;
        if(node->left == nullptr && node->right ==nullptr && sum == target){
            return true;
        }
        bool left = false;
        bool right = false;
        if(node->left){
            left =traversal(node->left,target);
            sum -= node->left->val;
        }
        if(node->right){
            right = traversal(node->right, target);
            sum -= node->right->val;
        }
        if(left || right) return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root, targetSum);
    }
};