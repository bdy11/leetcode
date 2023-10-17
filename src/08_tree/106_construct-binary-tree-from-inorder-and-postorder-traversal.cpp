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
根据中序后续构造二叉树，主要的难点包括
1. 使用中序后续构造二叉树的逻辑
2. 对中序和后续数组如何进行切割

后续数组的最后一个元素，一定是根节点，这个根节点作为中序数组的切割点。
找到这个切割点，将该切割点前的元素装入leftInorder，之后的元素装入rightinorder
切割后续数组是有技巧的。首先要将最后一个节点剔除，因为它是根节点。要明白leftPostorder的size和leftInorder size一样，
rightpostorder和rightinorder size一样。这样可以方便的完成后续数组的切割。
之后就是进行迭代，将子数组继续进行切割，组成完整的二叉树。
 */
class Solution {
private: 
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(inorder.empty()) return nullptr;
        int size = inorder.size();
        TreeNode* node = new TreeNode(postorder[size - 1]);

        if(postorder.size() == 1) return node;
        // 寻找inorder的切割点
        int delimiterIndex = 0;
        while(delimiterIndex < size){
            if(inorder[delimiterIndex] == node->val) break;
            else delimiterIndex++;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightinorder (inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        node->left = traversal(leftInorder, leftPostorder);
        node->right = traversal(rightinorder, rightPostorder);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
};