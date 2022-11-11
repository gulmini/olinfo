#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
const string quack = "quack";

int n, m, a, b;
vector<set<int>> adj;
vector<pi> fres, sres;
stack<int> q;

inline void remove(int i) {
	for (auto u: adj[i]) {
		adj[u].erase(i);
		if (adj[u].size() == 1) q.push(u);
	}
	adj[i].clear();
}

void solve() {
	vi tmp(2*n);
	iota(tmp.begin(), tmp.end(), 0);
	sort(tmp.begin(), tmp.end(), [](int &a, int &b){ return adj[a].size() > adj[b].size(); });
	for (int e: tmp) q.push(e);

	while (not q.empty()) {
		int i = q.top(); q.pop();
		if (adj[i].empty()) continue;
		if (adj[i].size() == 1) {
			int u = *adj[i].begin();
			if (i > u) swap(i, u);
			sres.push_back({ i, u%n });
			remove(i); remove(u);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	adj.resize(2*n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b; b += n;
		if (i < n) fres.push_back({a, b});
		adj[a].insert(b);
		adj[b].insert(a);
	}

	solve();

	bool unique = true;
	for (int i = 0; i < 2*n; i++) {
		if (adj[i].size()) { unique = false; break; }
	}
	if (unique) { cout << -1 << '\n'; return 0; }

	for (auto [a, b]: fres) {
		if (adj[a].size() and adj[b].size()) {
			adj[a].erase(b); adj[b].erase(a);
			solve();
		}
	}

	for (auto [a, b]: sres) cout << a << ' ' << b << '\n';
}
