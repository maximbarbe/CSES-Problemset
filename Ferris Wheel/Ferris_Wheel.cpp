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
    deque<int> q;
    int n, x, p;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> p;
        q.push_back(p);
    }
    sort(q.begin(), q.end());
    int res = 0;
    while (!q.empty()) {
        int first = q.back();
        q.pop_back();
        if (!q.empty() && first + q.front() <= x) {
            q.pop_front();
        }
        res ++;
    }
    cout << res << endl;
    return 0;
}