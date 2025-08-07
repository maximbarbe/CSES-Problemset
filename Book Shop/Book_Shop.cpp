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
    int n, x;
    vi books;
    vi pages;
    cin >> n >> x;
    books.assign(n, 0);
    pages.assign(n, 0);
    vvi dp = vvi(n+1);
    for (int i = 0; i < n; i++) {
        cin >> books[i];

        dp[i].assign(x+1, 0);
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    dp[n].assign(x+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j < books[i - 1]) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], pages[i - 1] + dp[i - 1][j - books[i - 1]]);
        }

    }
    cout << dp[n][x] << endl;
    return 0;
}