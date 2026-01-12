class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans =  0 ;
        for(int i = 0 ; i < points.size()-1 ; i ++)
        {
            int current_x = points[i][0];
            int current_y = points[i][1];
            int next_x = points[i+1][0];
            int next_y = points[i+1][1];
            ans += max(abs(next_x - current_x ),abs( next_y - current_y));
        }
        return ans;
    }
};