class Solution {
public:
    TreeNode* ans = NULL;

    void fun(TreeNode* node, int k) {
        if(node == NULL) return;

        if(node->val == k) {
            ans = node;
            return;
        }

        if(node->val > k) { // search in left subtree
            fun(node->left, k);
        }
        else { // search in right subtree
            fun(node->right, k);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root, val);
        return ans;
    }
};