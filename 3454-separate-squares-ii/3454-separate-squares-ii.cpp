#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // y-events: at y1 add [x1,x2], at y2 remove [x1,x2]
        struct E { long long y, x1, x2; int t; };
        vector<E> ev;
        ev.reserve(squares.size() * 2);

        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            ev.push_back({y,     x, x + l, +1});
            ev.push_back({y + l, x, x + l, -1});
        }
        sort(ev.begin(), ev.end(), [](const E& a, const E& b){ return a.y < b.y; });

        auto unionLen = [&](vector<pair<long long,long long>>& segs) -> long double {
            if (segs.empty()) return 0.0L;
            sort(segs.begin(), segs.end());
            long double res = 0;
            long long L = segs[0].first, R = segs[0].second;
            for (int i = 1; i < (int)segs.size(); i++) {
                if (segs[i].first > R) {
                    res += (long double)(R - L);
                    L = segs[i].first; R = segs[i].second;
                } else {
                    R = max(R, segs[i].second);
                }
            }
            res += (long double)(R - L);
            return res;
        };

        // active intervals with multiplicity (since multiple squares can contribute same [x1,x2])
        map<pair<long long,long long>, int> active;
        vector<pair<long long,long long>> segs;

        // 1) compute total union area
        long double total = 0;
        long long prevY = ev[0].y;

        for (int i = 0; i < (int)ev.size(); ) {
            long long y = ev[i].y;
            long long dy = y - prevY;

            if (dy > 0) {
                segs.clear();
                segs.reserve(active.size());
                for (auto &p : active) segs.push_back(p.first);
                long double L = unionLen(segs);
                total += (long double)dy * L;
            }

            while (i < (int)ev.size() && ev[i].y == y) {
                auto key = make_pair(ev[i].x1, ev[i].x2);
                active[key] += ev[i].t;
                if (active[key] == 0) active.erase(key);
                i++;
            }
            prevY = y;
        }

        long double half = total / 2.0L;

        // 2) sweep again to find minimal y where area reaches half
        active.clear();
        prevY = ev[0].y;
        long double acc = 0;

        for (int i = 0; i < (int)ev.size(); ) {
            long long y = ev[i].y;
            long long dy = y - prevY;

            if (dy > 0) {
                segs.clear();
                segs.reserve(active.size());
                for (auto &p : active) segs.push_back(p.first);
                long double L = unionLen(segs);

                long double block = (long double)dy * L;
                if (acc + block >= half) {
                    // inside this vertical slab: prevY -> y
                    if (L == 0) return (double)prevY; // degenerate safety
                    long double need = half - acc;
                    return (double)( (long double)prevY + need / L );
                }
                acc += block;
            }

            while (i < (int)ev.size() && ev[i].y == y) {
                auto key = make_pair(ev[i].x1, ev[i].x2);
                active[key] += ev[i].t;
                if (active[key] == 0) active.erase(key);
                i++;
            }
            prevY = y;
        }

        return (double)prevY;
    }
};
