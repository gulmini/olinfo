#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, s, c, cnt = 0;
ll i, j, ns, val;
vi v, res;
vector<vector<pi>> g;
vector<vector<uint8_t>> valid;

int f(int i, int j) {
	if (j >= n or j < 0) return 2;
	if (valid[i][j] != 0) return valid[i][j];
	if (j == 0) return valid[i][j] = 1;
	valid[i][j] = 2;
	auto [ns, val] = g[i][v[j]];
	return valid[i][j] = f(ns, j+val);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s >> c;
	g.resize(s, vector<pi>(max(n, c)));
	valid.resize(s, vector<uint8_t>(max(n, c)));
	v.resize(n);

	for (int k = 0; k < s*c; k++) {
		cin >> i >> j >> ns >> val;
		g[i][j] = { ns, val };
	}
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int j = 0; j < max(c, n); j++) {
		if (f(0, j) == 1) res.push_back(j);
	}
	cout << res.size() << '\n';
	for (auto e: res) cout << e << '\n';
}
