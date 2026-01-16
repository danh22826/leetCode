class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        vector<int> h = getEdges(hFences, m);
        vector<int> v = getEdges(vFences, n);

        sort(h.begin(), h.end(), greater<int>());
        sort(v.begin(), v.end(), greater<int>());

        int i = 0, j = 0;
        while (i < h.size() && j < v.size()) {
            if (h[i] == v[j]) {
                long long x = h[i];
                return (x * x) % MOD;
            }
            if (h[i] > v[j]) i++;
            else j++;
        }
        return -1;
    }

    vector<int> getEdges(vector<int> fences, int border) {
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());

        vector<int> edges;
        int sz = fences.size();
        for (int i = 0; i < sz; i++)
            for (int j = i + 1; j < sz; j++)
                edges.push_back(fences[j] - fences[i]);

        return edges;
    }
};
