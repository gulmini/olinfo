#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef int_fast64_t ll;
typedef vector<ll> vi;

char c;
ll n, q, a, t = 0, x = 0;
vi l, r, w, p, v;
vector<vi> adj;

struct bit {
	vi tree;
	bit() { tree.resize(n, 0); }
	void upd(int i, int val) {
		for (; i < n; i |= i+1)
			tree[i] += val;
	}
	int qry(int i) {
		int res = 0;
		for (; i >= 0; i = (i & (i+1)) - 1)
			res += tree[i];
		return res;
	}
};

void dfs(int i) {
	l[i] = ++t;
	for (int u: adj[i])
		dfs(u);
	r[i] = t;
}

int main() {
	// freopen("in", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	adj.resize(n); v.resize(n); r.resize(n);
	w.resize(n); p.resize(n); l.resize(n);
	cin >> w[0];
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		cin >> w[i] >> p[i];
		p[i]--;
		adj[p[i]].push_back(i);
	}
	dfs(0);
	bit tree;

	while (q--) {
		cin >> c;
		if (c == 'p') {
			cin >> a >> x; a--;
			tree.upd(l[a], x);
			tree.upd(r[a], -x);
		}
		else {
			cin >> a; a--;
			cout << w[a] + tree.qry(l[a]-1) << '\n';
		}
	}
}
