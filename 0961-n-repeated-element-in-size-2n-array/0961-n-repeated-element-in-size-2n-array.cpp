class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int n = nums.size() / 2;
        for (auto& [val, cnt] : mp) {
            if (cnt == n)
                return val;
        }
        return -1;
    }
};