
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        bool nullfound = false;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t == NULL) {
                nullfound = true;
            }
            else {
                if(nullfound) return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};