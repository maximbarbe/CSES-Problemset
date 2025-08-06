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
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        vi perm;
        int mid = n/2 + 1;
        int left = 1;
        int right = n;
        if (n % 2 == 0) {
            perm.push_back(mid);
            for (int k = 0; k < (n-1)/2; k++) {
                perm.push_back(left);
                perm.push_back(right);
                left ++;
                right --;
            }
            perm.push_back(left);
        } else {
            perm.push_back(mid);
            for (int k = 0; k < (n-1)/2; k++) {
                perm.push_back(right);
                perm.push_back(left);
                left ++;
                right --;
            }
        }
        for (int i = 0; i < perm.size() - 1; i++) {
            cout << perm[i] << " ";
        }
        cout << perm[perm.size() - 1] << endl;
    }

    return 0;
}