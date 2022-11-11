#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, x, y;
vector<pi> v;

unordered_map<ll, vi> fy, fx;

inline int low(ll x, ll y) {
	return lower_bound(fx[x].begin(), fx[x].end(), y) - fx[x].begin();
}
inline int up(ll x, ll y) {
	return upper_bound(fx[x].begin(), fx[x].end(), y) - fx[x].begin();
}
vi diff;

struct st {
	int sz;
	vi tree;
	st() {}
	st(vi &v) { build(v); }
	void build(vi &v) {
		sort(v.begin(), v.end());
		diff.clear();
		for (int i = 1; i < v.size(); i++)
			diff.push_back(v[i] - v[i-1]);
		sz = diff.size();
		tree.resize(2*sz);
		for (int i = 0; i < sz; i++)
			tree[sz+i] = diff[i];
		for (int i = sz-1; i >= 0; i--)
			tree[i] = max(tree[i<<1], tree[(i<<1)|1]);
	}
	ll qry(int l, int r) {
		ll res = 0;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l&1) res = max(res, tree[l++]);
			if (r&1) res = max(res, tree[--r]);
		}
		return res;
	}
};

map<ll, st> sty, stx;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.resize(n+1);
	for (int i = 0; i < n+1; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		fx[x].push_back(y);
		fy[y].push_back(x);
	}
	for (auto &[x, v]: fx) stx[x].build(v);
	for (auto &[y, v]: fy) sty[y].build(v);
	bool vertical, inv;
	ll res = 100;
	ll curr = 0;
	for (int i = 1; i < n+1; i++) {
		ll max_dist = 0, beg_dist = 0, end_dist = 0;
		auto [px, py] = v[i-1];
		auto [x, y] = v[i];
		
		bool vertical = x == px;
		if (not vertical)
			swap(x, y), swap(px, py), swap(fx, fy), swap(stx, sty);

		bool inv = py > y;

		if (inv) swap(py, y);
		int l = low(x, py);
		int r = up(x, y);

		if (fx[x].empty() or l == r) {
			beg_dist = y - py;
			end_dist = beg_dist + curr;
		}
		else {
			beg_dist = fx[x][l] - py;
			max_dist = stx[x].qry(l, r-1);
			end_dist = y - fx[x][r-1];
			if (inv) swap(beg_dist, end_dist);
		}
		res = max({ res, curr + beg_dist, max_dist, end_dist });
		curr = end_dist;

		if (not vertical)
			swap(x, y), swap(px, py), swap(fx, fy), swap(stx, sty);
	}
	cout << res-100ll << '\n';
}
