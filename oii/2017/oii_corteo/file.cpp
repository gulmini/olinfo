#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
constexpr int inf = 1 << 30;
const string quack = "quack";

int n, k, sa, ea, sb, eb;
vector<vi> adj, dist;
vector<bitset<1000>> vis;

template <typename T, int maxn = 1000000>
struct static_queue {
	T q[maxn];
	int f = 0, b = 0;
	bool empty() { return f == b; }
	void reset() { f = b = 0; }
	T front() { return q[b]; }
	void push(T x) { q[f] = x, f++, f %= maxn; }
	void pop() { b++, b %= maxn; }
};

static_queue<pi> q;
static_queue<int> dq;

void bfs(int root) {
	dist[root][root] = 0;
	dq.push(root);
	while (not dq.empty()) {
		auto a = dq.front(); dq.pop();
		for (auto b: adj[a]) {
			if (dist[root][a] + 1 < dist[root][b]) {
				dist[root][b] = dist[root][a] + 1;
				dq.push(b);
			}
		}
	}
}

bool check(int k) {
	if (dist[sa][sb] < k or dist[ea][eb] < k) return false;

	q.push({sa, sb});
	vis[sa][sb] = 1;

	while (not q.empty()) {
		auto [a, b] = q.front(); q.pop();

		if (a == ea and b == eb) return true;

		for (auto u: adj[a]) {
			if (not vis[u][b] and dist[u][b] >= k) {
				q.push({u, b});
				vis[u][b] = 1;
			}
		}
		for (auto u: adj[b]) {
			if (not vis[a][u] and dist[a][u] >= k) {
				q.push({a, u});
				vis[a][u] = 1;
			}
		}
	}

	return false;
}

inline void reset() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	q.reset();
}

int pianifica(int n, int m, int sa, int ea, int sb, int eb, int a[], int b[]) {
	::n = n, ::sa = sa, ::sb = sb, ::ea = ea, ::eb = eb;
	adj.resize(n); vis.resize(n);
	dist.resize(n, vi(n, inf));

	for (int i = 0; i < m; i++) {
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	for (int i = 0; i < n; i++) bfs(i);

	k = 0;
	for (int j = 11; j >= 0; j--) {
		reset();
		k |= 1 << j;
		if (not check(k))
			k &= ~(1 << j);
	}

	return k;
}

