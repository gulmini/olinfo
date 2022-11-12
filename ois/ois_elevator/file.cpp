#include <vector>
#include <utility>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
const string quack = "quack";
constexpr int inf = 1000000000;
constexpr int maxn = 200001;

int n, q, a, b, i, x, l0, r0;
vi v;
pi res;

struct segtree {
	struct node {
		int val = 0, i = 0, u = 0;
		inline node(): i(0), val(0), u(0) {}
    inline node(int i): i(i) val(0) u(0) {}
		inline node(int val, int i, int u): val(val), i(i), u(u) {}
		inline void join(node a, node b) {
			if (a.val >= b.val) { val = a.val; i = a.i; }
			else { val = b.val; i = b.i; }
			val += u;
		}
		inline void apply(int x) {
			u += x;
			val += x;
		}
	};
	int n, h;
	vector<node> tree;
	inline segtree(int _n) {
		n = _n; tree.resize(2*n);
		h = sizeof(int) * 8 - __builtin_clz(n);
		for (int i = 0; i < n; i++) tree[n+i].i = i;
		for (int i = n-1; i; i--) tree[i].join(tree[i<<1], tree[i<<1|1]);
	}
	inline void push(int pos) {
		int i;
		for (int s = h; s > 0; s--) {
			i = pos >> s;
			if (tree[i].u) {
				tree[i<<1].apply(tree[i].u);
				tree[i<<1|1].apply(tree[i].u);
				tree[i].u = 0;
			}
		}
	}
	inline void build(int i) {
		for (i >>= 1; i; i >>= 1) {
			tree[i].join(tree[i<<1], tree[i<<1|1]);
		}
	}
	inline void update(int l, int r, int x) {
		l += n; r += n;
		l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l&1) tree[l++].apply(x);
			if (r&1) tree[--r].apply(x);
		}
		build(l0);
		build(r0-1);
	}
	inline void query(int l, int r) {
		l += n; r += n;
		push(l);
		push(r-1);
		for (; l < r; l >>= 1, r >>= 1) {
			if (l&1) {
				if (tree[l].val > res.first) { res.first = tree[l].val; res.second = -tree[l].i; }
				l++;
			}
			if (r&1) {
				r--;
				if (tree[r].val > res.first) { res.first = tree[r].val; res.second = -tree[r].i; }
			}
		}
	}
};

int main() {
  cin >> n;
	v.resize(n);
	segtree t(maxn);

	for (int i = 0; i < n; i++) cin >> v[i];
	t.update(v[0], v[0]+1, 1);
	for (int i = 0; i < n-1; i++) {
		if (v[i] < v[i+1]) t.update(v[i]+1, v[i+1]+1, 1);
		else t.update(v[i+1], v[i], 1);
	}

  cin >> q;
	while (q--) {
    cin >> i >> x;

		if (i == 0) t.update(v[0], v[0]+1, -1);
		else if (v[i-1] < v[i]) t.update(v[i-1]+1, v[i]+1, -1);
		else t.update(v[i], v[i-1], -1);

		if (i == n-1);
		else if (v[i] < v[i+1]) t.update(v[i]+1, v[i+1], -1);
		else t.update(v[i+1]+1, v[i], -1);

		v[i] = x;

		if (i == 0) t.update(v[0], v[0]+1, 1);
		else if (v[i-1] < v[i]) t.update(v[i-1]+1, v[i]+1, 1);
		else t.update(v[i], v[i-1], 1);

		if (i == n-1);
		else if (v[i] < v[i+1]) t.update(v[i]+1, v[i+1], 1);
		else t.update(v[i+1]+1, v[i], 1);
		
		res.first = 0; res.second = -inf;
		t.query(0, maxn);
    cout << -res.second << ' ' << res.first << endl;
	}
	return 0;
}

