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
这道题使用前序遍历，判断当前节点的左子节点是不是叶子节点，如果是叶子节点，就将该左叶子节点的值累加起来。
 */
class Solution {
private:
    int sum = 0;
    void traversal(TreeNode* node){
        if (node == NULL) return;
        if (node->left == NULL && node->right== NULL) return;
        if (node->left && !node->left->left && !node->left->right) { // 左子树就是一个左叶子的情况
            sum += node->left->val;
        }
         traversal(node->left);    // 左
         traversal(node->right);  // 右
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root);
        return sum;
    }
};
