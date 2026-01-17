class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                long long w = min(topRight[i][0],topRight[j][0]) - max(bottomLeft[i][0] , bottomLeft[j][0]);
                long long h = min(topRight[i][1],topRight[j][1]) - max(bottomLeft[i][1] , bottomLeft[j][1]);
                if(w > 0 && h > 0)
                {
                    long long side = min(w,h);
                    maxSide = max(maxSide,side);
                }
            }
        }
        return maxSide * maxSide;
    }
};