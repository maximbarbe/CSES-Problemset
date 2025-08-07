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

vector<pii> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


vector<str> grid;

const int null = 1e6 + 1;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int n, m;
    str s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.push_back(s);
    }
    vvi parents = vvi(n);
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        parents[i].assign(m, 1e6 + 1);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = i * m + j;
            }
            if (grid[i][j] == 'B') {
                end = i * m + j;
            }
        }
    }
    deque<int> q;
    bool found = false;
    q.push_back(start);
    parents[start/m][start % m] = start;
    while (!q.empty()) {
        int pos = q.front();
        
        if (pos == end) {
            found = true;
            break;
        }
        q.pop_front();
        int i = pos / m;
        int j = pos % m;
        
        for (auto [di, dj]:dirs) {
            if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && grid[i + di][j + dj] != '#' && parents[i + di][j + dj] == null) {
                parents[i + di][j + dj] = pos;
                q.push_back((i + di)*m + j + dj);
            }
        } 
    }
    if (!found) {
        cout << "NO" << endl;
        return 0;
    }
    vector<char> path;
    int pos = end;
    int i = pos/m;
    int j = pos%m;
    while (true) {

        int parentPos = parents[i][j];
        int pi = parentPos/m;
        int pj = parentPos%m;
        if (i == pi && j == pj) {
            break;
        }
        if (i == pi) {
            if (j - pj == 1) {
                path.push_back('R');
            } else {
                path.push_back('L');
            }
        } else {
            if (i - pi == 1) {
                path.push_back('D');
            } else {
                path.push_back('U');
            }
        }
        i = pi;
        j = pj;
    }
    cout << "YES" << endl;
    cout << path.size() << endl;
    for (int i = path.size() -1; i > 0; i--) {
        cout << path[i];
    }
    cout << path[0]<<endl;



    return 0;
}