#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> ti;
const string quack = "quack";

ll n, m, k, a, b;
char c;
vector<vi> g, d;
queue<ti> q;

constexpr array<int, 4> dy = {-1, +1, 0, 0};
constexpr array<int, 4> dx = {0, 0, -1, +1};

inline bool valid(int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < n and g[i][j];
}

int main() {
	cin >> n;
	g.resize(n, vi(n));
	d.resize(n, vi(n, 1e9)); d[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			g[i][j] = c == '.' or c == 'T';
		}
	}
	q.push({0, 0, 0});
	while (not q.empty()) {
		auto [_, i, j] = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ni = i, nj = j;
			while (valid(ni += dy[dir], nj += dx[dir])) {
				if (d[ni][nj] > d[i][j] + 1) {
					q.push({d[ni][nj] = d[i][j] + 1, ni, nj});
				}
			}
		}
	}
	if (d[n-1][n-1] == 1e9) cout << -1;
	else cout << d[n-1][n-1] - 1;
}

