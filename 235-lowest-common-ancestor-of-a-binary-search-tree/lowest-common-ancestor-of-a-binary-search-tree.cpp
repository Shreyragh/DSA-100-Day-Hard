class Solution {
public:
    TreeNode* ans = NULL;
    void fun(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return;

        if(root->val < p->val) {
            fun(root->right, p, q);
        }
        else if(root->val > q->val) { // both p and q are on the left
            fun(root->left, p, q);
        }
        else { //case 4 When root is in centre so it will be LCA
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val < q->val) {
            fun(root, p, q);
        }
        else {
            fun(root, q, p);
        }
        return ans;        
    }
};