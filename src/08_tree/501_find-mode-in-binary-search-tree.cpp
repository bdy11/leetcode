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
要理解二叉搜索树的本质，是按从小到大排列的序列。用双指针法可以简洁且快速地遍历二叉搜索树。
遍历顺序依旧是中序遍历。
遍历开始时，pre指针为空，那么此时当前元素出现次数应该为1.如果当前元素的值与pre的值相同，那么count就加1.
比较count和maxcount的关系。如果count > maxcount，那么清空result数组，并且更新maxcount的值。
需要注意的是，众数不一定唯一，如果有一个以上元素的count与maxcount相同，那么也要加入result数组。
 */
class Solution {
private:
    int maxcount = 0;
    int count = 0;
    TreeNode* pre = nullptr;
    vector<int> result;

    void traversal(TreeNode* cur){
        if(cur == nullptr) return;

        traversal(cur->left);
        if(pre == nullptr){
            count = 1;
        }else if(cur->val == pre->val){
            count++;
        }else{
            count = 1;
        }

        pre = cur;
        if(count > maxcount){
            result.clear();
            result.push_back(cur->val);
            maxcount = count;
        }else if(count == maxcount){
            result.push_back(cur->val);
        }

        traversal(cur->right);
    }
public:
    vector<int> findMode(TreeNode* root) {

        traversal(root);
        return result;
        
    }
};