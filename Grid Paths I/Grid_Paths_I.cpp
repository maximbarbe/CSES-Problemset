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
typedef string str;

const double PI = acos(-1);
const int MOD = 1000000007;



int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    str s;
    vector<str> grid;
    
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.push_back(s);
    }
    vvi dp = vvi(n);
    for (int i = 0; i < n; i++) {
        dp[i].assign(n, 0);
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    if (j != 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                    if (i != 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}