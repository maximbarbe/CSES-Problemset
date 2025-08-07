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
    vi dp;
    dp.assign(n + 1, 1e6 + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        str rep = to_string(i);
        for (auto c:rep) {
            dp[i] = min(dp[i], 1 + dp[i - (c - '0')]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}