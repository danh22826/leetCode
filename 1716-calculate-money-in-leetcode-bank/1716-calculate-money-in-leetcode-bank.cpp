class Solution {
public:
    int totalMoney(int n) {
        int tong = 0, week = 1;
        for(int i = 0 ; i < n ; i++)
        {
            tong += (i % 7) + week;
            if(i % 7 == 6) week++;
        }
        return tong;
    }
};