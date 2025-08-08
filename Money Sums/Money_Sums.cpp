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
    vi values;
    
    cin >> n;
    vvi dp = vvi(n+1);
    
    values.assign(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i].assign(1e5 + 1, false);
        cin >> values[i];
    }
    dp[n].assign(1e5 + 1, false);
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1e5; j++) {
            if (j < values[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - values[i - 1]];
            }
        }
    }
    vi res;
    for (int i = 1; i <= 1e5; i++) {
        if (dp[n][i] == true) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size() - 1; i++) {
        cout << res[i] << " ";
    }
    cout << res[res.size() - 1] << endl;
    return 0;
}