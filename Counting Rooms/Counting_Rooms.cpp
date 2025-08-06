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

    queue<pii> q;
    int n,m;
    cin >> n >> m;
    string row;
    vector<string> grid;
    vector<vector<bool>> visited = vector<vector<bool>>(n);
    vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n;i++) {
        cin >> row;
        grid.push_back(row);
        visited[i].assign(m, false);
    }
    int res = 0;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                q.push({i, j});
                res ++;
                int curi, curj;
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [curi, curj] = q.front();
                    q.pop();
                    for (auto [di, dj]:dirs) {
                        if (curi + di >= 0 && curi + di < n && curj + dj >= 0 && curj + dj < m && !visited[curi+di][curj+dj] && grid[curi+di][curj+dj] == '.') {
                            q.push({curi+di, curj+dj});
                            visited[curi+di][curj+dj]=true;
                        } 
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}