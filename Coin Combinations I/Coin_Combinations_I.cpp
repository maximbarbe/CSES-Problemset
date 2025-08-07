#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
using namespace std;


#define all(x) begin(x), end(x);
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;



const double PI = acos(-1);
const int MOD = 1000000007;



int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vi coins;
    coins.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vi dp = vi(x+1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto c:coins) {
            if (i - c>= 0) {
                dp[i] = (dp[i] + dp[i - c])%MOD;
            }
        }
    }    
    cout << dp[x] << endl;
    return 0;
}