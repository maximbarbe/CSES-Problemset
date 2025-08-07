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
    int n, x, a;
    map<int, int> seen;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (seen[a] != 0) {
            cout << seen[a] << " " << i + 1<<endl;
            return 0;
        } else {
            seen[x - a] = i + 1;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}