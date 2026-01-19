class Solution {
public:
int m, n;
    vector<vector<int>> P; // Mảng Prefix Sum

    // Hàm kiểm tra xem có tồn tại hình vuông cạnh 'len' nào có tổng <= threshold không
    bool isValid(int len, int threshold) {
        for (int i = 0; i <= m - len; ++i) {
            for (int j = 0; j <= n - len; ++j) {
                // Tính tổng hình vuông con dùng công thức bao hàm - loại trừ
                // Tọa độ trong P sẽ lệch +1 so với mat gốc, nhưng do ta cộng len
                // vào i, j nên P[i+len][j+len] chính là góc dưới phải
                int currentSum = P[i + len][j + len] - P[i][j + len] - P[i + len][j] + P[i][j];
                
                if (currentSum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        
        // 1. Xây dựng mảng 2D Prefix Sum (kích thước lớn hơn 1 để tránh check biên)
        P.assign(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = mat[i-1][j-1] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
            }
        }
        
        // 2. Binary Search kết quả
        int low = 0, high = min(m, n);
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) { // Cạnh 0 luôn đúng
                low = 1; 
                continue;
            }
            
            if (isValid(mid, threshold)) {
                ans = mid;      // Ghi nhận kết quả
                low = mid + 1;  // Thử tìm cạnh lớn hơn
            } else {
                high = mid - 1; // Giảm cạnh xuống
            }
        }
        
        return ans;
    }
};