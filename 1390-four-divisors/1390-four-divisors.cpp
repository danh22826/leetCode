class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<vector<int>> ds(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            for(int j = 1; j * j <= nums[i]; j++)
            {
                if(x % j ==0)
                {
                    ds[i].push_back(j);
                    if(j !=  x / j)
                    {
                        ds[i].push_back(x/j);
                    }
                }
            }
        }
        int tong = 0;
        for(int i = 0 ;i < nums.size(); i++)
        {
            if(ds[i].size() == 4)
            {
                for(int j = 0 ; j < ds[i].size(); j++)
                {
                    tong += ds[i][j];
                }
            }
        }
        return tong;
        
    }
};