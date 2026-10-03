class Solution {
public:
    TreeNode* fun(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;

        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = fun(nums, low, mid - 1);
        node->right = fun(nums, mid + 1, high);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums, 0, nums.size() - 1);
    }
};