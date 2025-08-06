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




int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    char prev = 'Z';
    int max = 0;
    int cur = 0;
    for (auto c:s) {
        if (c == prev) {
            cur ++;
        } else {
            prev = c;
            cur = 1;
        }
        if (cur > max) {
            max = cur;
        }
    }
    cout << max << endl;

    return 0;
}