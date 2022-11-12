#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";
constexpr ll maxn = 200002;
constexpr ll mod = 1e9 + 7;

ll n, q;
vi v;
array<double, maxn> lg;
vector<pi> tree;

inline ll fast_exp(int b, int n) {
	if (b == 1 or n == 0) return 1;
	ll r = fast_exp(b, n/2);
	r = r * r % mod;
	return (n % 2 == 0) ? r : r * b % mod;
}

inline ll eval(int i, pi u) {
	auto [b, c] = u;
	return b * fast_exp(i, c) % mod;
}

inline bool comp(int i, pi a, pi b) {
	return lg[i+1] * a.second + lg[a.first] <
				 lg[i+1] * b.second + lg[b.first];
}

inline ll query(int x) {
	pi res = {1, 0};
	for (int i = x + n; i >= 1; i >>= 1) {
		if (comp(x, res, tree[i]))
			res = tree[i];
	}
	return eval(x+1, res);
}

inline void add(int i, int l, int r, pi u) {
	int m = (l + r) / 2;
	bool lc = comp(l, tree[i], u);
	bool mc = comp(m, tree[i], u);
	if (mc) swap(tree[i], u);
	if (r == l) return;
	if (lc == mc) add(2*i+1, m+1, r, u);
	else add(2*i, l, m, u);
}

void update(int i, int l, int r, int a, int b, pi u) {
	if (r < a or l > b) return;
	if (a <= l and b >= r) {
		add(i, l, r, u);
		return;
	}
	int m = (l + r) >> 1;
	update(i << 1, l, m, a, b, u);
	update(i << 1 | 1, m+1, r, a, b, u);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (__builtin_popcount(n) != 1) {
		v.push_back(0);
		n++;
	}
	tree.resize(2*n);
	for (int i = 1; i < maxn; i++) lg[i] = log(i);
	for (int i = 0; i < n; i++) tree[n+i] = pi{v[i], 0};
	cin >> q;
	int type, x, y, b, c;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> x; x--;
			cout << query(x) << '\n';
		}
		else {
			cin >> x >> y >> b >> c; x--; y--;
			update(1, 0, n-1, x, y, pi{b, c});
		}
	}
}

