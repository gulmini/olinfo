#include <bits/stdc++.h>
using namespace std;
typedef int_fast32_t ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll maxc = 101;
constexpr ll maxn = 10001;
constexpr ll INF = INT32_MAX / 2;
const string quack = "quack";

ll n, m, a, b, w, k;
vi v, ts;
vector<vi> memo;
vector<vector<pi>> adj;
bitset<maxn> vis = 0;

void dfs(int i) {
	vis[i] = true;
	for (auto [u, w]: adj[i])
		if (not vis[u]) dfs(u);
	ts.push_back(i);
}

int main() {
	cin >> n >> m >> k;
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	v.resize(n); adj.resize(n);
	memo.resize(n, vi(maxc, INF));

	for (ll i = 0; i < n; i++) cin >> v[i];

	for (ll c = 0; c <= k; c++)
		memo[0][c] = v[0] >> (k-c);

	for (ll i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back(pi{b, w});
	}

	dfs(0);
	reverse(ts.begin(), ts.end());

	for (auto i: ts)
		for (auto [u, w]: adj[i])
			for (ll ac = 0; memo[i][ac] != INF; ac++)
				for (ll bc = ac+w; bc >= 0; bc--)
					memo[u][bc] = min(
						memo[u][bc],
						max(v[u] >> (ac + w - bc), memo[i][ac]));

	cout << memo[n-1][0];
}

