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
typedef vector<vi> vvi;


const double PI = acos(-1);
const int MOD = 1000000007;



int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x, c;
    cin >> n >> x;
    vi coins;
    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
    }
    vvi dp = vvi(n+1);
    for (int i = 0; i <= n; i++) {
        dp[i].assign(x+1, 1000001);
        for (int j = 0; j <= x; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                break;
            } else if (j < coins[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(min(1 + dp[i - 1][j - coins[i - 1]], 1 + dp[i][j - coins[i - 1]]), dp[i - 1][j]);
            }
        }
    }
    if (dp[n][x] == 1000001) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x] << endl;
    }
    return 0;
}