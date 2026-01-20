class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int& x : nums)
        {
            if((x & 1) == 0)
            {
                ans.push_back(-1);
                continue;
            }
        int t = x, k = 0;
        while(t & 1)
        {
            k ++;
            t >>= 1;
        }
        ans.push_back( x - (1 << (k-1)));
        }
        return ans;
    }
};