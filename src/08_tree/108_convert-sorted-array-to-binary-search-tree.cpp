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
 将有序数组转换为平衡二叉搜索树
 递归三部曲，第一步确定递归函数的参数，本题包括输入，左区间Index left，右区间Index right.
 递归终止条件是，left > right.
 递归逻辑是，取数组的中间值创建一个新的节点，然后节点的左子树用数组的左区间构造，数组的右子树用数组的右区间构造
 最后返回创建的节点
 */
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traversal(nums, left, mid - 1);
        node->right = traversal(nums, mid + 1, right);
        return node; 
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};