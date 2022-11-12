#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m, k, q, a, b, t = 0;
vi v, ts;
vector<vi> adj, rev_adj;
bitset<100000> vis = 0;

void dfs(int i) {
	vis[i] = 1;
	for (auto u: adj[i]) {
		if (not vis[u]) dfs(u);
	}
	ts.push_back(i);
}

int main() {
	cin >> n;
	v.resize(n);
	adj.resize(n); rev_adj.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int a = 0; a < n; a++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> b;
			rev_adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	for (int i = 0; i < n; i++)
		if (rev_adj[i].empty()) dfs(i);

	for (auto i: ts) {
		ll max_dist = 0;

		for (auto u: adj[i])
			max_dist = max(max_dist, v[u]);

		v[i] += max_dist;
	}

	ll endtime = *max_element(v.begin(), v.end());
	for (int i = 0; i < n; i++) v[i] = endtime - v[i];
	for (auto e: v) cout << e << ' ';
}

