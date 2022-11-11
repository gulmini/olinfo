#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

int n, m, a, b;
vector<set<int>> adj;
vb vis;

void dfs(int i) {
	vis[i] = 1;
	for (auto u: adj[i]) {
		cout << i << ' ' << u << '\n';
		adj[u].erase(i);
		if (not vis[u]) dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	dfs(0);
}

