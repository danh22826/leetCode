class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long res = -1;
        int MOD = 1e9 + 7;
        unordered_set<int> hEdges = getEdges(hFences,m);
        unordered_set<int> vEdges = getEdges(vFences,n);
        for(int h : hEdges)
        {
            if(vEdges.count(h))
            {
                res = max(res,(long long)h*h);
            }
        }
        return res == -1 ? -1 : res % MOD;
    }
    unordered_set<int> getEdges(vector<int>& fences,int border)
    {
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(),fences.end());
        unordered_set<int> edges;
        for(int i = 0 ; i < fences.size(); ++i)
        {
            for(int j = i + 1 ; j < fences.size(); ++j)
            {
                edges.insert(fences[j] - fences[i]);
            }
        }
        return edges;
    }
};