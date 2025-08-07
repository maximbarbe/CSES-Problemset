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
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vi sizes;
    vi apartments;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sizes.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        cin >>b;
        apartments.push_back(b);
    }
    sort(sizes.begin(), sizes.end());
    sort(apartments.begin(), apartments.end());
    int j = 0;
    int i = 0;
    while (i != n && j != m) {
        if (sizes[i] - k <= apartments[j] && apartments[j] <= sizes[i] + k) {
            res ++;
            j ++;
            i ++;
        } else if (sizes[i] - k > apartments[j]) {
            j ++;
        } else {
            i ++;
        }
    }
    cout << res << endl;
    return 0;
}