#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> ti;
typedef vector<bool> vb;
typedef priority_queue<ti> pq;
const string quack = "quack";

ll n, k, root, t = 0;
vi v, w, ts, p;
ll flag[10];
vector<vi> adj, m;

void dfs(int i) {
	for (auto u: adj[i]) dfs(u);
	ts.push_back(i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	w.resize(n); adj.resize(n); p.resize(n);
	m.resize(n, vi(k+1, 0));
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> w[i];
		if (p[i] == -1) { root = i; p[i] = i; }
		else adj[p[i]].push_back(i);
	}
	dfs(root);
	for (auto i: ts) {
		if (adj[i].empty()) {
			for (int c = 0; c <= k; c++)
				m[i][c] = (c) ? 0 : w[i];
		}
		else {
			pq q;
			for (auto u: adj[i]) {
				q.push(ti{m[u][0], pi{u, 0}});
			}
			m[i][0] = w[i] + q.top().first;
			for (int c = 1; c <= k; c++) {
				auto [val, pp] = q.top(); q.pop();
				auto [u, prevc] = pp;
				ll nval = m[u][prevc+1];
				q.push(ti{nval, pi{u, prevc+1}});
				m[i][c] = w[i] + q.top().first;
			}
			for (int c = k; c > 0; c--) {
				m[i][c] = min(m[i][c], m[i][c-1] - w[i]);
			}
		}
	}
	cout << m[root][k];
}

