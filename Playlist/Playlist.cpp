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
    map<int, bool> seen;
    int n;
    vi songs;
    cin >> n;
    songs.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    int left =0;
    int right =0;
    int cur = 0;
    int res = 0;
    while (right != n) {
        if (!seen[songs[right]]) {
            cur ++;
            seen[songs[right]] = true;
            right ++;
        }else {
            while (seen[songs[right]]) {
                seen[songs[left]] = false;
                left ++;
                cur --;
            }
        }
        res = max(res, cur);
    }
    cout << res <<endl;
    return 0;
}