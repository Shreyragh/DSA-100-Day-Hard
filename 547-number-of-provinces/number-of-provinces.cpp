class Solution {
public:
    void dfs(vector<vector<int>>& a, int n, int i, vector<bool>& vis) {
        vis[i] = true;

        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && vis[j] == 0) {
                dfs(a, n, j, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        int res = 0;
        vector<bool> vis(n, 0);
        // for city that is not connected

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                res++;
                dfs(a, n, i, vis);
            }
        }

        return res;
    }
};