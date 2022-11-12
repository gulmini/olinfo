#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;

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

#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define init(filename) freopen("in", "r", stdin)
#else
#define dbg(...)
#define init() freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#endif

ll n, q, ix, a, b;
char type;
constexpr int bs = 450;
vi v;
ll flag[10];
vector<deque<int>> tree;

int main() {
	init();
	cin >> n >> q;
	tree.resize(n/bs+1);
	for (int i = 0; i < n; i++) {
		tree[i/bs].push_back(i);
	}
	while (q--) {
		cin >> type;
		if (type == 'c') {
			cin >> ix;
			cout << tree[ix/bs][ix%bs] << ' ';
		}
		else {
			cin >> ix >> b;
			int e = tree[ix/bs][ix%bs];
			tree[ix/bs].erase(tree[ix/bs].begin() + (ix%bs));
			for (int i = ix/bs; i < b/bs; i++) {
				tree[i].push_back(tree[i+1].front());
				tree[i+1].pop_front();
			}
			for (int i = ix/bs; i > b/bs; i--) {
				tree[i].push_front(tree[i-1].back());
				tree[i-1].pop_back();
			}
			tree[b/bs].insert(tree[b/bs].begin() + (b%bs), e);
		}
	}
}

