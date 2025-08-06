#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
using namespace std;


#define all(x) begin(x), end(x);

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
const double PI = acos(-1);





int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ull n;
    cin >> n;
    vector<ull> values;
    while (n != 1) {
        values.push_back(n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3*n + 1;
        }
    }
    values.push_back(1);
        
    for (int i = 0; i < values.size() - 1; i++) {
        cout << values[i] << " ";
    }
    cout << values[values.size() - 1] << endl;
    return 0;
}