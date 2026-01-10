class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        vector<vector<int>> v(m+1,vector<int>(n+1,0));
        for(int i = 1; i <= m ; i++)
        {
            v[i][0] = v[i-1][0] + s1[i-1];
        }
        for(int j = 1; j <= n; j++)
        {
            v[0][j] = v[0][j-1] + s2[j-1];
        }
        for(int i = 1; i <= m ; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    v[i][j] = v[i-1][j-1];
                }
                else 
                {
                    v[i][j] = min(v[i-1][j] + s1[i-1],v[i][j-1] + s2[j-1]);
                }
            }
        }
        return v[m][n];
    }
};