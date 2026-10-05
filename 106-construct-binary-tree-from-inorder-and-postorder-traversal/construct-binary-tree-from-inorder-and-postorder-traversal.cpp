class Solution {
public:
    unordered_map<int, int> in;
    int idx;
    TreeNode* fun(vector<int>& postorder, int low, int high) {
        if(low > high) return NULL;

        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;

        int id = in[node->val];

        node->right = fun(postorder, id + 1, high); //we will start traversal from right 
        node->left = fun(postorder, low, id -1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] =  i;
        }

        idx = postorder.size() - 1;

        return fun(postorder, 0, inorder.size() - 1);
    }
};