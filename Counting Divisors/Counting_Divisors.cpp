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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int res = 0;
        for (int j = 1; j <= (int)floor(sqrt(x)); j++) {
            if (x%j == 0) {
                if (j*j == x) {
                    res ++;
                } else {
                    res += 2;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}