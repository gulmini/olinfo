#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
typedef tuple<int, int, bool> ti;
constexpr ll inf = 1ll << 60;
constexpr int maxn = 100000;
const string quack = "quack";

array<array<ll, maxn>, 2> d;
array<vector<ti>, maxn> adj;
priority_queue<pi, vector<pi>, greater<pi>> q;

ll fuggi(int n, int m, vector<int> a, vector<int> b, vector<int> w, vector<int> red) {
	d[0].fill(inf), d[1].fill(inf);

	for (int i = 0; i < m; i++)
		adj[b[i]].push_back({a[i], w[i], red[i]});

	d[0][n-1] = 0; q.push({0, n-1});

	while (not q.empty()) {
		int a = q.top().second; q.pop();
		if (not a) return d[0][0];

		for (auto &[b, w, red]: adj[a]) {
			if (d[0][a] + w < d[red][b]) {

				d[red][b] = d[0][a] + w;
				if (d[0][b] > d[1][b]) d[0][b]--;

				q.push({d[0][b], b});
			}
		}
	}
}

