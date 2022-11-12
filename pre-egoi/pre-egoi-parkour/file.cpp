#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr int inf = 1000000000;
constexpr int maxn = 1000001;
const string quack = "quack";

int n, sz;
vi tree, memo;

int query(int i, int l, int r, int a, int b) {
	if (b >= n) return 0;
	if (r < a or l > b) return inf;
	if (a <= l and r <= b) return tree[i];
	int m = (l+r)/2;
	return min(query(2*i, l, m, a, b), query(2*i+1, m+1, r, a, b));
}

inline void update(int pos, int x) {
	tree[pos+sz] = x;
	for (int i = (pos+sz)/2; i >= 1; i /= 2) tree[i] = min(tree[2*i], tree[2*i+1]);
}

int salta(int n, vector<int> v, vector<int> a, vector<int> b) {
	::n = n;
	memo.resize(n, inf);
	sz = 1 << int(ceil(log2(n)) + 0.00001);
	tree.resize(2*sz);

	for (int i = n-1; i >= 0; i--) {
		memo[i] = max(v[i], query(1, 0, sz-1, i + a[i], i + b[i]));
		update(i, memo[i]);
	}

	return memo[0];
}

