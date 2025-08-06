#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
using namespace std;


#define all(x) begin(x), end(x);

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double PI = acos(-1);





int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, v;
    cin >>n;
    vi values;
    for (int i; i <n-1; i++) {
        cin >> v;
        values.push_back(v);
    }
    sort(values.begin(), values.end());
    int c = 1;
    for (auto v:values) {
        if (v != c) {
            cout << c << endl;
            return 0;
        }
        c ++;
    }
    cout << c << endl;

    return 0;
}