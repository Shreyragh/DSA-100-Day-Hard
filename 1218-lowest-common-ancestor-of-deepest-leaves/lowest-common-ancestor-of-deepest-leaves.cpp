class Solution {
public:
    pair<TreeNode*, int> solve(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.second == right.second) {
            return {root, left.second + 1};
        }
        if(left.second > right.second) //means left side is deeper
        {
            return {left.first, left.second + 1};
        }
        // then irght side will be deeper
        return {right.first, right.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).first;
    }
};