#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr int maxn = 100001;
const string quack = "quack";
ll n, t = 0;
ll flag[10];

struct node {
	node *left, *right;
	int val;

	node(int x) : left(nullptr), right(nullptr), val(x) {}

	node(node *l, node *r) : left(l), right(r), val(0) {
		if (l) val += l->val;
		if (r) val += r->val;
	}
};

node* build(int l, int r) {
	if (l == r) return new node(0);
	int m = (l+r) / 2;
	return new node(build(l, m), build(m+1, r));
}

int qry(node *i, int l, int r, int a, int b) {
	if (r < a or l > b) return 0;
	if (a <= l and b >= r) return i->val;
	int m = (l+r) / 2;
	return (qry(i->left, l, m, a, b) +
			qry(i->right, m+1, r, a, b));
}

node* upd(node *i, int l, int r, int pos) {
	if (l == r) return new node(flag[1]);
	int m = (l+r) / 2;
	if (pos <= m)
		return new node(upd(i->left, l, m, pos), i->right);
	return new node(i->left, upd(i->right, m+1, r, pos));
}

array<node*, maxn> roots;

void init(int n) {
	::n = n;
	roots[0] = build(0, n-1);
}

void log(vector<int>& added, vector<int>& removed) {
	t++;
	roots[t] = roots[t-1];
	flag[1] = 1;
	for (auto e: added)
		roots[t] = upd(roots[t], 0, n-1, e);
	flag[1] = 0;
	for (auto e: removed)
		roots[t] = upd(roots[t], 0, n-1, e);
}

int answer(int d, int y) {
	return qry(roots[d], 0, n-1, y, n-1);
}
