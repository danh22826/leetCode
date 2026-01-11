class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> pd(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m ; i++)
        {
            pd[i][0] = pd[i-1][0] + s1[i-1]; 
        }
        for(int j = 1; j <= n ; j++)
        {
            pd[0][j] = pd[0][j-1] + s2[j-1];
        }
        for(int i = 1; i <= m ; i++)
        {
            for(int j = 1 ; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    pd[i][j] = pd[i-1][j-1];
                }
                else 
                {
                    pd[i][j] = min(pd[i-1][j] + s1[i-1],pd[i][j-1] + s2[j-1]);
                }
            }
        }
        return pd[m][n];
    }
};