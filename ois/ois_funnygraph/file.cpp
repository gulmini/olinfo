#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int maxn = 100001;
const string quack = "quack";

ll n, m, a, b, w;
ll v[maxn], p[maxn], h[maxn];

int find(int x) {
	if (x == p[x]) return x;
	int root = find(p[x]);
	v[x] += v[p[x]];
	return p[x] = root;
}

bool join(int x, int y, int w) {
	int a = find(x);
	int b = find(y);
	if (a == b) return v[x] == v[y] + w;
	if (h[a] > h[b]) swap(a, b), swap(x, y), w *= -1;
	else if (h[a] == h[b]) h[b]++;
	p[a] = b;
	v[a] = w + v[y] - v[x];
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i;
	int i;
	for (i = 0; i < m; i++) {
		cin >> a >> b >> w;
		if (not join(a, b, w)) break;
	}
	cout << i;
}

