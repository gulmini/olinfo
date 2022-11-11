#include <vector>
#include <utility>
#include <array>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

const string quack = "quack";
constexpr int inf = 1 << 30;
constexpr int maxn = 100000;
constexpr int lg = 18;

ll timer = 0;
ll flag[10];
int h[maxn], p[maxn], tin[maxn], tout[maxn];
ll d[maxn], v[maxn];
int minst[maxn][lg], maxst[maxn][lg], up[maxn][lg];
ll sst[maxn][lg], lst[maxn][lg], rst[maxn][lg], gst[maxn][lg];
vector<pi> adj[maxn];
vector<int> ts;

void dfs(int i, int p = 0, ll d = 0, int h = 0, int v = 0) {
	ts.push_back(i);
	tin[i] = timer++;
	::d[i] = d;
	::h[i] = h;
	::v[i] = v;
	up[i][0] = p;
	for (auto [u, w]: adj[i]) {
		if (u != p) {
			minst[u][0] = w;
			dfs(u, i, d+w, h+1, w);
		}
	}
	tout[i] = timer++;
}

void inizia(int n, int type, int a[], int b[], int w[]) {
	for (int i = 0; i < n-1; i++) {
		adj[a[i]].emplace_back(b[i], w[i]);
		adj[b[i]].emplace_back(a[i], w[i]);
	}
	dfs(0);
	for (auto i: ts) {
		for (int j = 1; j < lg; j++) {
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	if (type == 2) {
		minst[0][0] = inf;
		for (auto i: ts) {
			for (int j = 1; j < lg; j++) {
				minst[i][j] = min(minst[up[i][j-1]][j-1], minst[i][j-1]);
			}
		}
	}
	if (type == 3) {
		for (auto i: ts) {
			sst[i][0] = v[i];
			gst[i][0] = lst[i][0] = rst[i][0] = max(0ll, v[i]);
			for (int j = 1; j < lg; j++) {
				int l = i, r = up[i][j-1];
				sst[i][j] = sst[l][j-1] + sst[r][j-1];
				lst[i][j] = max(lst[l][j-1], sst[l][j-1] + lst[r][j-1]);
				rst[i][j] = max(rst[l][j-1] + sst[r][j-1], rst[r][j-1]);
				gst[i][j] = max(
						max(sst[i][j], rst[l][j-1] + lst[r][j-1]),
						max(gst[l][j-1], gst[r][j-1]));
			}
		}
	}
}

inline int anc(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

inline int lca(int u, int v) {
	if (anc(u, v)) return u;
	if (anc(v, u)) return v;
	for (int j = lg-1; j >= 0; j--) {
		if (not anc(up[u][j], v)) {
			u = up[u][j];
		}
	}
	return up[u][0];
}

inline ll minq(int u, int v) {
	if (u == v) return inf;
	int res = inf;
	for (int j = lg-1; j >= 0; j--) {
		if (not anc(up[u][j], v)) {
			res = min(res, minst[u][j]);
			u = up[u][j];
		}
	}
	return min(res, minst[u][0]);
}

inline void join(array<ll, 4> &a, array<ll, 4> b) {
	ll s = a[0] + b[0];
	ll l = max(a[1], a[0] + b[1]);
	ll r = max(b[0] + a[2], b[2]);
	ll g = max(max(a[3], b[3]), max(a[2] + b[1], a[0] + b[0]));
	a = { s, l, r, max(g, 0ll) };
}

inline array<ll, 4> maxq(int u, int v) {
	if (u == v) return array<ll, 4> { 0, 0, 0, 0 };
	array<ll, 4> res = { 0, 0, 0, 0 };
	for (int j = lg-1; j >= 0; j--) {
		if (not anc(up[u][j], v)) {
			join(res, array<ll, 4> { sst[u][j], lst[u][j], rst[u][j], gst[u][j] });
			u = up[u][j];
		}
	}
	join(res, array<ll, 4> { sst[u][0], lst[u][0], rst[u][0], gst[u][0] });
	return res;
}

long long distanza1(int u, int v) {
	int l = lca(u, v);
	return h[u] + h[v] - 2 * h[l];
}
long long distanza2(int u, int v) {
	int l = lca(u, v);
	return d[u] + d[v] - 2 * d[l];
}
long long minimo(int u, int v) {
	int l = lca(u, v); 
	return min(minq(u, l), minq(v, l));
}
long long massimo(int u, int v) {
	int l = lca(u, v);
	array<ll, 4> res = { 0, 0, 0, 0 };
	array<ll, 4> rres = maxq(v, l);
	swap(rres[1], rres[2]);
	join(res, maxq(u, l));
	join(res, rres);
	return res[3];
}
