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
 这道题是递归中包含着回溯，由于是从根节点到叶子节点的顺序递归，本题应该使用前序遍历。
 比较tricky的是，要在数字中间加->。解决办法是将path存为vector<int>形式，再最后存到result里之前，转换成满足题目要求的输出。
 */
class Solution {
    void traversal(TreeNode* node, vector<int> &path, vector<string> &result){
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            string s;
            s += to_string(path[0]);
            for(int i = 1; i < path.size(); i++){
                s += "->";
                s += to_string(path[i]);
            }
            result.push_back(s);
        }
        if(node->left){
            traversal(node->left, path, result);
            path.pop_back();
        }
        if(node->right){
            traversal(node->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root == nullptr) return result;
        traversal(root, path, result);
        return result;        
    }
};