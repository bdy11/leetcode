/*
今天的学习内容是二叉树的两种遍历方式，递归遍历和迭代遍历。
写递归遍历严格依照递归三部曲来写，结构化解题，能有效提高解题速度，降低出错概率。
第一步，确定递归函数参数及返回值
第二步，确定递归终止条件
第三步，确定单层递归逻辑
*/

#include <vector>
class solution{
public:
    void traversal(treeNode* cur, vector<int>& vec){
        if(cur == nullptr){
            return;
        }
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> void preorderTraversal(treeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
