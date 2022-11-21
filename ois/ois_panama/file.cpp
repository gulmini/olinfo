#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1e14;
const string quack = "quack";

ll n, m, k, q;
vi v;
int type;
ll a, b;

struct segtree {
	struct node {
		ll l, r, s, g;
		node() {}
		node(ll val): l(val), r(val), s(val), g(val) {}
		node(node a, node b) {
			s = a.s + b.s;
			l = max(a.l, a.s + b.l);
			r = max(a.r + b.s, b.r);
			g = max(max(a.g, b.g), a.r + b.l);
		}
		node operator+(node o) {
			return node(*this, o);
		}
	};
	vector<node> tree;
	int n;

	segtree() {}

	void build(vi &v) {
		while (__builtin_popcount(v.size()) != 1)
			v.push_back(-inf);

		n = v.size();
		tree.resize(2*n);

		for (int i = 0; i < n; i++)
			tree[n+i] = node(v[i]);
		for (int i = n-1; i >= 1; i--)
			tree[i] = tree[2*i] + tree[2*i+1];
	}

	void _update(int i, int l, int r, int pos, int val) {
		if (l == r) {
			tree[i] = node(val);
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m) _update(2*i, l, m, pos, val);
		else _update(2*i+1, m+1, r, pos, val);
		tree[i] = tree[2*i] + tree[2*i+1];
	}

	void update(int l, int r) {
		_update(1, 0, n-1, l, r);
	}

	node _query(int i, int l, int r, int a, int b) {
		if (r < a or l > b) return node(-inf);
		if (a <= l and r <= b) return tree[i];
		int m = (l + r) / 2;
		return _query(2*i, l, m, a, b) + _query(2*i+1, m+1, r, a, b);
	}

	ll query(int l, int r) {
		return _query(1, 0, n-1, l, r).g;
	}
};

int main() {
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	segtree t1, t2;

	for (int i = 1; i < n; i += 2) v[i] *= -1;

	t1.build(v);
	for (auto &e: v) e *= -1;
	t2.build(v);

	while (q--) {
		cin >> type >> a >> b;
		a--;
		if (type == 1) {
			if (a % 2) b *= -1;
			t1.update(a, b);
			t2.update(a, -b);
		}
		else if (type == 2) {
			b--;
			cout << max(
				t1.query(a, b),
				t2.query(a, b)
			) << endl;
		}
	}
}
