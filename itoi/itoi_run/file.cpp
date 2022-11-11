#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n;
vi v, sr, tree;

inline ll combine(ll i, ll j) {
	if (i == -1) return j;
	if (j == -1) return i;
	return v[i] > v[j] ? i : j;
}

ll query(int i, int l, int r, int a, int b) {
	if (r < a or l > b) return -1;
	if (a <= l and b >= r) return tree[i];
	int m = (l + r) / 2;
	return combine(
		query(2*i, l, m, a, b),
		query(2*i+1, m+1, r, a, b)
	);
}

int main() {
	init();
	cin >> n;
	v.resize(n); sr.resize(n, n);
	for (int i = 0; i < n; i++) cin >> v[i];

	stack<ll> s;
	for (int i = 0; i < n; i++) {
		while (not s.empty() and v[s.top()] > v[i]) {
			sr[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	int sz = 1;
	for (; sz < n; sz <<= 1);
	tree.resize(2*sz, -1);
	for (int i = 0; i < n; i++)
		tree[sz+i] = i;
	for (int i = sz-1; i >= 1; i--)
		tree[i] = combine(tree[2*i], tree[2*i+1]);
	
	ll res = -1;
	for (int i = n-1; i >= 0; i--) {
		int r = sr[i] - 1;
		ll newres = query(1, 0, sz-1, i, r) - i + 1;
		res = max(res, newres);
	}
	cout << res;
}

