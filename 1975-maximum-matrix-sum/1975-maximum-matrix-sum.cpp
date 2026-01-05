#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;      
        int minAbsVal = INT_MAX;     
        int negativeCount = 0;       
        for (const auto& row : matrix) {
            for (int val : row) {
                totalSum += llabs((long long)val);
                if (val < 0) negativeCount++;
                minAbsVal = min(minAbsVal, (int)llabs((long long)val));
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2LL * minAbsVal;
        }

        return totalSum;
    }
};
