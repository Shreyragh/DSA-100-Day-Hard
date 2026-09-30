class Solution {
public:
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum, int target, vector<int>& diary) {
        if(root == NULL) return;

        sum = sum + root->val;
        diary.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            if(sum == target) {
                res.push_back(diary);
            }
            diary.pop_back();
            return;
        }
        fun(root->left, sum, target, diary);
        fun(root->right, sum, target, diary);

        diary.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> diary;

        fun(root, 0, targetSum, diary);
        return res;
    }
};