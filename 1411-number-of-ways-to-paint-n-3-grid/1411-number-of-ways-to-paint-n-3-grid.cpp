//He thuc truy hoi
typedef long long ll;
class Solution {
public:
    int numOfWays(int n) {
        ll MOD = 1e9 + 7;
        ll aba = 6;
        ll abc = 6;
        for(int i = 0; i < n - 1; i++)
        {
            ll new_aba = (3 * aba + 2 * abc) % MOD;
            ll new_abc = (2 * aba + 2 * abc) % MOD;
            aba = new_aba;
            abc = new_abc;
        }
        return (aba + abc) % MOD;
    }
};