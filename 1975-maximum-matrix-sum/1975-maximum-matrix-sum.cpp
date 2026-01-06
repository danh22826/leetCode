#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minVal = INT_MAX;
        int countNegative = 0;
        for(const auto& row : matrix)
        {
            for(int x : row)
            {
                if(x < 0) countNegative++;
                int abv = abs(x);
                sum += (long long)abv;
                minVal = min(minVal,abv);
            }
        }
        if(countNegative % 2 != 0) sum -= 2LL * minVal;
        return sum;
    }
};
