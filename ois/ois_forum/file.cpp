#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1 << 30;
const string quack = "quack";

ll n, l, q, t, x, timer = 0;
vi p, tin, tout;
vector<pi> st;
vector<vi> adj;

void dfs(int i, int p) {
	tin[i] = timer++;
	for (auto u: adj[i]) {
		if (u != p) dfs(u, i);
	}
	tout[i] = timer;
}

inline void upd(int x, int val) {
	int l = tin[x], r = tout[x];
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) st[l++] = pi(val, timer);
		if (r&1) st[--r] = pi(val, timer);
	}
}

inline int query(int x) {
	pi res = {0, 0};
	for (int i = tin[x]+n; i > 0; i >>= 1) {
		if (st[i].second > res.second) res = st[i];
	}
	return res.first;
}

int main() {
	init();
	cin >> n >> l >> q;
	n += l;
	p.resize(n); adj.resize(n);
	tin.resize(n); tout.resize(n);
	st.resize(2*n);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 1; i < n; i++) {
		adj[p[i]].push_back(i);
		adj[i].push_back(p[i]);
	}
	dfs(0, 0);

	while (q--) {
		timer++;
		cin >> t >> x;
		if (t == 0) upd(x, 0);
		else if (t == 1) upd(x, 1);
		else cout << query(x) << '\n';
	}
}

