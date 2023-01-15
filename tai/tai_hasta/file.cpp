#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const string quack = "quack";

int n, k;
vi v, w;
vi index_versions;
vector<vi> indexes;

struct node {
	node *l = nullptr, *r = nullptr;
	int val;
	node(): l(nullptr), r(nullptr), val(0) {}
	node(int val): l(nullptr), r(nullptr), val(val) {}
	node(node *l, node *r): l(l), r(r), val(0) {}
	node * apply(int x) { val += x; return this; }
};
vector<node*> roots;

node * build(int l, int r) {
	if (l == r) return new node(nullptr, nullptr);
	int m = (l + r) / 2;
	return new node(build(l, m), build(m+1, r));
}

node * _update(node *p, int l, int r, int a, int b, int delta) {
	if (r < a or l > b) return p;
	if (a <= l and r <= b)
		return (new node(*p))->apply(delta);

	int m = (l + r) / 2;
	return (new node(
		_update(p->l, l, m, a, b, delta),
		_update(p->r, m+1, r, a, b, delta)
	))->apply(p->val);
}

int query(node *p, int l, int r, int pos) {
	if (l == r) return p->val;
	int m = (l + r) / 2;
	return p->val + (pos <= m
		? query(p->l, l, m, pos)
		: query(p->r, m+1, r, pos));
}

void update(int a, int b, int delta) {
	roots.push_back(_update(roots.back(), 0, n-1, a, b, delta));
}

void extend(int i) {
	int e = v[i];
	indexes[e].push_back(i);
	int n = indexes[e].size();
	int q = w[e];

	if (n >= q) update(n == q ? 0 : indexes[e][n-q-1]+1, indexes[e][n-q], +q);
	if (n >= q+1) update(n == q+1 ? 0 : indexes[e][n-q-2]+1, indexes[e][n-q-1], -q);

	index_versions[i] = roots.size()-1;
}

void inizia(int n, int k, int v[], int r[]) {
	::v.assign(v, v+n);
	::w.assign(r, r+k);
	indexes.resize(n);
	index_versions.resize(n);
	roots.reserve(2*n+1);

	while (__builtin_popcount(n) != 1) n++;

	::n = n, ::k = k;

	roots.push_back(build(0, n-1));

	for (int r = 0; r < ::v.size(); r++)
		extend(r);
}

int istiga(int l, int r) {
	return query(roots[index_versions[r]], 0, n-1, l);
}
