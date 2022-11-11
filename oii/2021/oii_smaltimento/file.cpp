#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
constexpr ll inf = 1e17;
const string quack = "quack";

ll n, e, l, j, idx, v;
vi d, cnt;

vector<vector<int>> adj;
priority_queue<pi, vector<pi>, greater<pi>> q;

ll smaltisci(int n, int m, vector<int> A, vector<vector<int>> c) {
	adj.resize(n+m);
	cnt.resize(m, 0);
	d.resize(n+m, inf);
	for (int i = n; i < n+m; i++) d[i] = 0;

	for (int j = 0; j < m; j++) {
		if (c[j].empty()) q.emplace(d[A[j]] = 1, A[j]);
		adj[n+j].push_back(A[j]);
		for (auto e: c[j]) adj[e].push_back(n+j);
	}

	while (not q.empty()) {
		auto [w, a] = q.top(); q.pop();
		if (d[a] < w) continue;

		if (a >= n) {
			int b = adj[a][0];
			if (w + 1 < d[b]) {
				d[b] = w + 1;
				q.emplace(d[b], b);
			}
		}
		else {
			for (auto b: adj[a]) {
				d[b] += w;
				cnt[b-n]++;
				if (cnt[b-n] == c[b-n].size())
					q.emplace(d[b], b);
			}
		}
	}
	return d[0];
}

