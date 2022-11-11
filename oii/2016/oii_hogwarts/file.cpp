#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> ti;
constexpr ll inf = 1e10;
constexpr char sp = ' ';
const string quack = "quack"

int raggiungi(int n, int m, int a[], int b[], int startt[], int endt[]) {
	vi d(n, inf);
	vector<vector<ti>> adj(n);
	priority_queue<pi, vector<pi>, greater<pi>> q;
	for (int i = 0; i < m; i++) {
		adj[a[i]].push_back({ b[i], { startt[i], endt[i] }});
		adj[b[i]].push_back({ a[i], { startt[i], endt[i] }});
	}
	d[0] = 0; q.push({0, 0});
	while (not q.empty()) {
		auto [t, a] = q.top(); q.pop();
		for (auto [b, times]: adj[a]) {
			auto [start, end] = times;
			if (t >= end) continue;
			ll new_time = max(start+1, t+1);
			if (new_time < d[b]) {
				d[b] = new_time;
				q.push({ d[b], b });
			}
		}
	}
	return d[n-1] == inf ? -1 : d[n-1];
}

