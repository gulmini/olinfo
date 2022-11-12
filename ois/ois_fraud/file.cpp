#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr ll inf = 1e17;
constexpr int maxn = 100000;
const string quack = "quack";

ll n, res = 1;
vi v;

void dp(int l, int r) {
	if (l >= r) return;
	unordered_map<ll, ll> m;

	for (int i = l; i <= r; i++) m[v[i]]++;
	ll minfreq = inf, maxfreq = 1;

	for (auto [_, val]: m) {
		minfreq = min(minfreq, val);
		maxfreq = max(maxfreq, val);
	}
	res = max(res, minfreq * maxfreq);

	int lastl = l;
	for (int i = l; i <= r; i++) {
		if (m[v[i]] != minfreq) continue;
		dp(lastl, i-1);
		lastl = i;
	}
	dp(lastl+1, r);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	v.resize(n);
	for (auto &e: v) cin >> e;
	dp(0, n-1);
	cout << res << endl;
}
