#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        vector<int> heights(cols + 1, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') heights[c] += 1;
                else heights[c] = 0;
            }

            stack<int> st;
            st.push(-1); 

            for (int i = 0; i <= cols; i++) {
                int currentH = (i < cols) ? heights[i] : 0; 

                while (st.top() != -1 && heights[st.top()] >= currentH) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = i - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(i);
            }
        }

        return maxArea;
    }
};
