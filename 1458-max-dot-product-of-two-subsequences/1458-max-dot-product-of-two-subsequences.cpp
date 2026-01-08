class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        const long long NEG_INF = LLONG_MIN / 4;
        vector<vector<long long>> dp(n, vector<long long>(m, NEG_INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long product = 1LL * nums1[i] * nums2[j];

                long long best = product;

                if (i > 0 && j > 0) {
                    best = product + max(0LL, dp[i - 1][j - 1]);
                }

                if (i > 0) best = max(best, dp[i - 1][j]);
                if (j > 0) best = max(best, dp[i][j - 1]);

                dp[i][j] = best;
            }
        }

        return (int)dp[n - 1][m - 1];
    }
};