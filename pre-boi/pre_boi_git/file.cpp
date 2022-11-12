#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr int maxn = 12000000;
constexpr int maxq = 100002;
const string quack = "quack";

ll n, m, k, q, version = 0;
vi v, psa;

inline ll psa_query(int l, int r) {
	if (l) return psa[r] - psa[l-1];
	return psa[r];
}

struct node {
	ll sum = 0, u = 0;
	int n = 1;
	node *l = NULL, *r = NULL;
	node() {}
	inline void apply(ll x) { sum += x*n, u += x; }
};

inline ll sum(node *p) { return p ? p->sum : 0; }
inline ll addval(node *p) { return p ? p->u : 0; }
inline int size(node *p) { return p ? p->n : 0; }

node nodes[maxn];
node *roots[maxq];
node *nodes_ptr = nodes;

inline node * new_node(node *l, node *r, ll sum, ll u, int n) {
	node *p = nodes_ptr++;
	p->l = l, p->r = r;
	p->sum = sum,	p->u = u; p->n = n;
	return p;
}
inline node * new_node() { return nodes_ptr++; }
inline node * new_node(node *x) { return new_node(x->l, x->r, sum(x), addval(x), size(x)); }
inline node * join(node *l, node *r) { return new_node(l, r, sum(l) + sum(r), 0, size(l) + size(r)); }

inline void push(node *&p) {
	if (not addval(p)) return;
	p->l = new_node(p->l);
	p->r = new_node(p->r);
	p->l->apply(p->u);
	p->r->apply(p->u);
	p->u = 0;
}

node * add(node *&last, int l, int r, int &a, int &b, int &x) {
	node *p = new_node(last);
	if (r < a or l > b) return p;
	if (a <= l and b >= r) { p->apply(ll(x)); return p; }
	push(p);
	int m = (l+r)/2;
	p->l = add(p->l, l, m, a, b, x);
	p->r = add(p->r, m+1, r, a, b, x);
	p = join(p->l, p->r);
	return p;
}

node * reset(node *&last, node *&old, int l, int r, int &a, int &b) {
	node *p = new_node(last);
	if (r < a or l > b) return p;
	if (a <= l and b >= r) { return new_node(old); }
	push(p);
	push(old);
	int m = (l+r)/2;
	p->l = reset(p->l, old->l, l, m, a, b);
	p->r = reset(p->r, old->r, m+1, r, a, b);
	p = join(p->l, p->r);
	return p;
}

ll query(node *&p, int l, int r, int &a, int &b) {
	if (r < a or l > b) return 0;
	if (a <= l and b >= r) return p->sum;
	push(p);
	int m = (l+r)/2;
	return query(p->l, l, m, a, b) + query(p->r, m+1, r, a, b);
}

node * build(int l, int r) {
	if (l == r) { return new_node(); }
	int m = (l+r)/2;
	return join(build(l, m), build(m+1, r));
}

void inizia(int n, vector<int> v) {
	while (__builtin_popcount(n) != 1) n++, v.push_back(0);
	::n = n;
	psa.resize(n);
	psa[0] = v[0];
	for (int i = 1; i < n; i++)
		psa[i] = v[i] + psa[i-1];
	roots[0] = build(0, n-1);
}

void incrementa(int l, int r, int x) {
	r--;
	roots[version+1] = add(roots[version], 0, n-1, l, r, x);
	version++;
}

void resetta(int l, int r, int v) {
	r--;
	roots[version+1] = reset(roots[version], roots[v], 0, n-1, l, r);
	version++;
}

ll somma(int l, int r) {
	r--;
	return psa_query(l, r) + query(roots[version], 0, n-1, l, r);
}

