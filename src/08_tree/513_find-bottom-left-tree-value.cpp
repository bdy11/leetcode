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
本题适合使用二叉树的层序遍历。二叉树的层序遍历需要借助一个queue来实现。
层序遍历时，将每层第一个节点的值，保存在将要作为返回值的变量中。遍历到最后一层时，这层的第一个节点就是结果。
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == 0){
                    ans = node->val;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return ans;        
    }
};