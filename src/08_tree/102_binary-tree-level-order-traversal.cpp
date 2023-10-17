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
二叉树的层序遍历需要借助que来实现。从根节点开始，每一层遍历前，需要计算该层的节点数，用于控制当前层遍历的结束。
每一层遍历过程是，从queue中取front位置的node，如果该node的左右节点不为空，那么就将左右节点装入queue中。


*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;       //额外空间
        vector<vector<int>> result;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();  //不要用que.size()，因为que.size()是不断变化的
            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};