#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, q, t, a, b, res, sum = 1;
vi v, st, en;
vector<array<ll, 20>> up;
vector<vi> adj;

void dfs(ll i, ll p) {
	st[i] = t++;
	up[i][0] = p;
	for (ll j = 1; j < 20; j++)
		up[i][j] = up[up[i][j-1]][j-1];
	for (auto u: adj[i])
		if (u != p) dfs(u, i);
	en[i] = t-1;
}

inline bool is_ancestor(ll u, ll v) {
	return st[u] <= st[v] and en[u] >= en[v];
}

ll lca(ll u, ll v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (ll i = 19; i >= 0; i--) {
		if (not is_ancestor(up[v][i], u))
			v = up[v][i];
	}
	return up[v][0];
}

struct fw {
	ll n;
	vi t;
	fw(ll sz) { n = sz; t.resize(n); }
	void update(ll i, ll val) {
		for (; i < n; i |= i+1)
			t[i] += val;
	}
	void update(ll l, ll r, ll val) {
		update(l, val);
		update(r+1, -val);
	}
	ll query(ll i) {
		ll res = 0;
		for (; i >= 0; i = (i & (i+1)) - 1)
			res += t[i];
		return res;
	}
	ll query(ll l, ll r) {
		return query(r) - query(l-1);
	}
};

int main() {
	cin >> n >> q;
	adj.resize(n); st.resize(n); en.resize(n);
	up.resize(n); v.resize(n);
	fw tree(n);
	for (ll i = 0; i < n-1; i++) {
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	while (q--) {
		cin >> t >> a >> b; a--; b--;
		if (t == 1) {
			if (st[a] < st[b]) swap(a, b);
			v[a] = not v[a];
			tree.update(st[a], en[a], 2*v[a] - 1);
		}
		else {
			a = (a + sum) % n;
			b = (b + sum) % n;
			ll m = lca(a, b);
			res = (
				tree.query(st[a]) == tree.query(st[b]) and
				tree.query(st[a]) == tree.query(st[m])
			);
			sum += res;
			cout << res << '\n';
		}
	}
}
