class Solution {
public:
    bool sameTree(TreeNode* root, TreeNode* subroot) {
        if(root == NULL && subroot == NULL) {
            return true;
        }
        if(root == NULL or subroot == NULL) {
            return false;
        }
        if(root->val != subroot->val) {
            return false;
        }

        bool left = sameTree(root->left, subroot->left);
        bool right = sameTree(root->right, subroot->right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        
        if(root == NULL) return false;

        if(root->val == subroot->val) {
            if(sameTree(root, subroot)) {
                return true;
            }
        }

        bool left = isSubtree(root->left, subroot);
        bool right = isSubtree(root->right, subroot);

        return left or right;
    }
};
