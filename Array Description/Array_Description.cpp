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
    int n, m, x;
    cin >> n >> m;
    vvi dp = vvi(m+2);
    vi values;
    for (int i = 0; i < n; i++) {
        cin >>x;
        values.push_back(x);
    }
    for (int i = 0; i < m+2; i++) {
        dp[i].assign(n, 0);
    }
    for (int j = n-1; j >= 0; j--){
        if (j == n-1) {
            if (values[j] == 0) {
                for (int i = 1; i <= m; i++) {
                    dp[i][j] = 1;
                }
            } else {
                dp[values[j]][j]= 1;
            }
        } else {
            if (values[j] != 0) {
                dp[values[j]][j] = ((dp[values[j] - 1][j + 1] + dp[values[j] + 1][j + 1] )%MOD+ dp[values[j]][j + 1])%MOD;
            } else {
                for (int i = 1; i <= m; i++) {
                    dp[i][j] = ((dp[i - 1][j + 1] + dp[i + 1][j + 1])%MOD + dp[i][j + 1])%MOD;
                }
            }
        }
    }

    int res =0;
    for (int i = 0; i < m+2; i++) {
        res = (res + dp[i][0])%MOD;
    }
    cout << res << endl;
    return 0;   
}