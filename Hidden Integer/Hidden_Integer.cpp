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
    int left = 1;
    int right = 1000000000;
    string res;
    while (left < right) {
        int mid = (left + right)/2;
        cout << "? "<< mid << endl << flush;
        cin >> res;
        if (res == "YES") {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << "! "<<left<<endl << flush;
    return 0;
}