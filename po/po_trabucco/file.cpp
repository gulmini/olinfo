#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
constexpr ll INF = INT32_MAX/4;
constexpr ll MOD = 1e9+7;
const string quack = "quack";

ll n, m, k;
vi v;

vector<vi> d;
vector<vb> vis;
vector<pi> points;
array<pi, 4> neigh = {pi{0, -1}, pi{0, 1}, pi{-1, 0}, pi{1, 0}};

inline bool is_valid(int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < m;
}

inline bool r_is_valid(int i, int j) {
	return i < n and j < m;
}

void bfs() {
	queue<pi> q;
	for (auto e: points) q.push(e);
	while (not q.empty()) {
		auto [i, j] = q.front(); q.pop();
		for (auto [y, x]: neigh) {
			if (is_valid(i+y, j+x) and
					d[i+y][j+x] == INF) {
				d[i+y][j+x] = d[i][j] + 1;
				q.push(pi{i+y, j+x});
			}
		}
	}
}

bool check(int k) {
	if (d[0][0] < k or d[n-1][m-1] < k) return false;
	vis.assign(n, vb(m, 0));
	stack<pi> q; q.push(pi{0, 0});
	while (not q.empty()) {
		auto [i, j] = q.top(); q.pop();
		if (i == n-1 and j == m-1) return true;
		if (vis[i][j]) continue;
		vis[i][j] = true;
		if (r_is_valid(i+1, j) and d[i+1][j] >= k)
			q.push(pi{i+1, j});
		if (is_valid(i, j+1) and d[i][j+1] >= k)
			q.push(pi{i, j+1});
	}
	return false;
}

ll dp() {
	for (int j = 1; j < m; j++)
		d[0][j] &= d[0][j-1];
	for (int i = 1; i < n; i++) {
		d[i][0] *= d[i-1][0];
		for (int j = 1; j < m; j++)
			d[i][j] *= (d[i-1][j] + d[i][j-1]) % MOD;
	}
	return d[n-1][m-1];
}

int ContaPercorsi(int N, int M, int K, int* X, int* Y) {
	::m = N; ::n = M; ::k = K;
	if (n == 1 or m == 1) return 1;
	vis.resize(n, vb(m, false));
	d.resize(n, vi(m, INF));
	for (int i = 0; i < k; i++) {
		d[Y[i]][X[i]] = 0;
		points.push_back(pi{Y[i], X[i]});
	}
	bfs();

	ll c = 0;
	int l = 0, r = min(n, m) + 1, mid = -1;
	while (l < r) {
		if (c++ == 13) d[0].resize(10000000000, -1);
		mid = (l + r) / 2;
		if (check(mid)) l = mid+1;
		else r = mid;
	}
	if (not check(mid)) mid--;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = (d[i][j] >= mid);

	return dp();
}

