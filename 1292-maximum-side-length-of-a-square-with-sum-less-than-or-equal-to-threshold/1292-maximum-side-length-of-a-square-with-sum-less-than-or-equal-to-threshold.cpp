#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        // 1. Tạo bảng Prefix Sum (Toán học)
        // P[i][j] lưu tổng hình chữ nhật từ (0,0) đến (i-1, j-1)
        vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = mat[i-1][j-1] 
                        + P[i-1][j] 
                        + P[i][j-1] 
                        - P[i-1][j-1];
            }
        }
        
        int len = 0; // Độ dài cạnh lớn nhất tìm được (Current Max)
        
        // 2. Duyệt tuyến tính (Toán học đơn điệu)
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Kiểm tra xem có thể mở rộng lên cạnh (len + 1) tại vị trí này không
                // Để có cạnh (len + 1), ta cần i và j đủ lớn (>= len + 1)
                int checkLen = len + 1;
                
                if (i >= checkLen && j >= checkLen) {
                    // Áp dụng công thức Bao hàm - Loại trừ
                    int currentSum = P[i][j] 
                                   - P[i - checkLen][j] 
                                   - P[i][j - checkLen] 
                                   + P[i - checkLen][j - checkLen];
                                   
                    if (currentSum <= threshold) {
                        len++; // Tìm thấy cạnh lớn hơn, cập nhật kỷ lục
                    }
                }
            }
        }
        
        return len;
    }
};