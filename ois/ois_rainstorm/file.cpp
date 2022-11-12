#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, q, a, b, w;
vi v;
bitset<200000> vis;
vector<vector<pi>> adj;

void dfs(int i) {
	if (vis[i]) return;
	vis[i] = 1;
	for (auto [u, w]: adj[i])
		if (w >= k) dfs(u);
}

bool check(int k) {
	vis = 0;
	dfs(0);
	return vis.count() == n;
}

int main() {
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	k = 0;
	for (int j = 29; j >= 0; j--) {
		k |= 1 << j;
		if (not check(k)) k &= ~(1 << j);
	}
	cout << k << endl;
}

