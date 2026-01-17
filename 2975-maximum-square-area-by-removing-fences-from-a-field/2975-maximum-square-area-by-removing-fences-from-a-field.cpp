class Solution {
public:
    vector<int> getEdge(vector<int>& fences, int border)
    {
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(),fences.end());
        int size = fences.size();
        vector<int> edges;
        for(int i = 0 ; i < size-1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                edges.push_back(fences[j] - fences[i]);
            }

        }
        return edges;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        vector<int> h = getEdge(hFences,m);
        vector<int> v = getEdge(vFences,n);
        long long result = -1;
        sort(h.begin(),h.end(),greater<int>());
        sort(v.begin(),v.end(),greater<int>());
        int i = 0, j = 0;
        while(i < h.size() && j < v.size())
        {
            if(h[i] == v[j])
            {
                result = h[i];
                return (result * result) % MOD;
            }
            else if(h[i] > v[j]) i++;
            else j++;
        }
        return -1;
    }
};
