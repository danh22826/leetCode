class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        for(auto& x : nums)
        {
            mp[x]++;
        }
        int uniqueE = mp.size() - 1;
        int lengthA = nums.size() / 2;
        for(const auto& x : mp)
        {
            if(x.second == lengthA && x.second == uniqueE )
            {
                return x.first;
            }
        }
        return -1;
    }
};