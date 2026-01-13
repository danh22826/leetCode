class Solution {
public:
       double separateSquares(vector<vector<int>>& squares) {
        long double total = 0.0L;
        long double lo = LLONG_MAX, hi = LLONG_MIN;

        for (auto &s : squares) {
            long double y = s[1];
            long double l = s[2];
            total += l * l;
            lo = min(lo, y);
            hi = max(hi, y + l);
        }

        long double target = total / 2.0L;

        auto areaBelow = [&](long double Y) -> long double {
            long double sum = 0.0L;
            for (auto &s : squares) {
                long double y = s[1];
                long double l = s[2];
                long double h = Y - y;
                if (h <= 0) continue;
                if (h >= l) sum += l * l;
                else sum += h * l;
            }
            return sum;
        };

        for (int it = 0; it < 100; ++it) { 
            long double mid = (lo + hi) / 2.0L;
            if (areaBelow(mid) < target) lo = mid;
            else hi = mid;
        }

        return (double)hi; 
       }
};