class Solution {
public:
    TreeNode* prev = NULL;
    bool ans = true;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        if(prev == NULL) {
            prev = root;
        }
        else {
            if(root->val <= prev->val) {
                ans = false;
            }
            prev = root;
        }
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};