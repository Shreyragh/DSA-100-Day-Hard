class Solution {
public:
    int ans = INT_MIN;

    int find(TreeNode* root) {
        if(root == NULL) {
                return 0;
        }
        int left = max(0, find(root->left));
        int right = max(0, find(root->right));

             // Best path passing through this node

        ans = max(ans, left + root->val + right);

             // Best path that can be extended to parent
            
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
};