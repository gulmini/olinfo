#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
const string quack = "quack";

void debug_out() { cout << "\n"; }

template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
	for (auto e: v) cout << e << " ";
	cout << endl;
	return o;
}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << H;
  debug_out(T...);
}

#ifdef LOcaL
#define dbg(...) cout << "[" << #__Va_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define init(filename) freopen("in", "r", stdin)
#else
#define dbg(...)
#define init()
#endif

ll n, q, a, b, t = 0, res;
vi v, euler, h, tin, d;
vector<vector<pi>> adj;
ll flag[10];

struct node {
	ll i, l, r, s, g;
	node operator+(node &a) {
		return node {
			(h[i] < h[a.i]) ? i : a.i,
			max(l, s + a.l),
			max(r + a.s, a.r),
			max(s, a.s),
			max(max(g, a.g),
					max(s + a.s, r + a.l))
		};
	}
};

vector<node> tree;

void dfs(int i, int p, int height, int dist) {
	h[i] = height;
	d[i] = dist;
	tin[i] = t++;
	euler.push_back(i);
	for (auto [u, w]: adj[i]) {
		if (u != p) dfs(u, i, height+1, dist + w);
	}
}

void inizia(int n, int type, int a[], int b[], int c[]) {
	euler.push_back(n); tin.push_back(n); adj.resize(n);
	h.resize(n); d.resize(n);
	for (int i = 0; i < n; i++) {
		adj[a[i]].push_back(pi{b[i], c[i]});
		adj[b[i]].push_back(pi{a[i], c[i]});
	}
}

ll distanza1(int u, int v) {
	init();
	return 42;
};

ll distanza2(int u, int v) {
	init();
	return 42;
}

ll minimo(int u, int v) {
	init();
	return 42;
}

ll massimo(int u, int v) {
	init();
	return 42;
}
