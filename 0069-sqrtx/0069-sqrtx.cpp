class Solution {
public:
    int mySqrt(int x) {
       int l = 1, r = x;
       int ans = 0;
       if(x < 2 ) return x;
       while(l <= r)
       {
        int mid = l + (r-l)/2;
        if(mid <= x / mid )
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
       }
       return ans;
    }
};