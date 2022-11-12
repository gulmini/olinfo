#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
const string quack = "quack";

ll n;
int res = 0;
vi v, p;
ll flag[10];
vector<vi> adj;

struct dmap {
	int res = 0, max_app = 0;
	unordered_map<int, int> m;
	void add(int x, int n) {
		m[x] += n;
		if (m[x] == max_app)
			res++;
		if (m[x] > max_app) {
			max_app = m[x];
			res = 1;
		}
	}
	void merge(dmap& o) {
		for (auto [x, n]: o.m)
			add(x, n);
	}
};

void dfs(int i, dmap& d) {
	for (auto u: adj[i]) {
		dbg(i, u);
		dmap subt;
		dfs(u, subt);
		if (d.m.size() < subt.m.size())
			swap(d, subt);
		d.merge(subt);
	}
	d.add(v[i], 1);
	res = max(res, d.res);
}

int main() {
	init();
	cin >> n;
	v.resize(n);
	p.resize(n);
	adj.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	dmap d0;
	dfs(0, d0);
	cout << res;
}

