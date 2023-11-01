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
class Solution {
public:
    TreeNode* construct(vector<int> nums){
        if(nums.size() == 1){
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        int max = INT_MIN;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(nums[index]);
        if(index > 0){
            vector<int> leftvec(nums.begin(), nums.begin() + index);
            node->left = construct(leftvec);
        }
        if(index < nums.size() - 1){
            vector<int> rightvec(nums.begin() + index + 1, nums.end());
            node->right = construct(rightvec);
        }
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
    }
};