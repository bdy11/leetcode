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
 这道题在删除节点的时候考虑以下5种情况
 1. 找不到这个节点
 2. 该节点的左右子树为空, 删掉该节点，返回空
 3. 该节点左子树为空，右子树不为空，那么删掉该节点，返回该节点的右子树
 4. 该节点右子树为空，左子树不为空，那么删掉该节点，返回该节点的左子树
 5. 节点的左右子树都不为空，那么将左子树放到右子树的最左侧，删掉该节点，返回该节点的右子树
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            if(root ->left == nullptr && root->right != nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left != nullptr && root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left != nullptr && root->right != nullptr){
                TreeNode* temp = root->left;
                TreeNode* node = root->right;
                while(node->left != nullptr){
                    node = node->left;
                }
                node->left = temp;
                node = root->right;
                delete root;
                return node;
            }
        }

        if(root->val < key) root->right = deleteNode(root->right, key);
        if(root->val > key) root->left = deleteNode(root->left, key);

        return root;
    }
};