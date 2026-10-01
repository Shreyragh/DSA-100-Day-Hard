class Solution {
public:
    int res = 0;
    int fun(TreeNode* root) {
        if(root == NULL) return 0;

        int left = fun(root->left);
        int right = fun(root->right);

        int sum = left + right;
        res = max(res, sum);

        return 1 +max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return res;
    }
};