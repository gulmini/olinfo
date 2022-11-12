#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef vector<bool> vb;
const string quack = "quack";

void debug_out() { cout << "\n"; }

ll n, m;
vi v;
char c;
vector<vb> g;
vector<vi> adj;
vb vis;

inline int calc(int i, int j) {
	return i*m + i/2 + j;
}

void dfs(int i) {
	vis[i] = true;
	for (auto u: adj[i]) {
		if (not vis[u])
			dfs(u);
	}
}

int main() {
	init();
	cin >> n >> m;
	int sz = n*(2*m+1)+m;
	adj.resize(sz);
	vis.resize(sz);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '/') {
				adj[calc(2*i, j)].push_back(calc(2*i+1, j));
				adj[calc(2*i+1, j)].push_back(calc(2*i, j));

				adj[calc(2*i+1, j+1)].push_back(calc(2*i+2, j));
				adj[calc(2*i+2, j)].push_back(calc(2*i+1, j+1));
			}
			else {
				adj[calc(2*i, j)].push_back(calc(2*i+1, j+1));
				adj[calc(2*i+1, j+1)].push_back(calc(2*i, j));

				adj[calc(2*i+1, j)].push_back(calc(2*i+2, j));
				adj[calc(2*i+2, j)].push_back(calc(2*i+1, j));
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < sz; i++) {
		if (not vis[i]) {
			dfs(i);
			res++;
		}
	}
	cout << res << endl;
}

