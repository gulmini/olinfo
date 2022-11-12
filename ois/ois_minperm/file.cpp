#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, k;
vi v, l, p;

ll find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int x, int y) {
	if (x >= n or y >= n) return;
	ll a = find(x);
	ll b = find(y);
	if (a < b) swap(a, b);
	p[a] = b;
}

int main() {
	cin >> n >> k;
	v.resize(n); l.resize(k); p.resize(n);
	iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < k; i++) cin >> l[i];
	for (int i = 0; i < n; i++) {
		for (auto e: l) join(i, i+e);
	}
	vector<vi> cc(n);
	for (int i = 0; i < n; i++)
		cc[p[i]].push_back(v[i]);
	for (int i = 0; i < n; i++)
		sort(cc[i].begin(), cc[i].end(), greater<ll>());
	for (int i = 0; i < n; i++) {
		int component = p[i];
		cout << cc[component].back() << ' ';
		cc[component].pop_back();
	}
}
