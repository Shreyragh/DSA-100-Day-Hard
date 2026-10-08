class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            if(a > b)
                swap(a, b);

            // Initially assume 2 moves for every possible sum
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 1 move is enough for sums from a+1 to b+limit
            diff[a + 1]--;
            diff[b + limit + 1]++;

            // 0 moves for the current sum
            diff[a + b]--;
            diff[a + b + 1]++;
        }

        int ans = n;
        int moves = 0;

        for(int sum = 2; sum <= 2 * limit; sum++) {
            moves += diff[sum];
            ans = min(ans, moves);
        }

        return ans;
    }
};