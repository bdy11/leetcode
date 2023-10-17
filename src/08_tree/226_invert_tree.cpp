/*
反转树有两种写法，一种是用递归，先序遍历，另外一种是用栈。
今天刷题用的递归，ac了

*/
class Solution {
public:
    void traversal(TreeNode* node){
        if(node == nullptr){
            return;
        }
        swap(node->left, node->right);
        traversal(node->left);
        traversal(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();              // 中
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);   // 右
            if(node->left) st.push(node->left);     // 左
        }
        return root;
    }
};