class Solution {
public:
    stack<TreeNode* >asc;

    TreeNode *getsmall() {
        if(asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();

        TreeNode *rightchild = small->right;
        while(rightchild) {
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        if(root == NULL) {
            return -1;
        }
        TreeNode* t = root;

        while(t) {
            asc.push(t);
            t = t->left;
        }

        while(k--) {
            TreeNode* node = getsmall();

            if(k == 0) {
                return node->val;
            }
        }
        return -1;
    }
};