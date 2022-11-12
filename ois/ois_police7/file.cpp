#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, q;
vi v;

ll pref(int, ll);

struct node {
	ll a, b, i, sum = 0;
	node (int _i) {
		i = n+_i; a = b = sum = v[_i];
	}
	node () {}
	void join(node x, node y) {
		a = max(x.a, y.a);
		b = y.b;
		sum = y.sum + pref(2*i, y.a);
	}
};

vector<node> tree;

ll pref(int i, ll low) {
	if (tree[i].a <= low) return 0;
	ll res = tree[i].sum;
	if (i >= n) return res;
	res -= tree[2*i+1].sum;
	ll r = pref(2*i+1, low);
	return r ? res + r : pref(2*i, low);
}

void upd(int pos, ll x) {
	int i = n+pos;
	tree[i].a = tree[i].b = tree[i].sum = x;
	for (i >>= 1; i; i >>= 1)
		tree[i].join(tree[2*i], tree[2*i+1]);
}

int main() {
	init();
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (__builtin_popcount(n) != 1) {
		n++;
		v.push_back(0);
	}
	::n = n;
	tree.resize(2*n);
	for (int i = 0; i < n; i++)
		tree[n+i] = node(i);
	for (int i = n-1; i >= 1; i--) {
		tree[i].i = i;
		tree[i].join(tree[2*i], tree[2*i+1]);
	}
	ll x, p;
	while (q--) {
		cin >> p >> x;
		upd(p, x);
		cout << tree[1].sum << endl;
	}
}

