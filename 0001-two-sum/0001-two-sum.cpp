class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i< nums.size(); i++)
        {
            int check = target - nums[i];
            auto it = mp.find(check);
            if(it != mp.end())
            {
                return {it->second,i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};