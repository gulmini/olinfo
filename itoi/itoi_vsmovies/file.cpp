#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

constexpr int maxn = 100000;
constexpr int maxm = 500000;
constexpr int lg = 17;

ll mst = 0;
int n, m, cc, timer;
int v[maxn], p[maxn], tin[maxn], tout[maxn];
int up[maxn][lg], st[maxn][lg];
vector<pi> adj[maxn];
vi ts;

struct edge {
	int a, b, w;
	edge() {}
	edge(int _a, int _b, int _w) { a = _a; b = _b; w = _w; }
	bool operator<(edge a) { return w < a.w; }
};

edge e[maxm], q[maxm];

inline int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

inline bool join(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return false;
	p[b] = a;
	return true;
}

void dfs(int i, int p) {
	tin[i] = timer++;
	up[i][0] = p;
	for (auto [w, u]: adj[i]) {
		if (u == p) continue;
		v[u] = w;
		dfs(u, i);
	}
	ts.push_back(i);
	tout[i] = timer++;
}

inline bool anc(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

inline int lca(int u, int v) {
	if (anc(u, v)) return u;
	if (anc(v, u)) return v;
	for (int j = lg-1; j >= 0; j--) {
		if (not anc(up[u][j], v))
			u = up[u][j];
	}
	return up[u][0];
}

inline int query(int u, int v) {
	if (u == v) return 0;
	if (anc(u, v)) swap(u, v);
	int res = 0;
	for (int j = lg-1; j >= 0; j--) {
		if (not anc(up[u][j], v)) {
			res = max(res, st[u][j]);
			u = up[u][j];
		}
	}
	return max(res, ::v[u]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	cc = n;
	for (int i = 0; i < n; i++) p[i] = i;
	int a, b, w, u;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		e[i].a = q[i].a = a;
		e[i].b = q[i].b = b;
		e[i].w = q[i].w = w;
	}
	sort(e, e + m);
	for (int i = 0; i < m and cc > 1; i++) {
		a = min(e[i].a, e[i].b);
		b = max(e[i].a, e[i].b);
		if (join(a, b)) {
			cc--; mst += e[i].w;
			adj[a].emplace_back(e[i].w, b);
			adj[b].emplace_back(e[i].w, a);
		}
	}
	dfs(0, 0);
	reverse(ts.begin(), ts.end());
	for (auto i: ts) {
		for (int j = 1; j < lg; j++) {
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	for (auto i: ts) {
		st[i][0] = v[i];
		for (int j = 1; j < lg; j++) {
			st[i][j] = max(st[i][j-1], st[up[i][j-1]][j-1]);
		}
	}
	for (int i = 0; i < m; i++) {
		a = q[i].a, b = q[i].b, w = q[i].w;
		u = lca(a, b);
		cout << mst + w - max(query(a, u), query(b, u));
	}
	return 0;
}

