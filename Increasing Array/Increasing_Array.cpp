#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
using namespace std;


#define all(x) begin(x), end(x);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double PI = acos(-1);
const int MOD = 1000000007;





int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, v;
    vi values;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        values.push_back(v);
    }
    ull res = 0;
    for (int i = 1; i < n; i++) {
        if (values[i] < values[i - 1]) {
            res += values[i - 1] - values[i];
            values[i] = values[i - 1];
        }
    }
    cout << res << endl;
    return 0;
}