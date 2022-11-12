#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pi;
typedef bitset<255> vb;
const int inf = INT32_MAX >> 1;
const string quack = "quack";

bool operator<(const vb& a, const vb& b) {
	for (int i = 0; i < 255; i++) {
		if (a[i] != b[i]) return (a[i] < b[i]);
	}
	return true;
}

ll n, maxn, res = inf;
vi v;
vector<vi> adj;
vector<pi> nodes;
clock_t tbegin, tend;

struct Dsu {
	vi p, r;
	int n;
	Dsu(vi& v) {
		n = v.size(); p.resize(n); r.resize(n, 1);
		iota(p.begin(), p.end(), 0);
	}

	int find(int x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}
	
	void join(int x, int y) {
		int a = find(x);
		int b = find(y);
		if (a == b) return;
		if (r[a] > r[b]) swap(a, b);
		p[a] = b;
		if (r[a] == r[b]) r[a]++;
	}
};

void dp(int i, vb v, ll curr_res) {
	if (clock() > tend) return;
	if (curr_res >= res) return;
	if (v.count() == 0) { res = curr_res; return; }
	if (i == n) return;
	
	auto [value, index] = nodes[i];

	vb cpy(v);
	if (cpy[index]) {
		cpy[index] = 0;
		for (auto e: adj[index]) cpy[e] = 0;
		dp(i+1, cpy, curr_res+1);
	}
	dp(i+1, v, curr_res);
}

int main() {
	cin >> n >> maxn; v.resize(n); adj.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i] % v[j] == 0 or v[j] % v[i] == 0) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	Dsu d(v);
	for (int i = 0; i < n; i++) {
		for (int u: adj[i]) {
			d.join(i, u);
		}
	}
	vector<vb> sets(n);
	for (int i = 0; i < n; i++)
		sets[d.find(i)][i] = true;

	nodes.resize(n);
	for (int i = 0; i < n; i++)
		nodes[i] = pi{adj[i].size(), i};
	sort(nodes.begin(), nodes.end(), greater<pi>());
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		tbegin = clock();
		tend = tbegin + CLOCKS_PER_SEC * 0.4;
		dp(0, sets[i], 0);
		ans += res;
		res = inf;
	}

	cout << ans << "\n";
}
